#include <stdio.h>
#include <stdlib.h>

#define end exit(0)

bool levels[100];
int ans=0,n,p,q,x;

int main(){
  scanf("%d",&n);
  for (int i=0;i<n;i++){
    levels[i]=false;
  }
  scanf("%d",&p);
  for (int i=0;i<p;i++){
    scanf("%d",&x);
    levels[x-1]=true;
  }
  scanf("%d",&q);
  for (int i=0;i<q;i++){
    scanf("%d",&x);
    levels[x-1]=true;
  }
  for (int i=0;i<n;i++){
    if (!levels[i]){printf("Oh, my keyboard!");end;}
  }
  printf("I become the guy.");
  return 0;
}