#include <stdio.h>

int n,p,q,ans=0;

int main(){
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    scanf("%d%d",&p,&q);
    if (q-p>=2){ans++;}
  }
  printf("%d",ans);
  return 0;
}