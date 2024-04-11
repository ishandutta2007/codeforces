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
  in n;
  cin>>n;
  in a;
  in sm=0;
  forn(z,n){
    cin>>a;
    sm+=a;
  }
  const in inf=1e18;
  in bst=inf;
  in m;
  in l,r;
  cin>>m;
  forn(z,m){
    cin>>l>>r;
    if(r>=sm)
      bst=min(bst,max(sm,l));
  }
  if(bst==inf)
    bst=-1;
  cout<<bst<<endl;
  return 0;
}