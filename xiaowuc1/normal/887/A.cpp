#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  string s; cin >> s;
  int zero = 0;
  bool start = false;
  for(int i = 0; i < s.size(); i++) if(s[i] == '0' && start) zero++; else if(s[i] == '1') start = true;
  if(zero >= 6) cout << "yes\n";
  else cout << "no\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}