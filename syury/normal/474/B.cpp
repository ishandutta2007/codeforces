#include <stdio.h>

int n,m;
int q[100000],a[100001];
int g[1000001];

int main(){
  scanf("%d",&n);
  for (int i=0;i<n;i++){scanf("%d",&a[i]);if (i>0){a[i]+=a[i-1];}}
  a[n]=a[n-1];
  scanf("%d",&m);
  int ci=0;
  for (int i=0;i<=a[n];i++){
    if(i>a[ci]){ci++;}
    g[i]=ci+1;
  }
  for (int i=0;i<m;i++){scanf("%d",&q[i]);}
  for (int i=0;i<m;i++){printf("%d\n",g[q[i]]);}
  return 0;
}