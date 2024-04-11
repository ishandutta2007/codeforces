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
typedef int in;
typedef vector<in> VI;
typedef vector<VI> VVI;
in n;
VI mar;
in bst;
VI res;
VI sf;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  mar.resize(n);
  res.resize(n);
  forn(i,n){
    cin>>mar[i];
    --mar[i];
  }
  sf.resize(n);
  in c;
  forn(l,n){
    forn(i,n)
      sf[i]=0;
    bst=0;
    for(in r=l;r<n;++r){
      c=mar[r];
      ++sf[c];
      if(sf[c]>sf[bst] || (sf[c]==sf[bst] && c<bst))
	bst=c;
      ++res[bst];
    }
  }
  forn(i,n)
    cout<<res[i]<<" ";
  cout<<"\n";
  return 0;
}