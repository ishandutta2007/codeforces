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
const in mdl=1000000007LL;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in a,b;
  cin>>a>>b;
  in sm=0;
  forn(rm,b){
    sm+=rm*a;
    sm+=b*rm%mdl*(a*(a+1)/2%mdl);
    sm%=mdl;
  }
  cout<<sm<<endl;
  return 0;
}