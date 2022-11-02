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
in n;
VI gd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  forn(i,n){
    bool g=1;
    in t;
    forn(j,n){
      cin>>t;
      if(t==1 || t==3)
	g=0;
    }
    if(g)
      gd.PB(i+1);
  }
  cout<<sz(gd)<<endl;
  forv(i,gd)
    cout<<gd[i]<<" ";
  cout<<endl;
  return 0;
}