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
VI mar;
VI flf;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  const in inf=1000000000000LL;
  mar=VI(n+2,0);
  flf=VI(n+2,inf);
  for(in i=1;i<=n;i++)
    cin>>mar[i];
  in bsd=0;
  forn(i,n+2){
    bsd++;
    bsd=min(bsd,mar[i]);
    flf[i]=min(flf[i],bsd);
  }
  bsd=0;
  for(in i=n+1;i>=0;i--){
    bsd++;
    bsd=min(bsd,mar[i]);
    flf[i]=min(flf[i],bsd);
  }
  in mx=0;
  for(in i=1;i<=n;i++)
    mx=max(mx,flf[i]);
  cout<<mx<<endl;
  return 0;
}