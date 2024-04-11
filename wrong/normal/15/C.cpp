#include<cstdio>

using namespace std;

long long foldxor(long long x)
{
  long long ret = 0;
  if(x <= 0) return 0;
  if(x % 4 == 1 || x % 4 == 2) ret |= 1;
  for(long long bit = 2; bit <= x; bit <<= 1) {
    long long k = x % (bit*2);
    if(k % 2 == 0 && k >= bit) ret |= bit;
  }
  return ret;
}

int main()
{
  int n;
  scanf("%d", &n);
  long long sol = 0;
  for(int i=0; i<n; ++i) {
    long long m, x;
    scanf("%I64d%I64d", &x, &m);
    sol ^= foldxor(x-1) ^ foldxor(x+m-1);
  }
  if(sol == 0) puts("bolik");
  else puts("tolik");
  return 0;
}