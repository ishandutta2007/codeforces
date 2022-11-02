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
in sm=0;
VI od;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in a;
  forn(z,n){
    cin>>a;
    if(a%2==0)
      sm+=max(a,0LL);
    else
      od.PB(a);
  }
  sort(all(od));
  reverse(all(od));
  const in inf=1e18;
  in bst=-inf;
  in cs=0;
  forv(i,od){
    cs+=od[i];
    if(i%2==0)
      bst=max(bst,cs);
  }
  cout<<bst+sm<<endl;
  return 0;
}