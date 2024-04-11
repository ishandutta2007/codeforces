#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
//#define int ll

signed main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
  int n;
  cin >> n;
  cout << "? " << 1 << ' ' << n << endl;
  multiset<string> st;
  for (int i = 1; i <= n * (n + 1) / 2; i++) {
    string s;
    cin >> s;
    sort(all(s));
    st.insert(s);
  }
  if (n == 1) {
    cout <<"! " << *st.begin() << endl;
    exit(0);
  }  
  cout << "? " << 2 << ' ' << n << endl;
  for (int i = 1; i <= n * (n - 1) / 2; i++) {
    string s;
    cin >> s;
    sort(all(s));
    st.erase(st.find(s));
  }
  //cout << "OK" << endl;
  string ans;
  vector<string> str(n + 1);
  for (auto it : st) {
    str[SZ(it)] = it;
  }
  vector<vector<int>> cnt(n + 1, vector<int>(26));
  for (int i = 1; i <= n; i++) {
    for (auto it : str[i]) {
      cnt[i][it - 'a']++;
    }
    for (int j = 0; j < 26; j++) {
      if (cnt[i][j] > cnt[i - 1][j]) {
        ans.pb(char('a' + j));
      }
    }
  }
  cout << "! " << ans << endl;
}