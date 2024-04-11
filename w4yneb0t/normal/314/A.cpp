#include<iostream>
using namespace std;
typedef long long ll;
ll rat;
ll cur;
ll n,k;
int main(){
  cur=0;
  ll rem=0;
  cin>>n>>k;
  for(ll i=1;i<=n;i++){
    cin>>rat;
    if(cur-(i-rem-1LL)*(n-i)*rat<k){
      cout<<i<<endl;
      rem++;
      continue;
    }
    cur+=rat*((i-rem)-1LL);
  }
  return 0;
}