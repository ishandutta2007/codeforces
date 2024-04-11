#include <bits/stdc++.h>

using namespace std;

int main() {
  int n;
  scanf("%i",&n);
  int a[n];
  for(int i=0;i<n;i++) scanf("%i",&a[i]);
  sort(a,a+n);
  if(a[0]>1) {printf("1"); return 0;}
  printf("-1");
}