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
in n,k;
vector<in> f;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>k;
  f.resize(n);
  forn(i,n){
    cin>>f[i];
    f[i]--;
  }
  sort(all(f));
  reverse(all(f));
  in t=0;
  for(in i=0;i<n;i+=k){
    t+=2*f[i];
  }
  cout<<t<<endl;
  return 0;
}