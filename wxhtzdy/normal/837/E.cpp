#include <bits/stdc++.h>
using namespace std;
int main() {
  long long x,y,g,tmp,tmp1,ans=0,i;
  scanf("%lld%lld",&x,&y);
  while(y){
    g=__gcd(x,y);
    x/=g; y/=g;
    tmp=x, tmp1=y;
    for(i=2;i*i<=x;i++){
      if(tmp%i!=0) continue;
      tmp1=min(tmp1,y%i);
      while(tmp%i==0) tmp/=i;
    }
    if(tmp>1) tmp1=min(tmp1, y%tmp);
    y-=tmp1; ans+=tmp1;
  }
  printf("%lld\n",ans);
  return 0;
}