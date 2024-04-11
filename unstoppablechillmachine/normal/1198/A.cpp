#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

int f(int x) {
  int res = (int)log2(x);
  while ((1 << res) < x) res++;
  return res;
}

const int N = 4e5 + 10;
int pref[N], suf[N];

signed main() {
  ios_base::sync_with_stdio(0);
  int n, k;
  cin >> n >> k;
  k *= 8;
  vector<int> srt, a(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    srt.pb(a[i]);
  }  
  sort(all(srt));
  srt.resize(unique(all(srt)) - srt.begin());
  int sz = SZ(srt);
  unordered_map<int, int> to;
  for (int i = 0; i < sz; i++) {
    to[srt[i]] = i + 1;
  }
  for (int i = 0; i < n; i++) {
    pref[to[a[i]]]++;
    suf[to[a[i]]]++;
  }
  for (int i = 2; i <= sz; i++) {
    pref[i] += pref[i - 1];
  }
  for (int i = sz - 1; i >= 1; i--) {
    suf[i] += suf[i + 1];
  }
  int mx = 1;
  while (mx < n && n * f(mx + 1) <= k) {
    mx++;
  }
  //cout << mx << '\n';
  int ans = n;
  for (int l = 1; l <= sz; l++) {
    int r = min(sz, l + mx - 1);
    ans = min(ans, pref[l - 1] + suf[r + 1]);
  }
  cout << ans << '\n';
}