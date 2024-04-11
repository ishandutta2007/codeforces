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
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  VI fb(n+1);
  in mx=2e18;
  fb[0]=fb[1]=1;
  for(in i=2;i<=n;++i){
    fb[i]=fb[i-1]+fb[i-2];
    fb[i]=min(fb[i],mx);
  }
  in inc=1;
  in nxid=0;
  in lft=n;
  while(nxid<n){
    if(fb[lft-1]>=k){
      cout<<inc<<" ";
      ++inc;
      ++nxid;
      --lft;
      continue;
    }
    k-=fb[lft-1];
    cout<<(inc+1)<<" "<<inc<<" ";
    inc+=2;
    nxid+=2;
    lft-=2;
  }
  cout<<endl;
  return 0;
}