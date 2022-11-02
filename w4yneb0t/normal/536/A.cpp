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
in sm(in a, in b, in k){
  return a*(k+1)+k*(k+1)/2*b;
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in a,b,n;
  cin>>a>>b>>n;
  in l,t,m;
  forn(i,n){
    cin>>l>>t>>m;
    in mn=l-1;
    in mx=1000009;
    in md;
    while(mx-mn>1){
      md=(mx+mn)/2;
      if(a+(md-1)*b<=t && sm(a+(l-1)*b,b,md-l)<=m*t)
	mn=md;
      else
	mx=md;
    }
    cout<<(mn==l-1?-1:mn)<<"\n";
  }
  return 0;
}