#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>
#include<cstdio>
#include<queue>
#include<cassert>
using namespace std;
typedef long long in;
in tm[1000];
in f(in k, in d){
  assert(((1LL<<62LL)+(1LL<<61LL))/d >= (1LL<<k)-1LL+(d-1LL)/2LL);
  return ((1LL<<k)-1LL+(d-1LL)/2LL)*d;
}
int main(){
  in nts=0;
  in n;
  cin>>n;
  //2^k * d
  //(2^k - 1 + (d-1)/2)*d
  //d^2/2 + d*(1/2 + 2^k) = n
  //d^2 + d*2^(k+1) = 2*n
  //(d+2^k)^2 - 2^(2*k) = 2*n
  //(d+2^k)^2 = 2*n+2^(2*k)
  //d = sqrt(2*n+2^(2*k)) - 2^k
  for(in k=0;(1LL<<k)<=n+1LL;k++){
    in mx=1;
    in mn=1;
    in md;
    while(f(k,mx)<=n) mx*=2LL;
    while(mx-mn>1LL){
      md=(mx+mn)/2LL;
      if(f(k,md)>n)
        mx=md;
      else
        mn=md;
    }
    if(f(k,mn)==n && mn%2LL==1LL)
      tm[nts++]=(1LL<<k)*mn;
  }
  sort(tm,tm+nts);
  for(in i=0;i<nts;i++){
    cout<<tm[i]<<endl;
  }
  if(nts==0)
    cout<<-1<<endl;
  return 0;
}