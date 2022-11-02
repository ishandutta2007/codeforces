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
const in mx=24;
inline in p2(const in& a){
  return 1LL<<a;
}
VI wys(p2(mx));
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  string s;
  forn(z,n){
    cin>>s;
    in msk=0;
    forv(i,s)
      msk|=p2(s[i]-'a');
    ++wys[msk];
  }
  forn(i,mx){
    forn(msk,p2(mx)){
      if(msk&p2(i))
	continue;
      wys[msk|p2(i)]+=wys[msk];
    }
  }
  in tx=0;
  forn(i,p2(mx)){
    tx^=(n-wys[i])*(n-wys[i]);
  }
  cout<<tx<<endl;
  return 0;
}