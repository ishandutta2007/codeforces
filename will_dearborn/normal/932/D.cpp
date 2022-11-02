#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<ll> vi;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;
typedef vector<pii> vii;
typedef vector<string> vs;
//const int mod = ;

const int B = 19;
int pr[500000][B];
int ma[500000][B];
int nx[500000][B];
ll sum[500000][B];
int len[500000][B];
int w[500000];

int main() {
  std::ios::sync_with_stdio(false); std::cin.tie(0);
  int T;
  cin >> T;
  ll last = 0;
  int cnt = 1;
  for (int test = 0; test < T; ++test) {
    int type;
    ll p, q;
    cin >> type >> p >> q;
    if (type == 1) {
      ll r = (p ^ last) - 1, W = q ^ last;
//      cerr << cnt << ' ' << r << ' ' << W << endl;
      w[cnt] = W;
      pr[cnt][0] = r;
      ma[cnt][0] = w[r];
      for (int b = 1; b < B; ++b) {
        int p1 = pr[cnt][b-1];
        pr[cnt][b] = pr[p1][b-1];
        ma[cnt][b] = max(ma[cnt][b-1], ma[p1][b-1]);
      }
      if (ma[cnt][B-1] < W) {
        for (int b = 0; b < B; ++b) nx[cnt][b] = cnt;
      } else {
        int cur = cnt;
        for (int b = B - 1; b >= 0; --b) {
          if (ma[cur][b] < W) cur = pr[cur][b];
        }
        nx[cnt][0] = pr[cur][0];
        sum[cnt][0] = w[nx[cnt][0]];
        len[cnt][0] = 1;
        assert(w[nx[cnt][0]] >= W);
        for (int b = 1; b < B; ++b) {
          int p1 = nx[cnt][b-1];
          nx[cnt][b] = nx[p1][b-1];
          sum[cnt][b] = sum[cnt][b-1] + sum[p1][b-1];
          len[cnt][b] = len[cnt][b-1] + len[p1][b-1];
        }
      }
      ++cnt;
    } else {
      ll r = (p ^ last) - 1, X = q ^ last;
//      cerr << r << ' ' << X << endl;
      if (X < w[r]) {
        last = 0;
        cout << 0 << endl; continue;
      }
      X -= w[r];
      int res = 1, cur = r;
      for (int b = B - 1; b >= 0; --b) {
        if (sum[cur][b] <= X) {
          X -= sum[cur][b];
          res += len[cur][b];
          cur = nx[cur][b];
        }
      }
      last = res;
      cout << res << endl;
    }
  }
  return 0;
}