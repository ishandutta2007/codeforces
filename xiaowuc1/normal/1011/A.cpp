#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int n, k;
  string s;
  cin >> n >> k >> s;
  int ret = 0;
  int lhs = 'a';
  while(k--) {
    int choose = 1e5;
    for(int i = 0; i < s.size(); i++) {
      if(s[i] >= lhs) choose = min(choose, (int)s[i]);
    }
    if(choose == 1e5) {
      cout << "-1\n";
      return;
    }
    ret += choose+1-'a';
    lhs = choose+2;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}