#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int n;
  string s;
  cin >> n >> s;
  for(int i = 1; i < n; i++) {
    if(s[i-1] != s[i]) {
      cout << "YES\n";
      cout << s[i-1] << s[i] << "\n";
      return;
    }
  }
  cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}