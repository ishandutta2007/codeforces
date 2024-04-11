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
#define fors(i,s) for(typeof((s).begin())::iterator i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  in n,a;
  cin>>n;
  in sm=0;
  in rt=0;
  forn(i,n){
    cin>>a;
    if(a)
      rt++;
    else
      sm+=rt;
  }
  cout<<sm<<endl;
  return 0;
}