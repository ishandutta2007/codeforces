#include<cstdio>
int n,i,x;char a[11111];
int main(){
  scanf("%d%s",&n,a+1);
  for(x=i=1;i<=n;i+=x++)putchar(a[i]);
}