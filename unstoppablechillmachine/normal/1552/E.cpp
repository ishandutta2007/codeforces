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
  int n, k;
  cin >> n >> k;
  vector<int> a(n * k + 1);
  for (int i = 1; i <= n * k; i++) {
    cin >> a[i];
  }
  int lim = (n + k - 2) / (k - 1);
  int cnt = 0, iter = 0;
  vector<pair<int, int>> answer(n + 1);
  vector<bool> killed(n + 1);
  //cout << lim << endl;
  while (cnt < n) {
    iter++;
    assert(iter <= lim);
    vector<int> st;
    vector<bool> used(n + 1);
    for (int i = 1; i <= n * k; i++) {
      if (killed[a[i]]) {
        continue;
      }
      if (!used[a[i]]) {
        st.pb(i);
        used[a[i]] = true;
      } else {
        while (a[st.back()] != a[i]) {
          used[a[st.back()]] = false;
          st.pop_back();
        }
        //answer.pb({st.back(), i});
        answer[a[i]] = {st.back(), i};
        killed[a[i]] = true;
        cnt++;
        for (auto it : st) {
          used[a[it]] = false;
        }
        st = {};
      }
    }
  }
  for (int i = 1; i <= n; i++) {
    cout << answer[i].F << ' ' << answer[i].S << '\n';
  }
}