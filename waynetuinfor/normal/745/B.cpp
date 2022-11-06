#include <iostream>
#include <string>
using namespace std;

const int MAXN = 500 + 5;
string rec[MAXN];
int n, m, sti, stj, edi, edj, h, w, u, d, l, r;
bool found;

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> m;
  for (int i = 0; i < n; ++i) cin >> rec[i];
  u = 501, d = -1, l = 501, r = -1;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      if (rec[i][j] == 'X') {
        u = min(u, i);
        d = max(d, i);
        l = min(l, j);
        r = max(r, j);
      }
    }
  }
  for (int i = u; i <= d; ++i) for (int j = l; j <= r; ++j) if (rec[i][j] == '.') { cout << "NO\n"; return 0; }
  cout << "YES\n";
  return 0;
}