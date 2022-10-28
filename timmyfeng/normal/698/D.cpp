#include <bits/stdc++.h>
using namespace std;

using point = complex<long long>;
#define X real()
#define Y imag()

long long cross(point u, point v) {
  return u.X * v.Y - u.Y * v.X;
}

long long dot(point u, point v) {
  return u.X * v.X + u.Y * v.Y;
}

const int N = 1000;
const int K = 7;

point teleport[K], monster[N];
vector<int> segment[K][N];
vector<int> out;
int k;

void merge(vector<int> &a, vector<int> &b) {
  vector<int> c;
  c.reserve(a.size() + b.size());
  set_union(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
  a = c;
}

void unmerge(vector<int> &a, vector<int> &b) {
  vector<int> c;
  c.reserve(a.size());
  set_difference(a.begin(), a.end(), b.begin(), b.end(), back_inserter(c));
  a = c;
}

bool check(int mask, vector<int> targets) {
  int m1 = __builtin_popcount(mask);
  int m2 = targets.size();

  if (m2 == 0) {
    return true;
  } else if (m2 > m1) {
    return false;
  }

  merge(out, targets);

  for (int i = 0; i < (1 << k); ++i) {
    if (__builtin_popcount(i) == m2 && (mask & i) == i) {
      vector<int> order;
      for (int j = 0; j < k; ++j) {
        if ((i & (1 << j)) > 0) {
          order.push_back(j);
        }
      }

      do {
        vector<int> blocking;
        for (int j = 0; j < m2; ++j) {
          merge(blocking, segment[order[j]][targets[j]]);
        }

        unmerge(blocking, out);

        if (check(mask ^ i, blocking)) {
          return true;
        }
      } while (next_permutation(order.begin(), order.end()));
    }
  }

  unmerge(out, targets);
  return false;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> k >> n;

  for (int i = 0; i < k; ++i) {
    int x, y;
    cin >> x >> y;
    teleport[i] = point(x, y);
  }

  for (int i = 0; i < n; ++i) {
    int x, y;
    cin >> x >> y;
    monster[i] = point(x, y);
  }

  for (int i = 0; i < k; ++i) {
    for (int a = 0; a < n; ++a) {
      point u = monster[a] - teleport[i];
      for (int b = 0; b < n; ++b) {
        point v = monster[b] - teleport[i];
        if (cross(u, v) == 0 && dot(u, v) > 0 && norm(v) < norm(u)) {
          segment[i][a].push_back(b);
        }
      }
    }
  }

  int ans = 0;
  for (int i = 0; i < n; ++i) {
    out.clear();
    ans += check((1 << k) - 1, {i});
  }

  cout << ans << "\n";
}