#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  string s;
  cin >> n >> m >> s;

  string perm(26, 0);
  iota(perm.begin(), perm.end(), 'a');

  while (m--) {
    char a, b;
    cin >> a >> b;
    int x = find(perm.begin(), perm.end(), a) - perm.begin();
    int y = find(perm.begin(), perm.end(), b) - perm.begin();
    swap(perm[x], perm[y]);
  }

  for (auto c : s) {
    cout << perm[c - 'a'];
  }
  cout << "\n";
}