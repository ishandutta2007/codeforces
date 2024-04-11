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
const in linf=-1000000000000000LL;
VVI bst;
VVI bencomb;
VI bens,cnt;
in n;
in cc(in msk, in l){
  in& tp=bst[msk][l];
  if(tp!=linf)
    return tp;
  if(msk==0)
    return 0;
  forn(i,n){
    if(i==l)continue;
    if(msk&1<<i){
      tp=max(tp,cc(msk^(1<<l),i)+bencomb[i][l]);
    }
  }
  tp+=bens[l];
  return tp;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in m,k;
  cin>>n>>m>>k;
  bens=VI(n);
  bencomb=VVI(n,VI(n));
  bst=VVI(1<<n,VI(n,linf));
  forn(i,n)
    cin>>bens[i];
  in x,y,c;
  forn(i,k){
    cin>>x>>y>>c;
    --x;
    --y;
    bencomb[x][y]+=c;
  }
  cnt=VI(1<<n);
  cnt[0]=0;
  for(in i=1;i<(1<<n);++i)
    cnt[i]=1+cnt[i&(i-1)];
  in rs=linf;
  forn(i,n)
    bst[1<<i][i]=bens[i];
  forn(msk,1<<n){
    if(cnt[msk]==m){
      forn(i,n){
	if(msk&1<<i)
	  rs=max(rs,cc(msk,i));
      }
    }
  }
  cout<<rs<<endl;
  return 0;
}