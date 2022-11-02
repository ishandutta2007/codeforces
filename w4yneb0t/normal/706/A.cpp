#include<iostream>
#include<cmath>
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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  double a,b;
  cin>>a>>b;
  in n;
  cin>>n;
  double bst=1e20;
  double x,y,v;
  forn(z,n){
    cin>>x>>y>>v;
    x-=a;
    y-=b;
    bst=min(bst,sqrt(x*x+y*y)/v);
  }
  cout<<setprecision(15)<<bst<<endl;
  return 0;
}