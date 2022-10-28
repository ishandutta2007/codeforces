#include <bits/stdc++.h>
using namespace std;

using point = complex<double>;
#define x real()
#define y imag()

const int N = 3;
const double E = 1e-12;

point rotate90(point u) {
  return {-u.y, u.x};
}

struct cmp {
  bool operator()(point u, point v) {
    if (abs(u.x - v.x) < E) {
      return u.y + E < v.y;
    }
    return u.x + E < v.x;
  }
};

struct circle {
  point o;
  int r;
} circles[N];

vector<int> adj[N];
bool visited[N];

vector<point> intersect(circle u, circle v) {
  double d = norm(v.o - u.o);
  if (d + E < (v.r - u.r) * (v.r - u.r) || d - E > (v.r + u.r) * (v.r + u.r)) {
    return {};
  }
  d = sqrt(d);

  double a = (u.r * u.r - v.r * v.r + d * d) / (2 * d);
  double h = sqrt(u.r * u.r - a * a);

  point center = u.o + (v.o - u.o) / d * a;
  point delta = rotate90(v.o - u.o) / d * h;

  if (norm(delta) < E) {
    return {center};
  }
  return {center - delta, center + delta};
}

void dfs(int u) {
  visited[u] = true;
  for (int c : adj[u]) {
    if (!visited[c]) {
      dfs(c);
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    int xx, yy;
    cin >> xx >> yy >> circles[i].r;
    circles[i].o = point(xx, yy);
  }

  int ans = 1;
  set<point, cmp> all;
  for (int i = 0; i < n; ++i) {
    set<point, cmp> cur;
    for (int j = 0; j < n; ++j) {
      if (j != i) {
        vector<point> points = intersect(circles[i], circles[j]);
        for (point k : points) {
          cur.insert(k);
          all.insert(k);
        }
        if (!points.empty()) {
          adj[i].push_back(j);
        }
      }
    }
    ans += cur.size();
  }
  ans -= all.size();

  for (int i = 0; i < n; ++i) {
    if (!visited[i]) {
      dfs(i);
      ++ans;
    }
  }

  cout << ans << "\n";
}