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
in a,b;
int main(){
  cin.tie(0);
  ios::sync_with_stdio(0);
  cin>>a>>b;
  in y=0;
  for(in x=1000;x>0;x--){
    while(x*x+y*y<a*a)
      y++;
    if(y==0)
      continue;
    if(x*x+y*y==a*a){
      in xb=-y;
      in yb=x;
      if((xb*b)%a)
	continue;
      if((yb*b)%a)
	continue;
      xb=(xb*b)/a;
      yb=(yb*b)/a;
      if(yb==y)
	continue;
      cout<<"YES"<<endl;
      cout<<"0 0"<<endl;
      cout<<x<<" "<<y<<endl;
      cout<<xb<<" "<<yb<<endl;
      return 0;
    }
  }
  cout<<"NO"<<endl;
  return 0;
}