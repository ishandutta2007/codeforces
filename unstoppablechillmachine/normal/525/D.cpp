#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

const int N = 2010;
char a[N][N];
bool used[N][N];
pair<int, int> p[N][N];
int L1[N][N], R1[N][N], L2[N][N], R2[N][N], sz[N][N];
pair<int, int> find(pair<int, int> v) {
  return p[v.F][v.S] == v ? v : p[v.F][v.S] = find(p[v.F][v.S]);
}

pair<int, int> merge(pair<int, int> a, pair<int, int> b) {
  a = find(a), b = find(b);
  if (a == b) {
    return a;
  }
  if (sz[a.F][a.S] < sz[b.F][b.S]) {
    swap(a, b);
  }
  p[b.F][b.S] = a;
  sz[a.F][a.S] += sz[b.F][b.S];
  L1[a.F][a.S] = min(L1[a.F][a.S], L1[b.F][b.S]);
  L2[a.F][a.S] = min(L2[a.F][a.S], L2[b.F][b.S]);
  R1[a.F][a.S] = max(R1[a.F][a.S], R1[b.F][b.S]);
  R2[a.F][a.S] = max(R2[a.F][a.S], R2[b.F][b.S]);
  return a;
}

signed main() {
  int n, m;
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      cin >> a[i][j];
    }
  }
  vector<pair<int, int>> delta = {{0, 1}, {1, 0}, {0, -1}, { -1, 0}};
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      p[i][j] = {i, j};
      sz[i][j] = 1;
      L1[i][j] = R1[i][j] = i;
      L2[i][j] = R2[i][j] = j;
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (used[i][j] || a[i][j] == '*') {
        continue;
      }
      queue<pair<int, int>> q;
      q.push({i, j});
      used[i][j] = true;
      pair<int, int> root = {i, j};
      while (!q.empty()) {
        pair<int, int> cur = q.front();
        q.pop();
        for (auto it : delta) {
          pair<int, int> to = {cur.F + it.F, cur.S + it.S};
          if (to.F >= 1 && to.F <= n && to.S >= 1 && to.S <= m) {
            if (!used[to.F][to.S]) {
              if (a[to.F][to.S] == '.') {
                used[to.F][to.S] = true;
                q.push(to);
                root = merge(root, to);
              }
              else if (to.F <= R1[root.F][root.S] && to.F >= L1[root.F][root.S] && to.S <= R2[root.F][root.S] && to.S >= L2[root.F][root.S]) {
                root = merge(root, to);
                used[to.F][to.S] = true;
                q.push(to);
              }
            }
            else if (find(to) != root) {
              swap(root, to);
              root = find(root);
              q.push({L1[root.F][root.S], L2[root.F][root.S]});
              q.push({L1[root.F][root.S], R2[root.F][root.S]});
              q.push({R1[root.F][root.S], L2[root.F][root.S]});
              q.push({R1[root.F][root.S], R2[root.F][root.S]});
              root = merge(root, to);
            }
          }
        }
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      if (used[i][j]) {
        cout << '.';
      }
      else {
        cout << '*';
      }
    }
    cout << '\n';
  }
  cerr << "TIME :: " << clock() * 1.0 / CLOCKS_PER_SEC << '\n';
}