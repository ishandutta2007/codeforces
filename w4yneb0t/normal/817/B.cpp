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
in ncr(in a, in b){
  in r=1;
  forn(i,b)
    r*=a-i;
  forn(i,b)
    r/=i+1;
  return r;
}
map<in,in> ct;
VI a;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  a.resize(n);
  forn(i,n){
    cin>>a[i];
    ++ct[a[i]];
  }
  sort(all(a));
  map<in,in> gct;
  forn(i,3)
    ++gct[a[i]];
  in pd=1;
  fors(i,gct)
    pd*=ncr(ct[i->first],i->second);
  cout<<pd<<endl;
  return 0;
}