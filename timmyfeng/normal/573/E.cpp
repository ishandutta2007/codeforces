#include <bits/stdc++.h>
using namespace std;

const int N = 100000;
const int B = 256;

long long floor_div(long long a, long long b) {
  return a / b - (a % b < 0);
}

struct line {

  long long m, b;
  int i;

  long long intersect(line oth) {
    return floor_div(oth.b - b, m - oth.m);
  }

  long long evaluate(long long x) {
    return m * x + b;
  }

};

long long slope[N], offset[N];
bool used[N];
int order[N];

void build(vector<line> &hull, int l, int r) {
  hull.clear();
  for (int i = l; i < r; ++i) {
    if (used[order[i]]) {
      continue;
    }

    line l = {slope[order[i]], offset[order[i]], order[i]};

    if (!hull.empty() && hull.back().m == l.m) {
      if (hull.back().b < l.b) {
        hull.pop_back();
      } else {
        continue;
      }
    }

    while (hull.size() >= 2 && hull.back().intersect(l) >= hull[hull.size() - 2].intersect(hull.back())) {
      hull.pop_back();
    }

    hull.push_back(l);
  }
}

pair<long long, int> query(vector<line> &hull, long long x) {
  if (hull.empty()) {
    return {LLONG_MIN, -1};
  }

  while (hull.size() >= 2 && hull.back().evaluate(x) < hull[hull.size() - 2].evaluate(x)) {
    hull.pop_back();
  }

  return {hull.back().evaluate(x), hull.back().i};
}

long long prefix[N], suffix[N];
vector<line> hull[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> slope[i];
  }

  iota(order, order + n, 0);
  for (int i = 0; i <= (n - 1) / B; ++i) {
    sort(order + B * i, order + min(n, B * (i + 1)), [&](int a, int b) {
      return slope[a] > slope[b];
    });
    build(hull[i], B * i, min(n, B * (i + 1)));
  }

  long long ans = 0, score = 0;
  for (int i = 0; i < n; ++i) {
    pair<long long, int> best = {LLONG_MIN, -1};
    for (int j = 0; j <= (n - 1) / B; ++j) {
      pair<long long, int> block = query(hull[j], prefix[j] + 1);
      if (block.first > LLONG_MIN) {
        block.first += suffix[j];
      }
      best = max(best, block);
    }

    int u = best.second, v = u / B;
    score += best.first;
    ans = max(ans, score);
    used[u] = true;

    for (int j = B * v; j < min(n, B * (v + 1)); ++j) {
      if (j < u) {
        offset[j] += slope[u];
      } else if (j > u) {
        offset[j] += slope[j];
      }
    }
    build(hull[v], B * v, min(n, B * (v + 1)));

    for (int j = 0; j <= (n - 1) / B; ++j) {
      if (j < v) {
        suffix[j] += slope[u];
      } else if (j > v) {
        ++prefix[j];
      }
    }
  }

  cout << ans << "\n";
}