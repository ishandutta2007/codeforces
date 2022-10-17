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

int ask(int a, int b) {
  cout << "? " << a << ' ' << b << endl;
  int x;
  cin >> x;
  return x;
}

void out(int a) {
  cout << "! " << a << endl;
  exit(0);
}

const int N = 1010;
vector<int> g[N];
bool ban[N];

void dfs(int v, bool sos) {
  vector<int> arr;
  for (auto u : g[v]) {
    if (!ban[u]) {
      arr.pb(u);
    }
  }
  int id = -1;
  for (int i = 0; i + 1 < SZ(arr); i += 2) {
    int res = ask(arr[i], arr[i + 1]);
    if (res != v) {
      id = res;
      break;
    }
  }
  if (SZ(arr) & 1) {
    if (id != -1) {
      ban[v] = true;
      dfs(id, false);
    }
    else {
      if (sos && SZ(arr) == 1) {
        int res = ask(v, arr.back());
        out(res);
      }
      else {
        for (int i = 0; i + 1 < SZ(arr); i++) {
          ban[arr[i]] = true;
        }
        if (SZ(arr) == 1) dfs(arr.back(), true);
        else dfs(arr.back(), false);
      }
    }
  }
  else {
    if (id == -1) {
      out(v);
    }
    else {
      ban[v] = true;
      dfs(id, false);
    }
  }
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int u, v;
    cin >> u >> v;
    g[u].pb(v);
    g[v].pb(u);
  }
  dfs(1, false);
}