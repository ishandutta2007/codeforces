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
VI th,tr;
VI lc,rd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,q;
  cin>>n>>q;
  in sm=0;
  th.resize(n,0);
  tr.resize(n,0);
  in typ,x;
  in nxt=0;
  forn(z,q){
    cin>>typ>>x;
    --x;
    if(typ==1){
      ++th[x];
      ++sm;
      lc.PB(x);
      rd.PB(th[x]);
      cout<<sm<<"\n";
      continue;
    }
    if(typ==2){
      sm-=(th[x]-tr[x]);
      tr[x]=th[x];
      cout<<sm<<"\n";
      continue;
    }
    while(nxt<=x){
      if(tr[lc[nxt]]<=rd[nxt]){
	sm-=(rd[nxt]-tr[lc[nxt]]);
	tr[lc[nxt]]=rd[nxt];
      }
      ++nxt;
    }
    cout<<sm<<"\n";
  }
  return 0;
}