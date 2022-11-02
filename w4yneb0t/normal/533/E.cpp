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
bool isk(string m, string s){
  in im=0;
  forv(i,s){
    while(im<sz(m) && m[im]!=s[i])
      ++im;
    ++im;
  }
  return im<=sz(m);
}
set<string> cds;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  string s,t;
  cin>>s>>t;
  forv(i,s){
    if(s[i]!=t[i]){
      cds.insert(s.substr(0,i)+string(1,t[i])+s.substr(i,n-i));
      cds.insert(t.substr(0,i)+string(1,s[i])+t.substr(i,n-i));
      break;
    }
  }
  in sm=0;
  fors(i,cds){
    sm+=(isk(*i,s)&&isk(*i,t));
  }
  cout<<sm<<endl;
  return 0;
}