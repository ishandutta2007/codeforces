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
const in mx=4009;
const in mdl=1000000007LL;
VVI ncr;
VI wys;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ncr.resize(mx,VI(mx,0));
  forn(i,mx){
    ncr[i][i]=ncr[i][0]=1;
    for(in j=1;j<i;j++)
      ncr[i][j]=(ncr[i-1][j]+ncr[i-1][j-1])%mdl;
  }
  wys=VI(mx,0);
  wys[0]=1;
  for(in i=1;i<mx;i++){
    for(in j=1;j<=i;j++){
      wys[i]+=ncr[i-1][j-1]*wys[i-j]%mdl;
    }
    wys[i]%=mdl;
  }
  in n;
  cin>>n;
  in tans=0;
  for(in i=1;i<=n;i++){
    tans+=ncr[n][i]*wys[n-i]%mdl;
  }
  tans%=mdl;
  cout<<tans<<endl;
  return 0;
}