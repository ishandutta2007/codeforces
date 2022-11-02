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
in n,x,h;
in sm=0;
in rt=-2000000000LL;
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  cin>>n;
  in pvr=rt;
  forn(i,n){
    cin>>x>>h;
    if(x<=rt){
      rt=pvr;
      sm--;
    }
    if(x-h>rt){
      rt=x;
      sm++;
      continue;
    }
    pvr=x;
    rt=x+h;
    sm++;
  }
  cout<<sm<<endl;
  return 0;
}