#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
//#define int ll
#define F first
#define S second

map<pair<int, int>, vector<pair<int, int>>> mp1;
map<int, vector<pair<int, int>>> mp2;
vector<pair<int, int>> ost;
signed main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  cout.tie(0);
  int n;
  cin >> n;
  for (int i =0 ; i < n; i++) {
    int x, y, z;
    cin >> x >> y >> z;
    mp1[{x, y}].pb({z, i + 1});
  }

  for (auto &it : mp1) {
    sort(all(it.S));
    for (int i = 0; i + 1 < SZ(it.S); i += 2) {
      cout << it.S[i].S << ' ' << it.S[i + 1].S << '\n';
    }
    if (SZ(it.S) & 1) {
      mp2[it.F.F].pb({it.F.S, it.S.back().S});
    }
  }

  for (auto &it : mp2) {
    sort(all(it.S));
    for (int i = 0; i + 1 < SZ(it.S); i += 2) {
      cout << it.S[i].S << ' ' << it.S[i + 1].S << '\n';
    }
    if (SZ(it.S) & 1) {
      ost.pb({it.F, it.S.back().S});
    }
  }

  sort(all(ost));
  for (int  i= 0; i < SZ(ost); i += 2) {
    cout << ost[i].S << ' ' << ost[i + 1].S << '\n';
  }
}