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
in n;
in gcd(in a, in b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
ll mr(ll cs, ll g){
  if(cs==n){
    ll r=0;
    for(in s=g;s<n;s+=g){
      if(gcd(s,n)==g)
	r+=n;
    }
    return r;
  }
  ll r=0;
  for(in s=g;s<=cs && s<n;s+=g){
    if(gcd(s,n)==g)
      r+=(cs-s+1);
  }
  return r;
}
VI mar;
VI isk;
ll wy(in g){
  in m;
  forn(s,g){
    m=0;
    for(in j=s;j<n;j+=g)
      m=max(m,mar[j]);
    for(in j=s;j<n;j+=g)
      isk[j]=(mar[j]==m);
  }
  ll r=0;
  in cs=0;
  in bgn=-1;
  forn(i,n){
    if(isk[i]){
      ++cs;
      continue;
    }
    if(bgn==-1){
      bgn=cs;
      cs=0;
      continue;
    }
    if(cs>=g)
      r+=mr(cs,g);
    cs=0;
  }
  if(bgn==-1)
    return mr(cs,g);
  cs+=bgn;
  if(cs>=g)
    r+=mr(cs,g);
  return r;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  isk.resize(n);
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  ll sm=0;
  for(in i=1;i<n;++i){
    if(n%i)
      continue;
    sm+=wy(i);
  }
  cout<<sm<<endl;
  return 0;
}