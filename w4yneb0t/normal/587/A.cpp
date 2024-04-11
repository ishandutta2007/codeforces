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
const in mx=1001000;
in nb[mx];
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in t;
  forn(z,n){
    cin>>t;
    ++nb[t];
  }
  in sm=0;
  forn(z,mx-1){
    if(nb[z]%2)
      ++sm;
    nb[z+1]+=nb[z]/2;
  }
  cout<<sm<<endl;
  return 0;
}