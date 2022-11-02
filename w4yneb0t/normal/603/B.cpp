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
in p,k;
in pw(in a, in b){
  in r=1;
  for(in i=40;i>=0;--i){
    r=r*r%mdl;
    if(b&1LL<<i)
      r=r*a%mdl;
  }
  return r;
}
void sol(in a){
  cout<<pw(p,a)<<endl;
  exit(0);
}
in mpp(in p, in k){
  in c=k;
  in ct=1;
  while(c!=1){
    c=c*k%p;
    ++ct;
  }
  return ct;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>p>>k;
  if(k==0)
    sol(p-1);
  if(k==1)
    sol(p);
  in c=mpp(p,k);
  assert((p-1)%c==0);
  sol((p-1)/c);
  return 0;
}