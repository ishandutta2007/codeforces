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
VI typ;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,p;
  cin>>n>>p;
  string c;
  forn(i,n){
    cin>>c;
    typ.PB(sz(c)!=4);
  }
  reverse(all(typ));
  in cct=0;
  in sm=0;
  forv(i,typ){
    sm+=cct*p;
    cct*=2;
    if(typ[i]){
      sm+=p/2;
      ++cct;
    }
  }
  cout<<sm<<endl;
  return 0;
}