#include <bits/stdc++.h>

using namespace std;

const int MAXN = 1000005;

int nTest, n, m, p, a[MAXN], b[MAXN];


int main() {
  scanf("%d%d%d", &n, &m, &p);
  for(int i = 0; i < n; ++i)
    scanf("%d", &a[i]);
  for(int i = 0; i < m; ++i)
    scanf("%d", &b[i]);

  int idA = n-1;
  while (a[idA] % p == 0)
    --idA;
  int idB = m-1;
  while (b[idB] % p == 0)
    --idB;

  printf("%d\n", idA + idB);

  return 0;
}