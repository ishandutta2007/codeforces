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
in n,k;
VI ct[2];
const in mdl=1000000007LL;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>n>>k;
  forn(i,2)
    ct[i].resize(n+1,0);
  ct[0][1]=1;
  in sw,nw;
  in sm=0;
  forn(z,k){
    sw=z%2;
    nw=!sw;
    forn(i,n+1){
      ct[nw][i]=0;
      ct[sw][i]%=mdl;
    }
    for(in i=1;i<=n;i++){
      for(in j=i;j<=n;j+=i)
	ct[nw][j]+=ct[sw][i];
    }
    if(z==k-1){
      forn(i,n+1)
	sm+=ct[nw][i];
    }
  }
  cout<<sm%mdl<<"\n";
  return 0;
}