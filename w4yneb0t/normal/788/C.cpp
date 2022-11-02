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
typedef vector<in> VI;
typedef vector<VI> VVI;
const in inf=1e9;
const in mx=1000;
VI avb;
in n,k;
VI brc;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  scanf("%d%d",&n,&k);
  avb.resize(mx+1,0);
  in tt;
  forn(z,k){
    scanf("%d",&tt);
    avb[tt]=1;
  }
  in hmn=inf;
  in hmx=-inf;
  in fmn=inf;
  in fmx=-inf;
  forv(i,avb){
    if(avb[i]){
      if(i>=n)
	fmn=min(fmn,i);
      if(i<=n)
	fmx=max(fmx,i);
      hmn=min(hmn,i);
      hmx=max(hmx,i);
    }
  }
  if(hmn>n || hmx<n){
    cout<<-1<<endl;
    return 0;
  }
  in ubd=max(1,fmn-fmx);
  VI nuavb(mx+1,0);
  forv(i,avb){
    if(avb[i])
      nuavb[i-hmn]=1;
  }
  n-=hmn;
  avb=nuavb;
  const in lmx=ubd*mx;
  brc.resize(lmx+1,inf);
  brc[0]=0;
  forv(i,avb){
    if(avb[i]){
      for(in j=0;j+i<=lmx;++j){
	brc[j+i]=min(brc[j+i],brc[j]+1);
      }
    }
  }
  for(in j=1;j<=ubd;++j){
    if(brc[j*n]<=j){
      cout<<j<<endl;
      return 0;
    }
  }
  assert(0);
  return 0;
}