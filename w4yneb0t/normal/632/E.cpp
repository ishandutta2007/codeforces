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
typedef vector<in> VI;
typedef vector<VI> VVI;
VI bst;
VI pds;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,k;
  cin>>n>>k;
  pds.resize(n);
  forn(i,n)
    cin>>pds[i];
  in cmin;
  sort(all(pds));
  reverse(all(pds));
  cmin=pds.back();
  pds.pop_back();
  --n;
  forn(i,n)
    pds[i]-=cmin;
  in msz=1003*(k+2);
  bst.resize(msz,10000);
  bst[0]=0;
  in tp;
  forn(zz,n){
    tp=pds[zz];
    for(in i=0;i+tp<msz;++i)
      bst[i+tp]=min(bst[i+tp],bst[i]+1);
  }
  forn(i,msz)
    if(bst[i]<=k)
      cout<<i+k*cmin<<" ";
  cout<<endl;
  return 0;
}