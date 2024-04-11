#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%i",&n);
  int a[n];
  for(int i=0;i<n;i++) scanf("%i",&a[i]);
  sort(a,a+n);
  bool ok=0;
  for(int i=2;i<n;i++) if(a[i-2]+a[i-1]>a[i])ok=1;
  if(ok)printf("YES");
  else printf("NO");
}