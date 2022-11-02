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
vector<string> cts;
in n;
VI gl;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  cts.resize(n);
  gl=VI(n);
  forn(i,n)
    cin>>cts[i];
  forn(i,n)
    cin>>gl[i];
  VI sol;
  forn(z,n+3){
    forn(i,n){
      if(gl[i]==0){
	sol.PB(i+1);
	forn(j,n)
	  gl[j]-=(cts[i][j]-'0');
	assert(gl[i]==-1);
      }
    }
  }
  cout<<sz(sol)<<endl;
  forv(i,sol)
    cout<<sol[i]<<" ";
  cout<<endl;
  return 0;
}