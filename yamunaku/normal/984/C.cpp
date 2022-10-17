#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  int n;
  scanf("%d",&n);
  LL p,q,b;
  LL A,B,tmp;
  for(int t=0;t<n;t++){
    scanf("%lld %lld %lld",&p,&q,&b);
    p%=q;
    if(p==0){
      printf("Finite\n");
      continue;
    }
    A=q;
    B=p;
    while(A%B){
      tmp=B;
      B=A%B;
      A=tmp;
    }
    q/=B;
    if(q==1){
      printf("Finite\n");
      continue;
    }
    B=b;
    while(1){
      while(q%B==0){
        q/=B;
      }
      if(q==1){
        printf("Finite\n");
        break;
      }
      if(q==1) break;
      A=B;
      B=q%B;
      while(A%B){
        tmp=B;
        B=A%B;
        A=tmp;
      }
      if(B==1){
        printf("Infinite\n");
        break;
      }
    }
  }
  return 0;
}