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
in n,m,b;
in mdl;
VVI wys;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>m>>b>>mdl;
  wys.resize(m+1,VI(b+1,0));
  wys[0][0]=1;
  in a;
  forn(i,n){
    cin>>a;
    forn(j,m){
      forn(k,b+1-a){
	wys[j+1][k+a]+=wys[j][k];
	wys[j+1][k+a]%=mdl;
      }
    }
  }
  in sm=0;
  forn(k,b+1)
    sm+=wys[m][k];
  cout<<sm%mdl<<endl;
  return 0;
}