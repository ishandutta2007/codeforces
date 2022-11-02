#include<stdio.h>

int m,n,a,b,left,div;

int main(){
  scanf("%d%d%d%d",&n,&m,&a,&b);
  if (a*m<=b){printf("%d",a*n);}
  else {left=n%m;div=n/m;
    if (left*a<=b){printf("%d",left*a+div*b);}else{printf("%d",b*(div+1));}
  }
  return 0;
}