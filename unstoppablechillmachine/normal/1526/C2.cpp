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
  multiset<int> st;
  int sum = 0;
  for (int i = 1; i <= n; i++) {
    int x;
    cin >> x;
    if (sum + x >= 0) {
      st.insert(x);
      sum += x;
    }
    else {
      if (!st.empty() && *st.begin() < x) {
        sum += x - *st.begin();
        st.erase(st.begin());
        st.insert(x);
      }
    }
  }
  cout << SZ(st) << '\n';
}