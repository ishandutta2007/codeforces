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
string repat(string s){
  string r;
  forv(i,s){
    if(s[i]=='@')
      r+="at";
    else
      r+=s[i];
  }
  return r;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  string s;
  cin>>s;
  vector<string> vars;
  string c;
  for(in i=0;i<sz(s);++i){
    if(i!=0 && i+1<sz(s)-1 && s.substr(i,2)=="at"){
      c.PB('@');
      ++i;
      continue;
    }
    if(i!=0 && i+2<sz(s)-1 && s.substr(i,3)=="dot"){
      c.PB('.');
      i+=2;
      continue;
    }
    c.PB(s[i]);
  }
  forv(i,c){
    if(c[i]=='@'){
      vars.PB(repat(c.substr(0,i))+c[i]+repat(c.substr(i+1)));
    }
  }
  sort(all(vars));
  cout<<vars[0]<<endl;
  return 0;
}