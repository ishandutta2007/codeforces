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
  in sm=0;
  string s;
  in n;
  cin>>n;
  cin>>s;
  forn(r,n){
    forn(l,r+1){
      in lr=0;
      in ud=0;
      for(in i=l;i<=r;++i){
	if(s[i]=='R')
	  ++lr;
	if(s[i]=='L')
	  --lr;
	if(s[i]=='U')
	  ++ud;
	if(s[i]=='D')
	  --ud;
      }
      sm+=(lr==0 && ud==0);
    }
  }
  cout<<sm<<endl;
  return 0;
}