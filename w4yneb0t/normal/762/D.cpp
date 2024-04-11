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
VI kup(VI bst, VI mar){
  VI nu(5,-1e15);
  in ts=mar[0]+mar[1]+mar[2];
  bst[0]=max(bst[0],bst[3]);
  bst[2]=max(bst[2],bst[4]);
  forn(i,3){
    forn(j,3){
      in sm=0;
      forn(k,3){
	if((k>=i && k<=j)||(k>=j && k<=i))
	  sm+=mar[k];
      }
      nu[j]=max(nu[j],bst[i]+sm);
    }
  }
  nu[3]=max(bst[2],bst[3])+ts;
  nu[4]=max(bst[0],bst[4])+ts;
  return nu;
}
VVI mar;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  mar.resize(n,VI(3));
  forn(j,3){
    forn(i,n){
      cin>>mar[i][j];
    }
  }
  VI bst(5,-1e15);
  bst[0]=0;
  forn(i,n){
    bst=kup(bst,mar[i]);
  }
  cout<<max(bst[2],bst[4])<<endl;
  return 0;
}