#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(auto i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
in n;
vector<in> pr,ht;
struct eg{
  int a, b;
  in d;
  eg(in pa, in pb, in pc){a=pa;b=pb;d=pc;}
  bool operator<(const eg cp)const{
    return d<cp.d;
  }
};
vector<eg> segs;
in fnd(in a){
  in ta=a;
  while(a!=pr[a])
    a=pr[a];
  in tt=ta;
  while(ta!=a){
    tt=ta;
    ta=pr[ta];
    pr[tt]=a;
  }
  return a;
}
void uni(in a, in b){
  a=fnd(a);
  b=fnd(b);
  assert(a!=b);
  if(ht[a]>ht[b]){
    uni(b,a);
    return;
  }
  pr[a]=b;
  if(ht[a]==ht[b])
    ht[b]++;
}
vector<vector<in> > dt;
vector<vector<in> > egs,di;
bool ck(in u, in p, in st, in cd=0){
  if(cd!=dt[st][u])
    return 0;
  forv(i,egs[u]){
    if(egs[u][i]==p)
      continue;
    if(!ck(egs[u][i],u,st,cd+di[u][i]))
      return 0;
  }
  return 1;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  egs.resize(n);
  di.resize(n);
  dt.resize(n,vector<in>(n));
  forn(i,n)
    forn(j,n)
    cin>>dt[i][j];
  forn(i,n){
    if(dt[i][i]!=0){
      cout<<"NO"<<endl;
      return 0;
    }
    forn(j,i){
      if(dt[i][j]==0){
	cout<<"NO"<<endl;
	return 0;
      }
      if(dt[i][j]!=dt[j][i]){
	cout<<"NO"<<endl;
	return 0;
      }
      segs.PB(eg(i,j,dt[i][j]));
    }
  }
  sort(all(segs));
  pr.resize(n);
  forn(i,n)
    pr[i]=i;
  ht.resize(n,0);
  forv(i,segs){
    if(fnd(segs[i].a)==fnd(segs[i].b))
      continue;
    egs[segs[i].a].PB(segs[i].b);
    egs[segs[i].b].PB(segs[i].a);
    di[segs[i].a].PB(segs[i].d);
    di[segs[i].b].PB(segs[i].d);
    uni(segs[i].a,segs[i].b);
  }
  forn(i,n){
    if(!ck(i,-1,i)){
      cout<<"NO"<<endl;
      return 0;
    }
  }
  cout<<"YES"<<endl;
  return 0;
}