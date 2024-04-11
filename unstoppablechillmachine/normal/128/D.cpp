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

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  map<int, int> cnt;
  for (int i = 0; i < n; i++) {
    int x;
    cin >> x;
    cnt[x]++;
  }
  int cur = cnt.begin()->F, beg = cur;
  cnt[cur]--;
  for (int i = 1; i < n; i++) {
    if (cnt[cur + 1] > 0) {
      cur++;
      cnt[cur]--;
    }
    else if (cnt[cur - 1] > 0) {
      cur--;
      cnt[cur]--;
    }
    else {
      cout << "NO\n";
      exit(0);
    }
  }
  cout << (cur == beg + 1 ? "YES\n" : "NO\n");
}