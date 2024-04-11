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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef int in;
in n,m,q;
vector<in> ht,pr,mt;
in mx(in a, in b){
  return a>b?a:b;
}
in find(in a){
  in ta=a;
  in tt=a;
  while(pr[ta]!=ta)
    ta=pr[ta];
  while(a!=ta){
    tt=pr[a];
    pr[a]=ta;
    a=tt;
  }
  return ta;
}
void uni(in a, in b){
  a=find(a);
  b=find(b);
  if(a==b)
    return;
  if(ht[a]<ht[b]){
    uni(b,a);
    return;
  }
  pr[b]=a;
  if(ht[b]==ht[a])
    ht[a]++;
  mt[a]=mx(mx(mt[a],mt[b]),(mt[a]+1)/2+(mt[b]+1)/2+1);
}
vector<vector<in> > egs;
vector<int> rcd;
pair<in,in> dfs(in u, in p){
  rcd[u]=1;
  in v;
  in bl=0;
  in bp=0;
  pair<in,in> tp;
  forv(i,egs[u]){
    v=egs[u][i];
    if(v==p)
      continue;
    tp=dfs(v,u);
    if(tp.first>bl)
      bl=tp.first;
    if(tp.second+bp>bl)
      bl=tp.second+bp;
    if(tp.second>bp)
      bp=tp.second;
  }
  return MP(bl,bp+1);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>m>>q;
  ht.resize(n);
  pr.resize(n);
  mt.resize(n);
  forn(i,n)
    pr[i]=i;
  in ta,tb;
  egs.resize(n);
  rcd.resize(n);
  forn(i,m){
    cin>>ta>>tb;
    ta--;
    tb--;
    uni(ta,tb);
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  forn(i,n)
    mt[i]=0;
  forn(i,n){
    if(!rcd[i])
      mt[find(i)]=dfs(i,-1).first;
  }
  in typ;
  forn(i,q){
    cin>>typ;
    if(typ==2){
      cin>>ta>>tb;
      ta--;
      tb--;
      uni(ta,tb);
    }
    else{
      cin>>ta;
      ta--;
      cout<<mt[find(ta)]<<"\n";
    }
  }
  return 0;
}