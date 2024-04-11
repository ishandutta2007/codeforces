#include <bits/stdc++.h>
using namespace std;
int main() {
  int n;
  scanf("%i",&n);
  int a[n];
  for(int i=0;i<n;i++)scanf("%i",&a[i]);
  int sol=1,c=1;
  for(int i=1;i<n;i++){
    if(a[i]>=a[i-1]){
      c++;sol=max(sol,c);
    }else c=1;
  }
  printf("%i",sol);
}