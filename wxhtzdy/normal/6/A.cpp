#include <bits/stdc++.h>
using namespace std;
int a[4];
int main() {
  for(int i=0;i<4;i++)scanf("%i",&a[i]);
  sort(a,a+4);
  for(int i=2;i<4;i++)if(a[i-2]+a[i-1]>a[i]){printf("TRIANGLE");return 0;}
  for(int i=2;i<4;i++)if(a[i-2]+a[i-1]==a[i]){printf("SEGMENT");return 0;}
  printf("IMPOSSIBLE");
}