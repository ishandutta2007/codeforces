#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 1010;
int pref[N][N], h[N][N], val[N][N];

int get_sum(int a, int b, int a2, int b2) {
  return pref[a2][b2] - pref[a - 1][b2] - pref[a2][b - 1] + pref[a - 1][b - 1];
}

multiset<int> cur[N];

bool used[N][N];

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n, m, a, b;
  cin >> n >> m >> a >> b;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> h[i][j];
      pref[i][j] = pref[i][j - 1] + h[i][j];
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      pref[i][j] += pref[i - 1][j];
    }
  }
  for (int j = 1; j <= m; j++) {
    for (int i = 1; i <= a; i++) {
      cur[j].insert(h[i][j]);
    }
  }
  for (int i = 1; i + a - 1 <= n; i++) {
    multiset<int> st;
    for (int j = 1; j <= b; j++) {
      st.insert(*cur[j].begin());
    }
    val[i][1] = *st.begin();
    for (int j = 2; j + b - 1 <= m; j++) {
      st.erase(st.find(*cur[j - 1].begin()));
      st.insert(*cur[j + b - 1].begin());
      val[i][j] = *st.begin();
    }
    if (i + a <= n) {
      for (int j = 1; j <= m; j++) {
        cur[j].erase(cur[j].find(h[i][j]));
        cur[j].insert(h[i + a][j]);
      }
    }
  }
  vector<pair<int, pair<int, int>>> kek, rez;
  for (int i = 1; i + a - 1 <= n; i++) {
    for (int j = 1; j + b - 1 <= m; j++) {
      int flex = get_sum(i, j, i + a - 1, j + b - 1) - a * b * val[i][j];
      kek.pb(make_pair(flex, make_pair(i, j)));
    }
  }
  sort(all(kek)); 
  for (auto it : kek) {
    int i = it.S.F, j = it.S.S, cost = it.F;
    if (!used[i][j]) {
      rez.pb(it);
      pair<int, int> kek1 = {i - a + 1, j - b + 1}, kek2 = {i + a - 1, j + b - 1};
      for (int i = kek1.F; i <= kek2.F; i++) {
        for (int j = kek1.S; j <= kek2.S; j++) {
          if (i >= 1 && j >= 1 && i <= n && j <= m) {
            used[i][j] = true;
          }
        }
      }
    }
  }
  cout << SZ(rez) << '\n';
  for (auto it : rez) {
    cout << it.S.F << ' ' << it.S.S << ' ' << it.F << '\n';
  }
}