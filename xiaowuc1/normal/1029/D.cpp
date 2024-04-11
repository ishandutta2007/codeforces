#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll l[200005];
int len[200005];
map<ll, int> dp[15];
int n;
ll k;
ll tenPow[15];

void solve() {
  cin >> n >> k;
  tenPow[0] = 1;
  for(int i = 1; i <= 11; i++) {
    tenPow[i] = (tenPow[i-1] * 10) % k;
  }
  for(int i = 0; i < n; i++) {
    string s;
    cin >> s;
    len[i] = s.size();
    for(int a = 0; a < len[i]; a++) {
      l[i] *= 10;
      l[i] += s[a] - '0';
    }
    dp[len[i]][l[i]%k]++;
  }
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    ll cand = l[i] * tenPow[len[i]] + l[i];
    if(cand % k == 0) ret--;
  }
  for(int i = 0; i < n; i++) {
    ll curr = l[i];
    for(int a = 1; a <= 11; a++) {
      curr *= 10;
      curr %= k;
      ll need = (k - curr) % k;
      if(dp[a].count(need)) {
        ret += dp[a][need];
      }
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}