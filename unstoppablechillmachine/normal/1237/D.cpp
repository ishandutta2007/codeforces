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

const int INF = 1e9 + 10;

struct ST {
  vector<int> t, arr;
  ST(int n, vector<int> a) {
    t.resize(4 * n + 10);
    arr = a;
    build(1, 1, n);
  }
  void build(int v, int l, int r) {
    if (l == r) {
      t[v] = arr[l];
      return;
    }
    int mid = (l + r) / 2;
    build(2 * v, l, mid);
    build(2 * v + 1, mid + 1, r);
    t[v] = max(t[2 * v], t[2 * v + 1]);
  }
  int getLeft(int v, int l, int r, int a, int b, int mn) {
    if (l > b || r < a) {
      return INF;
    }
    if (l >= a && r <= b) {
      /*if (mn == 1) {
        cout << "DEBUG " << l << ' ' << r << '\n';
      }*/
      while (l != r) {
        if (t[2 * v] >= mn) {
          r = (l + r) / 2;
          v *= 2;
        }
        else {
          l = (l + r) / 2 + 1;
          v = v * 2 + 1;
        }
      }
      /*if (mn == 1) {
        cout << "DEBUG " << l << ' ' << t[v] << '\n';
      }*/
      if (t[v] < mn) {
        return INF;
      }
      return l;
    }
    int mid = (l + r) / 2;
    return min(getLeft(2 * v, l, mid, a, b, mn), getLeft(2 * v + 1, mid + 1, r, a, b, mn));
  }

  int getRight(int v, int l, int r, int a, int b, int mn) {
    if (l > b || r < a) {
      return -INF;
    }
    if (l >= a && r <= b) {
      while (l != r) {
        if (t[2 * v + 1] >= mn) {
          l = (l + r) / 2 + 1;
          v = v * 2 + 1;
        }
        else {
          r = (l + r) / 2;
          v *= 2;
        }
      }
      if (t[v] < mn) {
        return -INF;
      }
      return l;
    }
    int mid = (l + r) / 2;
    return max(getRight(2 * v, l, mid, a, b, mn), getRight(2 * v + 1, mid + 1, r, a, b, mn)); 
  }
};

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  vector<int> a(3 * n + 1);
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
  }
  for (int i = n + 1; i <= 3 * n; i++) {
    a[i] =  a[i - n];
  }
  ST tree1(3 * n, a);
  vector<int> lf(3 * n + 1);
  for (int i = 1; i <= 3 * n; i++) {
    lf[i] = tree1.getRight(1, 1, 3 * n, 1, i - 1, 2 * a[i] + 1);
    //cout << lf[i] << ' ';
  }

  //cout << '\n' << '\n';
  ST tree2(3 * n, lf);
  vector<int> ans(n + 1);
  for (int i = 1; i <= n; i++) {
    ans[i] = tree2.getLeft(1, 1, 3 * n, i, 3 * n, i);
    if (ans[i] != INF) {
      ans[i] = ans[i] - i;
    }
  }
  for (int i = 1; i <= n; i++) {
    if (ans[i] == INF) {
      cout << -1 << ' ';
    }
    else {
      cout << ans[i] << ' ';
    }
  }
  cout << '\n';
}