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
in lt[53];
in pat(in n, in i, in cl){
  assert(i>=0 && i<lt[cl]);
  if(cl==0){
    assert(i==0);
    return n;
  }
  in t=lt[cl-1];
  if(i<t)
    return pat(n/2,i,cl-1);
  if(i==t)
    return n%2;
  return pat(n/2,i-t-1,cl-1);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,l,r;
  cin>>n>>l>>r;
  in nhv=0;
  in u=n;
  while(u>1){
    ++nhv;
    u/=2;
  }
  lt[0]=1;
  for(in i=1;i<=nhv;++i){
    lt[i]=2*lt[i-1]+1;
  }
  --l;
  --r;
  in sm=0;
  for(in i=l;i<=r;++i){
    sm+=pat(n,i,nhv);
  }
  cout<<sm<<endl;
  return 0;
}