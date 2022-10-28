#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

int rand_int(int a, int b) {
  return uniform_int_distribution<int>(a, b)(rng);
}

using point = complex<long long>;
#define X real()
#define Y imag()

long long cross(point a, point b) {
  return a.X * b.Y - a.Y * b.X;
}

const int N = 100000 + 1;
const int B = 512;

long long c[N];
point v[N];
int n;

set<pair<int, vector<int>>> processed;
vector<array<int, 2>> ans;

void solve(vector<int> remain, int k) {
  if (remain.empty()) {
    cout << "YES\n";
    cout << ans.size() << "\n";
    for (auto [u, v] : ans) {
      cout << u << " " << v << "\n";
    }
    exit(0);
  }

  if (k == 0 || processed.count({k, remain}) > 0) {
    return;
  }
  processed.insert({k, remain});

  bool same = true;
  for (int i = 1; i < (int) remain.size(); ++i) {
    same &= (v[remain[i - 1]] == v[remain[i]]);
  }

  if (same) {
    if (k < (int) remain.size()) {
      return;
    }
    for (auto i : remain) {
      ans.push_back({i, -1});
    }
    solve(vector<int>(), 0);
  }

  for (int i = 0; i < B; ++i) {
    int a = remain[rand_int(0, remain.size() - 1)];
    int b = remain[rand_int(0, remain.size() - 1)];
    if (cross(v[a], v[b]) == 0) {
      continue;
    }

    point p = c[a] * v[b] - c[b] * v[a];

    int count = 0;
    vector<int> nxt;
    for (auto i : remain) {
      if (cross(v[i], p) == c[i] * cross(v[a], v[b])) {
        ++count;
      } else {
        nxt.push_back(i);
      }
    }

    if (count * k >= (int) remain.size()) {
      ans.push_back({a, b});
      solve(nxt, k - 1);
      ans.pop_back();
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> n >> k;

  for (int i = 1; i <= n; ++i) {
    int a, b;
    cin >> a >> b >> c[i];
    v[i] = point(-b, a);
    c[i] *= -1;
  }

  vector<int> remain(n);
  iota(remain.begin(), remain.end(), 1);

  solve(remain, k);

  cout << "NO\n";
}