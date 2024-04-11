#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  string s;
  cin >> s;
  for(int i = 2; i < s.size(); i++) {
    if(s[i-2] == '.' || s[i-1] == '.' || s[i] == '.') continue;
    if(s[i-2] == s[i-1]) continue;
    if(s[i-0] == s[i-1]) continue;
    if(s[i-2] == s[i-0]) continue;
    cout << "Yes\n";
    return;
  }
  cout << "No\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}