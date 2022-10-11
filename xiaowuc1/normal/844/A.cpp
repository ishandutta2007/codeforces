#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  string s;
  cin >> s;
  int n;
  cin >> n;
  set<char> dp;
  for(int i = 0; i < s.size(); i++) dp.insert(s[i]);
  if(s.size() < n) cout << "impossible\n";
  else cout << max(0, n - (int)dp.size()) << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}