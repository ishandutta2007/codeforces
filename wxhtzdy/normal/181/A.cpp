#include <bits/stdc++.h>

using namespace std;

/*
   ko zeli da nauci kako se rade 800 zadaci neka gleda stream na yt koji ce biti soon
*/

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, m;
  cin >> n >> m;
  vector<string> s(n);
  for (int i = 0; i < n; i++)
    cin >> s[i];
  vector<int> row(n);
  vector<int> col(m);
  for (int i = 0; i < n; i++)
    for (int j = 0; j < m; j++)
      if (s[i][j] == '*')
        row[i]++, col[j]++;
  int ans_x, ans_y;
  for (int i = 0; i < n; i++)
    if (row[i] & 1)
      ans_x = i;
  for (int i = 0; i < m; i++)
    if (col[i] & 1)
      ans_y = i;
  cout << ans_x + 1 << " " << ans_y + 1 << '\n';
  return 0;
}