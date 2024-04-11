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
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> st = {0};
    vector<int> a(n + 1), prv(n + 1);
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] == 1) {
        prv[i] = st.back();
      } else {
        while (a[st.back()] != a[i] - 1) {
          st.pop_back();
        }
        st.pop_back();
        prv[i] = st.back();
      }
      st.push_back(i);
    }
    auto to_string = [](int n) {
      string result;
      while (n) {
        result.push_back(char('0' + n % 10));
        n /= 10;
      }
      reverse(result.begin(), result.end());
      return result;
    };  
    vector<string> answer(n + 1);
    cout << 1 << '\n';
    answer[1] = "1";
    for (int i = 2; i <= n; i++) {
      answer[i] = (prv[i] ? answer[prv[i]] + "." + to_string(a[i]) : to_string(a[i]));
      cout << answer[i] << '\n';
    }
  }

}