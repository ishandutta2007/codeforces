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
vector<string> v;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,m;
  cin>>n>>m;
  v.resize(n);
  forn(i,n)
    cin>>v[i];
  in rmd=0;
  while(1){
    bool gn=0;
    forn(i,n-1){
      forn(j,m){
	if(v[i][j]<v[i+1][j])
	  break;
	if(v[i][j]>v[i+1][j]){
	  ++rmd;
	  gn=1;
	  forn(k,n)
	    v[k][j]='a';
	  break;
	}
      }
    }
    if(!gn)break;
  }
  cout<<rmd<<endl;
  return 0;
}