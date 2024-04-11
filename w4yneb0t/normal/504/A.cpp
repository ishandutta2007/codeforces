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
VI dg,sm;
queue<in> q;
VI egx,egy;
VI inq;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  dg.resize(n);
  sm.resize(n);
  inq.resize(n);
  forn(i,n){
    cin>>dg[i]>>sm[i];
    if(dg[i]<=1){
      inq[i]=1;
      q.push(i);
    }
  }
  in u;
  while(!q.empty()){
    u=q.front();
    q.pop();
    if(dg[u]==0)
      continue;
    sm[sm[u]]^=u;
    dg[sm[u]]--;
    egx.PB(u);
    egy.PB(sm[u]);
    if(dg[sm[u]]<=1 && !inq[sm[u]]){
      inq[sm[u]]=1;
      q.push(sm[u]);
    }
  }
  cout<<sz(egx)<<"\n";
  forv(i,egx){
    cout<<egx[i]<<" "<<egy[i]<<"\n";
  }
  return 0;
}