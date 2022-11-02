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
in n,a,b;
VI mar;
VI cng;
in conv(in x){
  if(x==0)
    return 0;
  if(x==1 || x==-1)
    return 1;
  return 2;
}
in proc(in gl){
  forn(i,n){
    cng[i]=mar[i]%gl;
    if(cng[i]>1)
      cng[i]-=gl;
    cng[i]=conv(cng[i]);
  }
  in ct0=0;
  in ct1=0;
  in ct2=0;
  forn(i,n){
    ct0=min(ct0,in(1e18));
    ct1=min(ct1,ct0);
    ct2=min(ct2,ct1);
    if(cng[i]==2)
      ct0=ct2=1e18;
    if(cng[i]==1){
      ct0+=b;
      ct2+=b;
    }
    ct1+=a;
  }
  return min(ct0,min(ct1,ct2));
}

in totbst=1e18;
set<in> cands;
void adrl(in x){
  for(in i=2;i*i<=x;++i){
    if(x%i==0){
      cands.insert(i);
      while(x%i==0)
	x/=i;
    }
  }
  if(x!=1)
    cands.insert(x);
}
void adcand(in x){
  for(in i=-1;i<=1;++i)
    adrl(x+i);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n>>a>>b;
  mar.resize(n);
  cng.resize(n);
  forn(i,n)
    cin>>mar[i];
  adcand(mar[0]);
  adcand(mar[n-1]);
  fors(it,cands)
    totbst=min(totbst,proc(*it));
  cout<<totbst<<endl;
  return 0;
}