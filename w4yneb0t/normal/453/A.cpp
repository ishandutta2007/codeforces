#include<iostream>
#include<cstdio>
#include<algorithm>
#include<set>
#include<map>
#include<queue>
#include<iomanip>
#include<cassert>
#define PB push_back
#define MP make_pair
#define sz(v) (in((v).size()))
#define forn(i,n) for(in i=0;i<(n);++i)
#define forv(i,v) forn(i,sz(v))
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
double pw(double a, in n){
  double r=1;
  for(in i=20;i>=0;i--){
    r*=r;
    if(n&(1LL<<i))
      r*=a;
  }
  return r;
}
in n,m;
double prob(in a){
  return pw((a+1)/double(m),n);
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>m>>n;
  double tsm=0;
  double p,o;
  o=0;
  forn(i,m){
    p=prob(i);
    tsm+=(p-o)*(i+1);
    o=p;
  }
  cout<<setprecision(15);
  cout<<tsm<<endl;
  return 0;
}