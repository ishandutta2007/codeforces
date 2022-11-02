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
VI t;
VI c;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n;
  cin>>n;
  t.resize(n);
  c.resize(n+1);
  forn(i,n)
    cin>>t[i];
  in can5=0;
  in can12=0;
  forn(i,n){
    c[i+1]=20+c[i];
    while(t[i]-t[can5]>=90)
      ++can5;
    while(t[i]-t[can12]>=1440)
      ++can12;
    c[i+1]=min(c[i+1],50+c[can5]);
    c[i+1]=min(c[i+1],120+c[can12]);
    cout<<c[i+1]-c[i]<<"\n";
  }
  return 0;
}