#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,d,h;
  scanf("%i%i%i",&n,&d,&h);
  if(n==2){
    if(h==1&&d==1){
      printf("1 2");
      return 0;
    } else {
      printf("-1");
      return 0;
    }
  }
  if(d==1||d>2*h){printf("-1");return 0;}
  int v=2,e=0;
  for(int i=0;i<h;i++)printf("%i %i\n",v-1,v),v++;
  for(int i=0;i<d-h;i++){
    if(i==0){printf("%i %i\n",1,v),v++;}
    else printf("%i %i\n",v-1,v),v++;
  }
  if(d==h){
    for(int i=0;i<n-d-1;i++){
      printf("%i %i\n",2,v),v++;
    }
  }else{
    for(int i=0;i<n-d-1;i++){
      printf("%i %i\n",1,v),v++;
    }
  }
}