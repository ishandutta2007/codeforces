#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll

const int N = 3e5 + 10;
int t[4 * N], f[4 * N];

void push(int v) {
  f[2 * v] += f[v];
  f[2 * v + 1] += f[v];
  t[2 * v] += f[v];
  t[2 * v + 1] += f[v];
  f[v] = 0;
}

void update(int v, int l, int r, int a, int b, int delta) {
  if (l > b || r < a) {
    return;
  }
  if (l >= a && r <= b) {
    t[v] += delta;
    f[v] += delta;
    return;
  }
  push(v);
  int mid = (l + r) / 2;
  update(2 * v, l, mid, a, b, delta);
  update(2 * v + 1, mid + 1, r, a, b, delta);
  t[v] = min(t[2 * v], t[2 * v + 1]);
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int n;
  cin >> n;
  vector<int> pos(n + 1);
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    pos[x] = n - i + 1;
  }
  int ptr = n;
  for (int i = 1; i <= n; i++) {
    cout << ptr << ' ';
    int x;
    cin >> x;
    x = n - x + 1;
    update(1, 1, n, x, n, 1);
    for (;;) {
      update(1, 1, n, pos[ptr], n, -1);
      if (t[1] < 0) {
        update(1, 1, n, pos[ptr], n, 1);
        break;
      }
      else {
        ptr--;
      }
    }
  }
}