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
set<string> ss;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  in n=sz(s);
  forn(i,n+1){
    for(char a='a';a<='z';++a)
      ss.insert(s.substr(0,i)+a+s.substr(i,n-i));
  }
  cout<<sz(ss)<<endl;
  return 0;
}