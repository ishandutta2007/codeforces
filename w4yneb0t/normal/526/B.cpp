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
VI lts,ups;
in dpt;
in n;
in ab(in a){
  return a<0?-a:a;
}
in mx(in a, in b){
  return a>b?a:b;
}
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>dpt;
  n=(1LL<<(dpt+1));
  lts.resize(n,-1);
  ups=lts;
  for(in i=2;i<n;i++){
    cin>>ups[i];
  }
  in ta=0;
  for(in i=n-1;i>=2;i--){
    in pr=i/2;
    if(lts[pr]==-1){
      lts[pr]=ups[i]+lts[i];
      continue;
    }
    ta+=ab(lts[pr]-(ups[i]+lts[i]));
    lts[pr]=mx(lts[pr],ups[i]+lts[i]);
  }
  cout<<ta<<endl;
  return 0;
}