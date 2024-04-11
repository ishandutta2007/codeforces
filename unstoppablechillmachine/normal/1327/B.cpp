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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<bool> used(n + 1);
    int id = -1;
    for (int i = 1; i <= n; i++) {
      int cnt;
      cin >> cnt;
      bool ok = false;
      for (int j = 0; j < cnt; j++) {
        int x;
        cin >> x;
        if (!ok && !used[x]) {
          ok = true;
          used[x] = true;
        }
      }
      if (!ok) {
        id = i;
      }
    }
    int id2 = -1;
    for (int i = 1; i <= n; i++) {
      if (!used[i]) {
        id2 = i;
      }
    }
    if (id != -1) {
      cout << "IMPROVE\n" << id << ' ' << id2 << '\n';
    }
    else {
      cout << "OPTIMAL\n";
    }
  }  
}