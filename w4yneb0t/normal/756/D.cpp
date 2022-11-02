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
  const in mxfc=1001000;
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
VVI trm;
VVI wys;
VI lst;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  inifc();
  in n;
  cin>>n;
  string s;
  cin>>s;
  const in asz=26;
  lst.resize(asz,-1);
  trm.resize(n);
  wys.resize(n+3,VI(asz+1));
  wys[0][asz]=1;
  in tr;
  in tla;
  forn(i,n){
    trm[i].resize(i+1);
    for(in j=i;j>=0;--j){
      tr=wys[j][asz]-wys[j][s[i]-'a'];
      trm[i][j]=tr;
      tla=lst[s[i]-'a'];
      if(tla>-1 && j<=tla)
	tr-=trm[tla][j];
      wys[j+1][s[i]-'a']+=tr;
      wys[j+1][asz]+=tr;
      wys[j+1][s[i]-'a']%=mdl;
      wys[j+1][asz]%=mdl;
    }
    lst[s[i]-'a']=i;
  }
  in sm=0;
  for(in j=1;j<=n;++j){
    sm+=wys[j][asz]*ncr(n-j+j-1,j-1)%mdl;
  }
  sm%=mdl;
  if(sm<0)
    sm+=mdl;
  cout<<sm<<endl;
  return 0;
}