#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
typedef long long ll;
typedef pair<double, double> pdd;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef pair<int, int> pii;
typedef vector<pii> vii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;
//const int mod = ;

int d[26][26];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int n;
  cin >> n;
  vs s(n);
  bool fail = 0;
  const int INF = 1e9;
  for (int i = 0; i < 26; ++i) {
    for (int j = 0; j < 26; ++j) d[i][j] = INF;
  }
  for (int i = 0; i < n; ++i) {
    cin >> s[i];
    vi c(26);
    for (auto& j : s[i]) {
      j -= 'a';
      ++c[j];
    }
    for (int j = 0; j < 26; ++j) if (c[j] > 1) fail = 1;
    for (int j1 = 0; j1 < s[i].size(); ++j1) for (int j2 = 0; j2 < s[i].size(); ++j2) {
      int a1 = s[i][j1], a2 = s[i][j2];
      if (d[a1][a2] == INF) d[a1][a2] = j2 - j1;
      else if (d[a1][a2] != j2 - j1) fail = 1;
    }
  }
  for (int t = 0; t < 100; ++t) for (int a = 0; a < 26; ++a) for (int b = 0; b < 26; ++b) for (int c = 0; c < 26; ++c) {
    if (d[a][b] != INF && d[b][c] != INF) {
      int sum = d[a][b] + d[b][c];
      if (d[a][c] == INF) d[a][c] = sum;
      else if (d[a][c] != sum) fail = 1;
    }
  }
  for (int i = 0; i < 26; ++i) for (int j = i + 1; j < 26; ++j) if (d[i][j] == 0) fail = 1;
  if (fail) {
    cout << "NO\n"; return 0;
  }
  vi was(26);
  vs all;
  for (int i = 0; i < 26; ++i) if (d[i][i] == 0 && !was[i]) {
    vii ts;
    for (int j = 0; j < 26; ++j) if (d[i][j] != INF) {
      was[j] = 1;
      ts.emplace_back(d[i][j], j);
    }
    sort(ts.begin(), ts.end());
    string s = "";
    for (pii p : ts) {
      s += (char)(p.second + 'a');
    }
    all.push_back(s);
  }
  sort(all.begin(), all.end());
  string res = "";
  for (string s : all) res += s;
  cout << res << endl;
  return 0;
}