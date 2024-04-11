#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;

#define fst first
#define snd second
#define x first
#define y second
#define sz(x) (int)((x).size())
#define all(x) (x).begin(), (x).end()
#define dbg(x) cerr << #x << ": " << (x) << endl;
#define ints(args...) int args; readln(args);
#define lls(args...) ll args; readln(args);

template<typename... Args>
void readln(Args&... args) { ((cin >> args), ...); }
template<typename... Args>
void writeln(Args... args) { ((cout << args << " "), ...); cout << '\n'; }

const int INF = 1e9;
const int MN = 200 + 5;

int D[MN][MN];
int ans[MN];
int depth[MN];
int vis[MN];

bool dfs(int n, int d, int N) {
  vis[n] = 1;
  depth[n] = d;
  for(int j = 0; j < N; j++) {
    if (n == j || D[n][j] == INF) continue;
    if (vis[j]) {
      if (((depth[j]&1) != ((d+1)&1))) {
        return true;
      }
      continue;
    }
    if (dfs(j, d+1, N)) return true;
  }
  return false;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  ints(N, M);
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      D[i][j] = INF;
    }
    D[i][i] = 0;
  }

  for(int i = 0; i < M; i++) {
    ints(a, b, c); a--, b--;
    if (c == 0) {
      D[a][b] = D[b][a] = 1;
    }
    else {
      D[a][b] = 1;
      D[b][a] = -1;
    }
  }

  if (dfs(0, 0, N)) {
    writeln("NO");
    return 0;
  }

  for(int k = 0; k < N; k++) {
    for(int i = 0; i < N; i++) {
      for(int j = 0; j < N; j++) {
        if (i == k || k == j || i == j) continue;

        D[i][j] = min(D[i][j], D[i][k] + D[k][j]);
      }
    }
  }

  int maxd = 0;
  int lo = 0, hi = 0;
  for(int i = 0; i < N; i++) {
    for(int j = 0; j < N; j++) {
      if (i == j) continue;
      if (D[i][j] + D[j][i] < 0) {
        writeln("NO");
        return 0;
      }

      if (maxd < D[i][j]) {
        maxd = D[i][j];
        lo = i, hi = j;
      }
    }
  }

  for(int i = 0; i < N; i++) {
    ans[i] = D[lo][i];
  }
  writeln("YES");
  writeln(maxd);
  for(int i = 0; i < N; i++) {
    cout << ans[i] << ' ';
  }
  writeln("");
  return 0;
}