#include <bits/stdc++.h>
using namespace std;

pair<int,int> dat[105];
vector<vector<int>> anses;

int main()
{
  int n;
  scanf("%d",&n);
  for (int i = 0; i < n; i++)
  {
    scanf("%d",&dat[i].first);
    dat[i].second = i;
  }
  sort(dat,dat+n,greater<pair<int,int>>());

  auto dump = [&]()
  {
    return;
    for (int i = 0; i < n; i++) printf("%d ", dat[i].first);
    printf("\n");
  };

  if (n == 2)
  {
    if (dat[0].first != dat[1].first)
    {
      printf("0\n%d\n", max(dat[0].first, dat[1].first));
      while (dat[0].first > 0 || dat[1].first > 0)
      {
        printf("11\n");
        dat[0].first--; dat[1].first--;
      }
    }
    else
    {
      printf("%d\n0\n", dat[0].first);
    }
    return 0;
  }
  else
  {
    while (dat[0].first > dat[1].first)
    {
      vector<int> minus;

      int idx = max_element(&dat[2],&dat[n])-dat;

      minus.push_back(dat[0].second);
      minus.push_back(dat[idx].second);
      dat[0].first--; dat[idx].first--;
      dat[idx].first = max(dat[idx].first, 0);

      dump();
      anses.emplace_back(move(minus));
    }

    sort(dat, dat+n, greater<pair<int,int>>());

    while (dat[0].first > dat[n-1].first)
    {
      int j = 1;
      while (dat[j].first == dat[0].first) j++;
      j--;

      // 0 ~ j

      int i = 0;
      while (j - i + 1 > 3)
      {
        anses.push_back({dat[i].second, dat[i + 1].second});
        dat[i].first--; dat[i+1].first--;
        i += 2;
      }

      dat[i].first--; dat[i+1].first--;
      if (j - i == 1) anses.push_back({dat[i].second, dat[i + 1].second});
      else anses.push_back({dat[i].second, dat[i + 1].second, dat[i + 2].second}), dat[i+2].first--;

      dump();
    }

    printf("%d\n%d\n", dat[n-1].first, (int)anses.size());
    for (auto &&vt : anses)
    {
      string str(n, '0');
      for (int t : vt) str[t] = '1';
      printf("%s\n", str.c_str());
    }
  }
}