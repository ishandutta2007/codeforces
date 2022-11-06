#include <iostream>
#include <algorithm>
using namespace std;

const int MAXN = 100000 + 5;
int n, a, b, k, Max, Min, cnt;
char M, m, ans[MAXN];

int main() {
  cin.tie(0); ios_base::sync_with_stdio(false);
  cin >> n >> k >> a >> b;
  if (a > b) Max = a, Min = b, M = 'G', m = 'B';
  else Max = b, Min = a, M = 'B', m = 'G';
  if (Min == 0) {
    if (k < n) { cout << "NO\n"; return 0; }
    else for (int i = 0; i < Max; ++i) cout << M;
    return 0;
  }
  if (Max / (Min + 1) + (Max % (Min + 1) > 0) > k) { cout << "NO\n"; return 0; }
  cnt = 0;
  for (int i = 0; i < Min + 1; ++i) {
    if (cnt < Max % (Min + 1)) {
      cnt++;
      for (int j = 0; j < (Max / (Min + 1)) + 1; ++j) cout << M;
    }
    else for (int j = 0; j < (Max / (Min + 1)); ++j) cout << M;
    if (i < Min) cout << m;
  }
  return 0;
}