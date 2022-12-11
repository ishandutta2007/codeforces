#include <bits/stdc++.h>
using namespace std;

string str[105];
bool z[105];

int main()
{
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
  {
    cin >> str[i];
  }

  vector<int> sel;
  sel.resize(m);

  for (int i = 0; i < m; i++)
  {
    cin >> sel[i];
    sel[i]--;
    z[sel[i]] = true;
  }

  if (sel.size() == 1)
  {
    cout << "Yes\n" << str[sel[0]];
    return 0;
  }

  string ans = str[sel[0]];

  for (int i = 1; i < sel.size(); i++)
  {
    if (str[sel[i]].size() != ans.size())
    {
      cout << "No";
      return 0;
    }

    for (int j = 0; j < str[sel[i]].size(); j++)
    {
      if (ans[j] != str[sel[i]][j])
      {
        ans[j] = '?';
      }
    }
  }

  for (int i = 0; i < n; i++)
  {
    if (z[i]) continue;
    if (str[i].size() != ans.size()) continue;
    int j;
    for (j = 0; j < ans.size(); j++)
    {
      if (str[i][j] != ans[j] && ans[j] != '?') break;
    }

    if (j == ans.size())
    {
      cout << "No";
      return 0;
    }
  }

  cout << "Yes\n" << ans;
}