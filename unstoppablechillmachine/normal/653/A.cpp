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
  int n;
  cin >> n;
  set<int> st;
  for (int i = 0; i < n; i++)  {
  	int x;
  	cin >> x;
  	st.insert(x);
  }
  for (auto it : st) {
  	if (st.find(it + 1) != st.end() && st.find(it + 2) != st.end()) {
  		cout << "YES\n";
  		exit(0);
  	}
  }
  cout << "NO\n";
}