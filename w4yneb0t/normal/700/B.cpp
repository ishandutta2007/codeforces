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
typedef vector<in> VI;
typedef vector<VI> VVI;
VI hh;
in k;
in sm;
VVI egs;
in dfs(in u, in pr){
  in sd=0;
  in tp;
  forv(i,egs[u]){
    if(egs[u][i]==pr)
      continue;
    tp=dfs(egs[u][i],u);
    sd+=tp;
    sm+=min(tp,2*k-tp);
  }
  sd+=hh[u];
  return sd;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  sm=0;
  in n;
  cin>>n>>k;
  egs.resize(n);
  hh.resize(n);
  in ta,tb;
  forn(i,2*k){
    cin>>ta;
    ++hh[ta-1];
  }
  forn(i,n-1){
    cin>>ta>>tb;
    --ta;
    --tb;
    egs[ta].PB(tb);
    egs[tb].PB(ta);
  }
  assert(dfs(0,-1)==2*k);
  cout<<sm<<endl;
  return 0;
}