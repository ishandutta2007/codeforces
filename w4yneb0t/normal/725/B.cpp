#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<cassert>
#include<sstream>
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
  string s;
  cin>>s;
  char st=s.back();
  s.pop_back();
  istringstream is(s);
  in n;
  is>>n;
  in sm=0;
  --n;
  sm+=(n/4)*16;
  n%=4;
  if(n%2)
    sm+=7;
  string ord="fedabc";
  forv(i,ord)
    if(ord[i]==st)
      sm+=i+1;
  cout<<sm<<endl;
  return 0;
}