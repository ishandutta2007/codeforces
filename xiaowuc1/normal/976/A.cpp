#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int zero = 0;
  int one = 0;
  string s;
  cin >> s;
  cin >> s;
  for(int i = 0; i < s.size(); i++) {
    if(s[i] == '0') zero++;
    else one++;
  }
  if(one) cout << 1;
  while(zero--) cout << 0;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}