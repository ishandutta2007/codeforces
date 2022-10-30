#include<cstdio>

int A[100050];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%d", &A[i]);

  int cnt = 0;
  for(int i=0; i<n-1; ++i) {
    int t = 1;
    while(i+2*t < n) t<<=1;
    cnt += A[i];
    A[i+t] += A[i];
    printf("%d\n", cnt);
  }

  return 0;
}