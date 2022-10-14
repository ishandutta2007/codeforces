#include <bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  scanf("%i%i",&n,&k);
  int a[k];
  for(int i=0;i<k;i++)scanf("%i",&a[i]);
  sort(a,a+k);
  int sol=a[k-1];
  for(int i=n-1;i<k;i++)sol=min(sol,a[i]-a[i-n+1]);
  printf("%i",sol);
}