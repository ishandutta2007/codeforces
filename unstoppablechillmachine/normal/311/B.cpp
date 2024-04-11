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

const int INF = 1e9 + 10;

struct line {
  int k, b;
  line() : k(INF), b(INF) {};
  line(int k, int b) : k(k), b(b) {};
  int get(int x) {
    return k * x + b;
  }
  int inter(line l) {
    return (b - l.b) / (l.k - k);
  }
};

struct CHT {
  vector<int> from;
  vector<line> have;
  int ptr;
  CHT() {
    from.pb(-INF);
    have.pb(line());
    ptr = 0;
  }
  void add_line(line nl) {
    while (SZ(have) > 1) {
      int cur = nl.inter(have.back());
      if (cur < from.back()) {
        have.pop_back();
        from.pop_back();
      }
      else {
        break;  
      }
    }
    from.pb(nl.inter(have.back()));
    have.pb(nl);
  }
  int get(int x) {
    ptr = min(ptr, SZ(have) - 1);
    while (ptr + 1 < SZ(have) && have[ptr + 1].get(x) <= have[ptr].get(x)) {
      ptr++;
    }
    return have[ptr].get(x);
  }
};

const int N = 1e5 + 10;
const int M = 110;
int dp[N][M], arr[N], d[N], pref[N];

signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n, m, p;
  cin >> n >> m >> p;
  for (int i = 2; i <= n; i++) {
    cin >> d[i];
    d[i] += d[i - 1];
  }
  dp[0][0] = 0;
  for (int i = 1; i <= n; i++) {
    dp[i][0] = INF;
  }
  for (int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    arr[i] = b + d[n] - d[a];
    pref[i] = pref[i - 1] + arr[i]; 
  }
  sort(arr + 1, arr + m + 1);
  for (int i = 1; i <= m; i++) {
    dp[i][1] = arr[i] * i - pref[i];
  }
  for (int i = 2; i <= p; i++) {
    CHT kek;
    kek.add_line(line(0, 0));
    for (int j = 1; j <= m; j++) {
      dp[j][i] = kek.get(arr[j]) + arr[j] * j - pref[j];
      kek.add_line(line(-j, dp[j][i - 1] + pref[j]));
    }
  }
  cout << dp[m][p] << '\n';
}