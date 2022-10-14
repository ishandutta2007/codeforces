#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%i",&n);
  int a[2*n];
  for(int i=0;i<2*n;i++)scanf("%i",&a[i]);
  sort(a,a+2*n);
  if(a[n]==a[n-1])printf("NO");
  else printf("YES");
}