#include<iostream>
#include<iomanip>
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
vector<double> a,b;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  a=b=vector<double>(n);
  double p;
  cin>>p;
  forn(z,n){
    cin>>a[z]>>b[z];
  }
  double mn=0;
  double mx=1e13;
  double md;
  double hv;
  forn(zz,80){
    md=(mx+mn)/2;
    hv=0;
    forn(i,n){
      if(b[i]>=a[i]*md)
	continue;
      hv-=a[i]*md-b[i];
    }
    hv+=md*p;
    if(hv<0)
      mx=md;
    else
      mn=md;
  }
  if(mn>1e12){
    cout<<-1<<endl;
    return 0;
  }
  cout<<setprecision(15);
  cout<<mn<<endl;
  return 0;
}