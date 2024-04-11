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
const in mdl=1000000007;
VI x;
in n;
in cc(){
  in s=0;
  in p2=1;
  forv(i,x){
    s+=p2*x[i];
    s%=mdl;
    p2*=2;
    p2%=mdl;
  }
  return s;
}
in sm=0;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  x.resize(n);
  forn(i,n)
    cin>>x[i];
  sort(all(x));
  sm+=cc();
  reverse(all(x));
  sm-=cc();
  sm%=mdl;
  if(sm<0)
    sm+=mdl;
  cout<<sm<<endl;
  return 0;
}