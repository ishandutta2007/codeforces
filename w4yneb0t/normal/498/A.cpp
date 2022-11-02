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
  in x1,y1,x2,y2,n;
  cin>>x1>>y1>>x2>>y2>>n;
  in sm=0;
  in a,b,c;
  forn(z,n){
    cin>>a>>b>>c;
    if((x1*a+y1*b+c<0)!=(x2*a+y2*b+c<0))
      ++sm;
  }
  cout<<sm<<endl;
  return 0;
}