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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  a.resize(n);
  forn(i,n)
    cin>>a[i];
  for(in i=1;i<n;++i){
    if(a[i]%k!=a[0]%k){
      cout<<-1<<endl;
      return 0;
    }
  }
  in mn=1e18;
  forn(i,n)
    mn=min(mn,a[i]);
  in sm=0;
  forn(i,n)
    sm+=(a[i]-mn)/k;
  cout<<sm<<endl;
  return 0;
}