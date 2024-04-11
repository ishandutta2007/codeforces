#include<bits/stdc++.h>
using namespace std;
const int p[]={0,2,3,5,7,13,17,19,31,61,89,107,127,521,607,1279,2203,2281,3217,4253,4423,9689,9941,11213,19937,21701,23209,44497,86243,110503,132049,216091,756839,859433,1257787,1398269,2976221,3021377,6972593,13466917,20996011};
const int mod=1e9+7;
int n;
int qpow(int a,int b){
  int ans=1;
  while(b>0){
    if(b&1)ans=1ll*ans*a%mod;
    a=1ll*a*a%mod;
    b>>=1;
  }
  return ans;
}
int main(){
  cin>>n;
  n=p[n]-1;
  cout<<(qpow(2,n)-1+mod)%mod<<'\n';
  return 0;
}