#include "stdio.h"
 
int main(){
  int i,c;
  long long int n;
  scanf("%lld",&n);
  
  for(c=0; n>0; n/=10){
    if((n%10 == 4)||(n%10==7))
      c++;
  }
 
  
  if((c==4)||(c==7))
    printf("YES");
  else
    printf("NO");
  return 0;
}