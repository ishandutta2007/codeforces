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
VVI tr;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,t;
  cin>>n>>t;
  tr.resize(t+3);
  in tq,tt;
  forn(z,n){
    cin>>tt>>tq;
    tr[t-tt].PB(tq);
  }
  for(in i=sz(tr)-1;i>0;--i){
    if(sz(tr[i])%2)
      tr[i].PB(0);
    sort(all(tr[i]));
    forn(j,sz(tr[i])/2)
      tr[i-1].PB(tr[i][2*j]+tr[i][2*j+1]);
  }
  sort(all(tr[0]));
  cout<<tr[0].back()<<endl;
  return 0;
}