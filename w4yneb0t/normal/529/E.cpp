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
VI mar;
in n,k;
map<in,in> br;
in wy(in tp){
  in bst=k+1;
  br.clear();
  forn(i,n){
    forn(j,k+1){
      if(j*mar[i]>tp)
	continue;
      if(br.find(tp-j*mar[i])==br.end())
	br[tp-j*mar[i]]=j;
      else
	br[tp-j*mar[i]]=min(br[tp-j*mar[i]],j);
    }
  }
  forn(i,n){
    forn(j,k+1){
      if(j*mar[i]>tp)
	continue;
      if(br.find(j*mar[i])==br.end())
	continue;
      bst=min(bst,j+br[j*mar[i]]);
    }
  }
  if(bst==k+1)
    return -1;
  return bst;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>k;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  in q;
  cin>>q;
  in tp;
  forn(z,q){
    cin>>tp;
    cout<<wy(tp)<<"\n";
  }
  return 0;
}