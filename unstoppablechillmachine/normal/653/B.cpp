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
  int n, q;
  cin >> n >> q;
  vector<pair<pair<char, char>, char>> kek;
  for (int i = 0; i < q; i++) {
    char a, b, c;
    cin >> a >> b >> c;
    kek.pb(make_pair(make_pair(a, b), c));
  }
  vector<int> cnt(6, 1);
  for (int i = 1; i < n; i++) {
    vector<int> cnt2(6, 0);
    for (int was = 0; was < 6; was++) {
      for (int nxt = 0; nxt < 6; nxt++) {
        for (auto it : kek) {
          if (it.F.F - 'a' == was && it.F.S - 'a' == nxt) {
            cnt2[it.S - 'a'] += cnt[was];
          }
        }
      }
    }
    cnt = cnt2;
  }
  cout << cnt[0] << '\n';
}