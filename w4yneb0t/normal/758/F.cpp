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
in ggt(in a, in b){
  if(b==0)
    return a;
  return ggt(b,a%b);
}
int main(){
  ios::sync_with_stdio(0);
  cin.tie(0);
  in n,l,r;
  cin>>n>>l>>r;
  in tt=(r-l+1);
  if(n==1){
    cout<<tt<<endl;
    return 0;
  }
  if(n==2){
    cout<<tt*(tt-1)<<endl;
    return 0;
  }
  if(n>30){
    cout<<0<<endl;
    return 0;
  }
  VI ps;
  for(in i=1;1;++i){
    tt=1;
    forn(z,n-1)
      tt*=i;
    if(tt>r)
      break;
    ps.PB(tt);
  }
  in sm=0;
  in num,denom;
  forv(z,ps){
    forv(zz,ps){
      num=ps[z];
      denom=ps[zz];
      if(num>=denom || ggt(num,denom)!=1)
	continue;
      in mn=l*denom/num;
      in mx=r;
      if(mn>mx)
	continue;
      sm+=(mx/denom)-((mn-1)/denom);
    }
  }
  cout<<sm*2<<endl;
  return 0;
}