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

int f(int x, int parts) {
  int dv = x / parts;
  int c2 = x % parts, c1 = parts - c2;
  return dv * dv * c1 + (dv + 1) * (dv + 1) * c2;
}

signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int n, k;
  cin >> n >> k;
  vector<int> a(n), cnt(n);
  int ans = 0;
  set<pair<int, int>> st; 
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    ans += a[i] * a[i];
    cnt[i] = 1;
    st.insert({f(a[i], 2) - f(a[i], 1), i});
  }
  for (int i = 0; i < k - n; i++) {
    int id = st.begin()->S;
    st.erase(st.begin());
    ans += f(a[id], cnt[id] + 1) - f(a[id], cnt[id]);
    cnt[id]++;
    st.insert({f(a[id], cnt[id] + 1) - f(a[id], cnt[id]), id});
  }
  cout << ans << '\n';
}