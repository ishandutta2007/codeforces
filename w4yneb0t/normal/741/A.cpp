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
in gcd(in a, in b){
  if(b==0)
    return a;
  return gcd(b,a%b);
}
VI a;
VI gd;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  a.resize(n);
  gd.resize(n);
  forn(i,n){
    cin>>a[i];
    --a[i];
    gd[a[i]]=1;
  }
  forn(z,n){
    if(!gd[z]){
      cout<<-1<<endl;
      return 0;
    }
  }
  in sm=1;
  forn(z,n){
    if(!gd[z])
      continue;
    in u=z;
    in c=0;
    do{
      ++c;
      gd[u]=0;
      u=a[u];
    }while(u!=z);
    if(c%2==0)
      c/=2;
    sm=sm*(c/gcd(c,sm));
  }
  cout<<sm<<endl;
  return 0;
}