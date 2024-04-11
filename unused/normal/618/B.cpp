#include <bits/stdc++.h>
using namespace std;

int dat[55][55];

int main()
{
  int n;
  scanf("%d",&n);
  bool f = false;
  for (int i = 0; i < n; i++)
  {
    int ans = 0;
    for (int j = 0; j < n; j++)
    {
      int tmp;
      scanf("%d",&tmp);
      ans = max(ans, tmp);
    }
    if (ans == n - 1)
    {
      if (f) ans = n;
      else f = true;
    }
    printf("%d ", ans);
  }
}