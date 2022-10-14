#include <bits/stdc++.h>
using namespace std;
int main(){
  int t;
  scanf("%i",&t);
  while(t--){
    int a,b;
    scanf("%i%i",&a,&b);
    if(a*2>b)printf("-1 -1\n");
    else printf("%i %i\n",a,a*2);
  }
}