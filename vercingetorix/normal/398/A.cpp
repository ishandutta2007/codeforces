#include <iostream>
#include <math.h>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int>> vvi;
typedef std::vector<std::vector<long long>> vvll;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()

#define pb push_back

int main()
{
#ifndef ONLINE_JUDGE  
  freopen("input.txt", "rt", stdin);
  freopen("output.txt", "wt", stdout);
#endif
  
  ll m,n,t,p,a,b;
  cin>>a>>b;
  if(a==0){
      cout<<-b*b<<endl;
      for(int i=0;i<b;i++) cout<<"x";
      return 0;
  }
  ll ans=-999999999999;
  ll curi, curx, cury;
  for(ll i=1; i<=a; i++){
      ll sum=(a+1-i)*(a+1-i)+i-1;
      ll y=b%(i+1);
      ll x=b/(i+1);
      sum-=(i+1-y)*x*x;
      sum-=(y)*(x+1)*(x+1);
      if(sum>ans) {
          ans=sum;
          curi=i;
          curx=x;
          cury=y;
      }
  }
  cout<<ans<<endl;
  for(int j=0;j<curx;j++) cout<<"x";
  for(int j=0;j<(a+1-curi);j++) cout<<"o";
  for(int i=1; i<curi; i++){
      for(int j=0;j<curx;j++) cout<<"x";
      if(i>(curi-cury)) cout<<"x";
      cout<<"o";
  }
  for(int j=0;j<curx;j++) cout<<"x";
  if(cury>0) cout<<"x";
 

  return 0;
}