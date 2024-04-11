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
vector<vector<in> > cst,sid;
vector<in> trord;
bool fail=0;
in dfs(in u, in ntp){
  assert(u<=ntp);
  assert(ntp<=n);
  in llf=1000000000;
  in hlf=-1;
  in lrt=llf;
  in hrt=hlf;
  assert(sz(cst[u])==sz(sid[u]));
  forv(i,cst[u]){
    if(sid[u][i]==0){
      if(cst[u][i]<llf)
	llf=cst[u][i];
      if(cst[u][i]>hlf)
	hlf=cst[u][i];
    }
    else{
      if(cst[u][i]<lrt)
	lrt=cst[u][i];
      if(cst[u][i]>hrt)
	hrt=cst[u][i];
    }
  }
  if(llf<=u || lrt<=u || hlf>=lrt){
    fail=1;
    return n+10;
  }
  in nxt=u+1;
  if(hlf!=-1){
    if(hlf<nxt)
      hlf=nxt;
    nxt=dfs(nxt,hlf)+1;
    if(fail)return n+10;
  }
  trord.PB(u);
  if(hrt!=-1 || nxt-1<ntp){
    if(lrt<nxt){
      fail=1;
      return n+10;
    }
    if(hrt<nxt)
      hrt=nxt;
    if(hrt<ntp)
      hrt=ntp;
    nxt=dfs(nxt,hrt)+1;
    if(fail)return n+10;
  }
  return nxt-1;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  in c;
  cin>>c;
  cst.resize(n+1);
  sid=cst;
  in ta,tb;
  string w;
  forn(i,c){
    cin>>ta>>tb>>w;
    cst[ta].PB(tb);
    if(w=="LEFT")
      sid[ta].PB(0);
    else{
      assert(w=="RIGHT");
      sid[ta].PB(1);
    }
  }
  if(dfs(1,n)!=n){
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  if(fail){
    cout<<"IMPOSSIBLE\n";
    return 0;
  }
  assert(sz(trord)==n);
  forv(i,trord)
    cout<<trord[i]<<(i==sz(trord)-1?"":" ");
  cout<<"\n";
  return 0;
}