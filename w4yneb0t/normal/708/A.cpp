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
  string s;
  bool na=0;
  cin>>s;
  forv(i,s)
    if(s[i]!='a')
      na=1;
  if(!na){
    cout<<string(sz(s)-1,'a')<<"z\n";
    return 0;
  }
  forv(i,s){
    if(s[i]!='a'){
      for(in j=i+1;j<=sz(s);++j){
	if(j==sz(s) || s[j]=='a'){
	  forv(k,s){
	    if(k<i || k>=j)
	      cout<<s[k];
	    else
	      cout<<char(s[k]-1);
	  }
	  cout<<"\n";
	  return 0;
	}
      }
    }
  }
  return 0;
}