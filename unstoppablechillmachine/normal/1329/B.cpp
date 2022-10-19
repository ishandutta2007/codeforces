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

int mod;
int cnt[40], dp[40][40];

void add(int &a, int b) {
  a = (a + b) % mod;
}

int mult(int a, int b) {
  return (a * 1ll * b) % mod;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
	int T;
  cin >> T;
  while (T--) {
    int d;
    cin >> d >> mod;
    int mx_bit = 0;
    while ((1 << (mx_bit + 1)) <= d) {
      mx_bit++;
    }
    for (int i = 0; i < 40; i++) {
      cnt[i] = 0;
      for (int j = 0; j < 40; j++) {
        dp[i][j] = 0;
      }
    }
    for (int bit = 0; bit <= mx_bit; bit++) {
      cnt[bit] = (bit == mx_bit ? d - (1 << (mx_bit)) + 1 : (1 << bit));
      //cout << bit << ' ' << cnt[bit] << '\n';
    }
    int ans = 0;
    for (int i = 0; i <= mx_bit; i++) {
      dp[1][i] = cnt[i];
      add(ans, dp[1][i]);
    }
    for (int i = 2; i <= mx_bit + 1; i++) {
      for (int was = 0; was < mx_bit; was++) {
        for (int to = was + 1; to <= mx_bit; to++) {
          add(dp[i][to], mult(dp[i - 1][was], cnt[to]));
        }
      }
      for (int to = 0; to <= mx_bit; to++) {
        add(ans, dp[i][to]);
      }
    }
    cout << ans << '\n';
  }
}