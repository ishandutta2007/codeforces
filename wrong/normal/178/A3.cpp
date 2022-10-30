#include<cstdio>

long long A[100050];

int main()
{
  int n;
  scanf("%d", &n);
  for(int i=0; i<n; ++i)
    scanf("%I64d", &A[i]);

  long long cnt = 0;
  for(int i=0; i<n-1; ++i) {
    int t = 1;
    while(i+2*t < n) t<<=1;
    cnt += A[i];
    A[i+t] += A[i];
    printf("%I64d\n", cnt);
  }

  return 0;
}