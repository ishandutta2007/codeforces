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
in p2(in a){
  return 1LL<<a;
}
vector<map<in,in> > tt(62);
in grund(in a, in msk){
  if(tt[a].count(msk))
    return tt[a][msk];
  VI hv(16);
  for(in i=1;i<=a;++i){
    if(msk&p2(i))
      continue;
    hv[grund(a-i,msk|p2(i))]=1;
  }
  in c=0;
  while(hv[c])
    ++c;
  return tt[a][msk]=c;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  in sm=0;
  in a;
  forn(z,n){
    cin>>a;
    sm^=grund(a,0);
  }
  if(sm)
    cout<<"NO"<<endl;
  else
    cout<<"YES"<<endl;
  return 0;
}