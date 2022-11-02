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
VI p,v;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  p=v=VI(n);
  forn(i,n){
    cin>>p[i];
    --p[i];
  }
  in sm=1;
  in b;
  forn(i,n){
    cin>>b;
    sm+=b;
  }
  sm%=2;
  in cyc=0;
  forn(i,n){
    if(v[i])
      continue;
    in u=i;
    while(!v[u]){
      v[u]=1;
      u=p[u];
    }
    ++cyc;
  }
  if(cyc>1)
    sm+=cyc;
  cout<<sm<<endl;
  return 0;
}