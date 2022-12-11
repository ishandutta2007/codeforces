#include <bits/stdc++.h>
using namespace std;

char z[22];
int zlen;

vector<int> stk;
int now;
bool print;

bool recur(int idx)
{
  if (idx == zlen)
  {
    int fin = 0;
    for (int n = now; n; n /= 10) fin += n % 10;
    if (fin < 10)
    {
      if (print)
      {
        printf("%d", stk[0]);
        for (int i = 1; i < stk.size(); i++)
        {
          printf("+%d", stk[i]);
        }
        printf("\n");

        string res = to_string(now);
        printf("%c", res[0]);
        for (int i = 1; i < res.size(); i++)
        {
          printf("+%c", res[i]);
        }
        printf("\n");
        exit(0);
      }
      return true;
    }

    return false;
  }

  for (int X = z[idx] - '0', Y = idx + 1; Y <= zlen; Y++)
  {
    now += X;
    stk.push_back(X);
    if (recur(Y)) return true;
    stk.pop_back();
    now -= X;
    X = X * 10 + z[Y] - '0';
  }
  return false;
}

int main()
{
  cin.sync_with_stdio(false);
  string str;
  cin >> str;
  cin >> str;

  for (int div = 1; div <= str.size(); div++)
  {
    long long res = 0;
    int j;
    for (j = 0; j + div <= str.size(); j += div)
    {
      char old = str[j + div];
      if (old) str[j + div] = 0;
      res += atoi(str.c_str() + j);
      if (old) str[j + div] = old;
    }
    if (j < str.size()) res += atoi(str.c_str() + j);

    stk.clear();
    now = 0;
    sprintf(z, "%lld", res);
    zlen = strlen(z);
    if (recur(0))
    {
      int j;
      for (j = 0; j + div <= str.size(); j += div)
      {
        char old = str[j + div];
        if (old) str[j + div] = 0;
        if (j) printf("+");
        printf("%s", str.c_str() + j);
        if (old) str[j + div] = old;
      }
      if (j < str.size()) { if (j) printf("+"); printf("%s\n", str.c_str() + j); }
      else printf("\n");
      print = true;
      stk.clear();
      now = 0;
      recur(0);
    }
  }
}