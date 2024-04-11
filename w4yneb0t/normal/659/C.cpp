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
VI hv;
VI sol;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  in tp;
  forn(i,n){
    cin>>tp;
    hv.PB(tp);
  }
  sort(all(hv));
  in nxt=1;
  in nxid=0;
  while(nxt<=m){
    while(nxid<sz(hv) && hv[nxid]<nxt)
      ++nxid;
    if(nxid<sz(hv) && hv[nxid]==nxt){
      ++nxt;
      continue;
    }
    sol.PB(nxt);
    m-=nxt;
    ++nxt;
  }
  cout<<sz(sol)<<"\n";
  forv(i,sol)
    cout<<sol[i]<<" ";
  cout<<"\n";
  return 0;
}