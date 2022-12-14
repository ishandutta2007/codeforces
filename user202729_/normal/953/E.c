#include<stdio.h>
int a[200001];int size=0;
int main(){
   int n;scanf("%d",&n);
   while(n-->0){
      scanf("%d",&a[size]);++size;
      while(size>=2&&a[size-1]==a[size-2]){
         --size;
         ++a[size-1];
      }
   }
   printf("%d\n",size);
   for(int i=0;i<size;++i)printf("%d ",a[i]);
   printf("\n");
}