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
VI a;
in sm;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  a.resize(n);
  forn(i,n){
    cin>>a[i];
    sm+=a[i];
  }
  VI k;
  forn(i,n){
    if(a[i]*(n-1)==(sm-a[i]))
      k.PB(i+1);
  }
  cout<<sz(k)<<endl;
  forv(i,k)
    cout<<k[i]<<" ";
  cout<<endl;
  return 0;
}