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
const in mdl=1000000007LL;
in p2(in a){
  return (1LL<<a);
}
in pw(in a, in b, in lm=62){
  a%=mdl;
  if(a<0)
    a+=mdl;
  in r=1;
  for(in i=lm;i>=0;--i){
    r=r*r%mdl;
    if(b&p2(i))
      r=r*a%mdl;
  }
  return r;
}
in inv(in a){
  a%=mdl;
  if(a<0)
    a+=mdl;
  assert(a!=0);
  return pw(a,mdl-2,30);
}
VI fc,invfc;
in ncr[500][500];
void inifc(){
  const in mxfc=500;
  fc.resize(mxfc);
  invfc.resize(mxfc);
  fc[0]=fc[1]=invfc[0]=invfc[1]=1;
  for(in i=2;i<mxfc;++i){
    fc[i]=fc[i-1]*i%mdl;
    invfc[i]=invfc[mdl%i]*(mdl-mdl/i)%mdl;
  }
  for(in i=2;i<mxfc;++i){
    invfc[i]*=invfc[i-1];
    invfc[i]%=mdl;
  }
}

VVI totpath;
in totp(in n, in c){
  if(c==0)
    return 1;
  in& tp=totpath[n][c];
  if(tp!=-1)
    return tp;
  if(n==1){
    if(c==1)
      return tp=1;
    return tp=0;
  }
  tp=0;
  for(in s=0;s<=c;++s){
    tp+=totp(n-1,s)*totp(n-1,c-s)%mdl*ncr[c][s]%mdl*(1+c*2);
    tp%=mdl;
  }
  for(in s=0;s<=c-1;++s){
    tp+=totp(n-1,s)*totp(n-1,c-1-s)%mdl*ncr[c-1][s]%mdl*c;
    tp%=mdl;
  }
  for(in s=0;s<=c+1;++s){
    tp+=totp(n-1,s)*totp(n-1,c+1-s)%mdl*ncr[c+1][s]%mdl*c;
    tp%=mdl;
  }
  tp%=mdl;
  return tp;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  inifc();
  in n;
  cin>>n;
  forn(i,500){
    ncr[i][i]=ncr[i][0]=1;
    for(in j=1;j<i;++j)
      ncr[i][j]=(ncr[i-1][j-1]+ncr[i-1][j])%mdl;
  }
  totpath.resize(n+1,VI(n+1,-1));  
  in r=totp(n,1);
  r%=mdl;
  if(r<0)
    r+=mdl;
  cout<<r<<endl;
  return 0;
}