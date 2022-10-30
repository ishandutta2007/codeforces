#include<cstdio>
#include<cstring>

int gcd(int m, int n)
{
  return m%n ? gcd(n, m%n) : n;
}

int lcm(int a, int b)
{
  return a / gcd(a, b) * b;
}

int main()
{
  int n, m, k, x, sa = 0, sb = 0, sola = 0, solb = 0;
  char A[1024], B[1024];
  scanf("%d%s%s", &n, A, B);
  m = strlen(A);
  k = strlen(B);
  x = lcm(m, k);
  for(int i=0; i<m; ++i)
    A[i] = (A[i]=='R' ? 0 : (A[i]=='S' ? 1 : 2));
  for(int i=0; i<k; ++i)
    B[i] = (B[i]=='R' ? 0 : (B[i]=='S' ? 1 : 2));
  for(int i=0; i<x; ++i) {
    if(i == n%x) { sola=sa; solb=sb; }
    if((A[i%m]+1)%3 == B[i%k]) sb++;
    if((B[i%k]+1)%3 == A[i%m]) sa++;
  }
  printf("%d %d\n", sola+sa*(n/x), solb+sb*(n/x));
}