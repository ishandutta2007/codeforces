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
  in n;
  cin>>n;
  VI p(n);
  in sm=0;
  forn(z,n){
    cin>>p[z];
    --p[z];
  }
  forn(i,n){
    if(p[i]==i)
      ++sm;
    if(p[p[i]]==i)
      ++sm;
  }
  assert(sm%2==0);
  cout<<sm/2<<endl;
  return 0;
}