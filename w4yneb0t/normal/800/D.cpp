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
VI cnt,sm,smprd;
VI actv;
const in mx=1000000;
const in mdl=1000000007;
VI p10;
VI p2;
void adt(in a, in ct, in s, in spr, in acv){
  cnt[a]+=ct;
  smprd[a]+=spr+sm[a]*s;
  smprd[a]%=mdl;
  sm[a]+=s;
  sm[a]%=mdl;
  actv[a]+=acv;
  actv[a]%=mdl;
  if(actv[a]<0)
    actv[a]+=mdl;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  p2.PB(1);
  forn(i,mx+5)
    p2.PB(p2[i]*2%mdl);
  p10.PB(1);
  forn(i,10)
    p10.PB(p10[i]*10);
  cnt=sm=actv=smprd=VI(mx);
  int n;
  scanf("%d",&n);
  int a;
  forn(z,n){
    scanf("%d",&a);
    adt(a,1,a,a*in(a)%mdl,0);
  }
  forn(i,6){
    forn(c,mx){
      if(c/p10[i]%10!=9)
	continue;
      in cr=c;
      forn(j,9){
	adt(cr-p10[i],cnt[cr],sm[cr],smprd[cr],0);
	cr-=p10[i];
      }
    }
  }
  forn(c,mx){
    if(cnt[c]>=1)
      actv[c]=smprd[c]*p2[cnt[c]-1]%mdl;
  }
  forn(i,6){
    forn(c,mx){
      if(c/p10[i]%10!=0)
	continue;
      in cr=c;
      forn(j,9){
	cr+=p10[i];
	adt(cr-p10[i],0,0,0,-actv[cr]);
      }
    }
  }
  in totxor=0;
  forn(c,mx)
    totxor^=(c*actv[c]);
  printf("%lld\n",totxor);
  return 0;
}