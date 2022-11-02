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
in l;
in w(in bg, in sml1, in sml2){
  in r=0;
  in cb;
  in rm;
  forn(lg,l+1){
    cb=bg+lg;
    rm=cb-sml1-sml2;
    if(rm<0)continue;
    rm=min(rm,l-lg);
    r+=(rm+2)*(rm+1)/2;
  }
  return r;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in a,b,c;
  cin>>a>>b>>c>>l;
  in gw=(l+3)*(l+2)*(l+1)/6;
  gw-=w(a,b,c);
  gw-=w(b,a,c);
  gw-=w(c,b,a);
  cout<<gw<<endl;
  return 0;
}