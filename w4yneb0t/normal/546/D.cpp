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
vector<int> ppr;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ppr.resize(5000009,0);
  for(in i=2;i<sz(ppr);++i){
    if(ppr[i]==0){
      for(in pw=i;pw<sz(ppr);pw*=i){
	for(in j=pw;j<sz(ppr);j+=pw)
	  ++ppr[j];
      }
    }
    ppr[i]+=ppr[i-1];
  }
  in t;
  cin>>t;
  in a,b;
  forn(z,t){
    cin>>a>>b;
    cout<<ppr[a]-ppr[b]<<"\n";
  }
  return 0;
}