#include <bits/stdc++.h>
using namespace std;
int main() {
  int a,b;
  scanf("%i%i",&a,&b);
  int sol=1;
  for(int i=2;i<=min(a,b);i++)sol*=i;
  printf("%i",sol);
}