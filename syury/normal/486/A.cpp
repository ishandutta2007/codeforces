#include <stdio.h>

long long int n;

long long int f(long long int x){
  if (x==1){return -1;}
  if (x==2){return 1;}
  if (x%2==0){if (x/2%2==0){return f(x/2)+x/4;}else{return f(x/2)-x/4+x;}}
  else{return f(x-1)-x;}
}

int main(){
  scanf("%I64d",&n);
  printf("%I64d",f(n));
  return 0;
}