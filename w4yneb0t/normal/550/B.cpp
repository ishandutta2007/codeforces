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
  in n,l,r,x;
  cin>>n>>l>>r>>x;
  VI c;
  c.resize(n);
  forn(i,n)
    cin>>c[i];
  in sm=0;
  forn(msk,(1LL<<n)){
    in mn=1000000000;
    in mx=-10;
    in tt=0;
    in nb=0;
    forn(i,n){
      if(msk&(1LL<<i)){
	nb++;
	tt+=c[i];
	mn=min(c[i],mn);
	mx=max(c[i],mx);
      }
    }
    if(nb>=2 && tt<=r && tt>=l && mx-mn>=x)
      sm++;
  }
  cout<<sm<<endl;
  return 0;
}