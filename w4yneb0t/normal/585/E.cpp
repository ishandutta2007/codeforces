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
typedef int in;
typedef long long ll;
typedef vector<in> VI;
typedef vector<VI> VVI;
const in mx=10000009;
const in mdl=1000000007;
vector<int> ct;
vector<int> wp;
vector<int> rmg,rf;
vector<int> p2;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  ct.resize(mx);
  wp.resize(mx);
  rmg.resize(mx);
  rf.resize(mx,1);
  p2.resize(in(6e5));
  p2[0]=1;
  for(in i=1;i<sz(p2);++i)
    p2[i]=p2[i-1]*2%mdl;
  in n;
  scanf("%d",&n);
  in t;
  forn(z,n){
    scanf("%d",&t);
    ++ct[t];
  }
  ll tp;
  forn(i,mx)
    rmg[i]=i;
  for(in i=1;i<mx;++i){
    for(in j=2*i;j<mx;j+=i)
      ct[i]+=ct[j];
    if(i>=2 && rmg[i]==i){
      for(in j=i;j<mx;j+=i){
	rmg[j]/=i;
	rf[j]*=-1;
      }
    }
  }
  for(in i=mx-1;i>=1;--i){
    wp[i]=p2[ct[i]]-1;
    tp=0;
    for(in j=2*i;j<mx;j+=i)
      tp+=wp[j];
    wp[i]-=tp%mdl;
    if(wp[i]<0)
      wp[i]+=mdl;
  }
  ll sm=0;
  wp[1]=0;
  for(in i=1;i<mx;++i){
    if(rmg[i]!=1)
      continue;
    for(in j=i;j<mx;j+=i)
      sm+=rf[i]*ll(ct[i])*wp[j];
  }
  sm%=mdl;
  if(sm<0)
    sm+=mdl;
  printf("%lld\n",sm);
  return 0;
}