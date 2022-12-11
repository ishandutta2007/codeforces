#include <bits/stdc++.h>
using namespace std;

int ask(int a, int b)
{
  printf("? %d %d\n", a, b);
  fflush(stdout);

  char ch;
  scanf(" %c", &ch);
  if (ch == '<') return -1;
  else if (ch == '=') return 0;
  else return 1;
}

int main()
{
  int T;
  scanf("%d",&T);
  while (T--)
  {
    int n;
    scanf("%d",&n);

    if (n == 1)
    {
      printf("! 1 1\n");
      fflush(stdout);
      continue;
    }

    vector<int> mins, maxs;

    for (int i = 0; i < n / 2; i++)
    {
      int res = ask(i * 2 + 1, i * 2 + 2);
      if (res <= 0)
      {
        mins.push_back(i*2+1);
        maxs.push_back(i*2+2);
      }
      else
      {
        mins.push_back(i*2+2);
        maxs.push_back(i*2+1);
      }
    }

    if (n & 1) mins.push_back(n), maxs.push_back(n);

    int minv = mins[0];
    for (int i = 1; i < mins.size(); i++)
    {
      if (ask(minv, mins[i]) > 0) minv = mins[i];
    }

    int maxv = maxs[0];
    for (int i = 1; i < maxs.size(); i++)
    {
      if (ask(maxv, maxs[i]) < 0) maxv = maxs[i];
    }

    printf("! %d %d\n", minv, maxv);
    fflush(stdout);
  }
}