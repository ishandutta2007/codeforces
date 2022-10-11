#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  string s;
  cin >> s;
  int g = 0;
  int b = 0;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == 'o') g++;
    else b++;
  }
  if(g == 0 || b%g == 0) cout << "YES\n";
  else cout << "NO\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}