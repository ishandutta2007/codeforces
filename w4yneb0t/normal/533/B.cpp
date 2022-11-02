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
#define fors(i,s) for(typeof((s).begin()) i=(s).begin();i!=(s).end();++i)
#define all(v) (v).begin(),(v).end()
using namespace std;
typedef long long in;
typedef vector<in> VI;
typedef vector<VI> VVI;
typedef pair<in,in> PII;
VI a;
VVI cd;
PII fbst(in u){
  VI bst(2,0);
  bst[1]=-1e18;
  forv(i,cd[u]){
    PII t=fbst(cd[u][i]);
    in tu=max(bst[0]+t.second,bst[1]+t.first);
    bst[0]=max(bst[0]+t.first,bst[1]+t.second);
    bst[1]=tu;
  }
  bst[1]=max(bst[1],bst[0]+a[u]);
  return MP(bst[0],bst[1]);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  cd.resize(n);
  in p;
  a.resize(n);
  forn(i,n){
    cin>>p>>a[i];
    --p;
    if(i)
      cd[p].PB(i);
  }
  PII t=fbst(0);
  cout<<max(t.first,t.second)<<endl;
  return 0;
}