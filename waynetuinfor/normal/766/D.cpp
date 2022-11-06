#include <bits/stdc++.h>
using namespace std;

const int maxn = 200000 + 5;
map<string, int> m;
int N, M, Q, djs[maxn << 1], k;
string s, t;

int F(int);
void U(int, int);

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  for (int i = 0; i < maxn * 2; ++i) djs[i] = i;
  cin >> N >> M >> Q;
  for (int i = 0; i < N; ++i) cin >> s, m[s] = i;
  while (M--) {
    cin >> k >> s >> t;
    int a = m[s], b = m[t];
    if (k == 1) {
      if (F(a) == F(b + maxn) || F(b) == F(a + maxn)) { cout << "NO\n"; continue; }
      cout << "YES\n";
      U(a, b); U(a + maxn, b + maxn);
    }
    if (k == 2) {
      if (F(a) == F(b) || F(a + maxn) == F(b + maxn)) { cout << "NO\n"; continue; }
      cout << "YES\n";
      U(a, b + maxn); U(b, a + maxn);
    }
  }
  while (Q--) {
    cin >> s >> t;
    int a = m[s], b = m[t];
    if (F(a) == F(b) && F(a + maxn) == F(b + maxn)) cout << "1\n";
    else if (F(a) == F(b + maxn) && F(b) == F(a + maxn)) cout << "2\n";
    else cout << "3\n";
  }
  return 0;
}

int F(int x) { return x == djs[x] ? x : djs[x] = F(djs[x]); }

void U(int x, int y) {
  x = F(x); y = F(y);
  djs[x] = y;
}