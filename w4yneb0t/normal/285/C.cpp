#include<iostream>
#include<algorithm>
#define forn(i,n) for(int i=0;i<(n);++i)
using namespace std;
typedef long long ll;
ll ab(ll a){
  if(a<0)
    return -a;
  return a;
}
int main(){
  int n;
  cin>>n;
  ll p[300009];
  forn(i,n){
    cin>>p[i];
  }
  sort(p,p+n);
  ll r=0;
  forn(i,n){
    r+=ab(p[i]-(i+1));
  }
  cout<<r<<endl;
  return 0;
}