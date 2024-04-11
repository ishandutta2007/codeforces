#include <bits/stdc++.h>
using namespace std;

int main()
{
  int n, c;
  scanf("%d%d",&n,&c);
  int before = (int)-1e9 - 1;
  int ans = 0;
  for (int i = 0; i < n; i++)
  {
    int tmp;
    scanf("%d",&tmp);
    if (tmp - before > c) ans = 0;
    before = tmp;
    ans++;
  }
  printf("%d", ans);
}