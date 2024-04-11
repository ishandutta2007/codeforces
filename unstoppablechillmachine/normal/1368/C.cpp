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
  int n;
  cin >> n;
  set<pair<int, int>> st;
  for (int i = 0; i <= n; i++) {
    st.insert({i, i});
    st.insert({i + 1, i});
    st.insert({i, i + 1});
    st.insert({i + 1, i + 1});
  }
  cout << SZ(st) << '\n';
  for (auto it : st) {
    cout << it.F << ' ' << it.S << '\n';
  }
}