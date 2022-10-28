#include <bits/stdc++.h>
using namespace std;

const int N = 1000000 + 2;
const int M = 1000000007;
const int A = 26;

void add(int &a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
}

int series_link[N], series[N], diff[N];
int link[N], length[N], to[N][A];
string t;

int get(int u, int i) {
  while (true) {
    int j = i - 1 - length[u];
    if (j >= 0 && t[j] == t[i]) {
      break;
    }
    u = link[u];
  }
  return u;
}

int ways[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  for (int i = 0; i < n / 2; ++i) {
    t += s[i], t += s[n - 1 - i];
  }

  int u = 0, m = 2;
  length[1] = -1;
  link[0] = 1;

  ways[0] = 1;

  for (int i = 0; i < n; ++i) {
    u = get(u, i);
    if (to[u][t[i] - 'a'] == 0) {
      length[m] = length[u] + 2;
      link[m] = to[get(link[u], i)][t[i] - 'a'];

      diff[m] = length[m] - length[link[m]];
      if (diff[m] == diff[link[m]]) {
        series_link[m] = series_link[link[m]];
      } else {
        series_link[m] = link[m];
      }

      to[u][t[i] - 'a'] = m++;
    }
    u = to[u][t[i] - 'a'];

    for (int v = u; length[v] > 0; v = series_link[v]) {
      series[v] = ways[i + 1 - length[series_link[v]] - diff[v]];
      if (diff[v] == diff[link[v]]) {
        add(series[v], series[link[v]]);
      }
      add(ways[i + 1], series[v]);
    }

    if (i % 2 == 0) {
      ways[i + 1] = 0;
    }
  }

  cout << ways[n] << "\n";
}