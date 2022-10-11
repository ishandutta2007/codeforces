#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void realsolve() {
  int n;
  cin >> n;
  string s;
  cin >> s;
  bool good = true;
  for(int i = 0; i < s.size(); i++) {
    int x = s[i];
    x -= s[s.size()-1-i];
    good &= (x == 2 || x == 0 || x == -2);
  }
  if(good) cout << "YES\n";
  else cout << "NO\n";
}

void solve() {
  int n;
  cin >> n;
  while(n--) realsolve();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}