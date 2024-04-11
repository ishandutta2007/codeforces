#include<cstdio>
#include<algorithm>
using namespace std;

long long n, m, s;

long long getans(const long long i) {
  if (i % s == 0) return i; else return (i / s + 1 ) * (i % s);
}

int main() {
  scanf("%I64d %I64d %I64d", &n, &m, &s);
  printf("%I64d\n", getans(n) * getans(m));
  return 0;
}