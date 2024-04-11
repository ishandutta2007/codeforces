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
  string s,t;
  cin>>s>>t;
  VI ct(300);
  forv(i,t)
    ++ct[t[i]];
  char nxt='9';
  forv(i,s){
    while(nxt>='0' && ct[nxt]==0)
      --nxt;
    if(nxt>='0' && nxt>s[i]){
      s[i]=nxt;
      --ct[nxt];
    }
  }
  cout<<s<<endl;
  return 0;
}