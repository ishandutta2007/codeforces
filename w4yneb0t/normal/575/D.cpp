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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in x=1000;
  cout<<2*x-1<<endl;
  forn(i,x)
    cout<<i+1<<" "<<1<<" "<<i+1<<" "<<2<<endl;
  for(in i=1;i<x;++i)
    cout<<i+1<<" "<<1<<" "<<i+1<<" "<<2<<endl;
  return 0;
}