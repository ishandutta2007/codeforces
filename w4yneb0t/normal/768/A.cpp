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
  map<in,in> t;
  in a;
  forn(z,n){
    cin>>a;
    ++t[a];
  }
  in sm=0;
  in ct=0;
  in lst=0;
  fors(it,t){
    if(ct){
      sm+=it->second;
      lst=it->second;
    }
    ++ct;
  }
  sm-=lst;
  cout<<sm<<endl;
  return 0;
}