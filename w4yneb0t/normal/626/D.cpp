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
const in mx=5009;
VI wtd;
VI mar;
VI wtsm;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  mar.resize(n);
  forn(i,n)
    cin>>mar[i];
  sort(all(mar));
  wtd=VI(mx,0);
  forn(i,n){
    forn(j,i)
      ++wtd[mar[i]-mar[j]];
  }
  wtsm=VI(2*mx+9,0);
  forn(i,mx){
    forn(j,i)
      wtsm[i+j]+=2*wtd[i]*wtd[j];
    wtsm[2*i]+=wtd[i]*wtd[i];
  }
  double wtbt=0;
  for(in i=1;i<mx;++i){
    wtsm[i]+=wtsm[i-1];
    wtbt+=wtsm[i-1]*wtd[i];
  }
  forn(zz,3)
    wtbt/=(n*(n-1)/2);
  cout<<setprecision(15)<<wtbt<<endl;
  return 0;
}