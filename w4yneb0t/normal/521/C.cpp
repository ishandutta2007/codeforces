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
in ncr(in a, in b){
  if(b==0 || b==a)
    return 1;//even if a<0
  if(b<0 || b>a)
    return 0;
  return fc[a]*invfc[b]%mdl*invfc[a-b]%mdl;
}
void inifc(){
  const in mxfc=301000;
  fc.resize(mxfc);
  invfc.resize(mxfc);
  fc[0]=invfc[0]=1;
  for(in i=1;i<mxfc;++i){
    fc[i]=fc[i-1]*i%mdl;
    invfc[i]=invfc[i-1]*inv(i)%mdl;
  }
}

string s;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  inifc();
  in n,k;
  cin>>n>>k>>s;
  in sm=0;
  in wtg=0;
  in npw=1;
  for(in i=n-1;i>=0;--i){
    sm+=(s[i]-'0')*(wtg+ncr(i,k)*npw%mdl);
    sm%=mdl;
    wtg+=ncr(i-1,k-1)*npw;
    wtg%=mdl;
    npw=npw*10%mdl;
  }
  cout<<sm<<endl;
  return 0;
}