#include<cstdio>

int main()
{
  int n, a[100];
  scanf("%d", &n);
  for(int i=0; i<n; ++i) scanf("%d", &a[i]);
  int mi = 0, Mi = 0;
  for(int i=1; i<n; ++i) {
    if(a[mi] >= a[i]) mi = i;
    if(a[Mi] < a[i]) Mi = i;
  }
  int S = Mi + (n-mi-1);
  if(mi<Mi) S--;
  printf("%d\n", S);
  return 0;
}