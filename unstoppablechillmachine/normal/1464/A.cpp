#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

const int N = 1e5 + 10;
int sz[N], p[N];

int find(int v) {
  return p[v] == v ? v : p[v] = find(p[v]);
}

bool merge(int a, int b) {
  a = find(a), b = find(b);
  if (a == b) {
    return false;
  }
  if (sz[a] < sz[b]) {
    swap(a, b);
  }
  sz[a] += sz[b];
  p[b] = a;
  return true;
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
      p[i] = i;
      sz[i] = 1;
    }
    int ans = k;
    for (int i = 1; i <= k; i++) {
      int a, b;
      cin >> a >> b;
      if (a == b) {
        ans--;
        continue;
      }
      if (!merge(a, b)) {
        ans++;
      }
    }
    cout << ans << '\n';
  }
}