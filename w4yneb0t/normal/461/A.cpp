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
typedef long long in;
in n;
vector<in> a;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  sort(all(a));
  reverse(all(a));
  for(in i=1;i<sz(a);i++)
    a[i]+=a[i-1];
  in sm=0;
  forn(i,n)
    sm+=a[i];
  sm+=a[n-1]-a[0];
  cout<<sm<<endl;
  return 0;
}