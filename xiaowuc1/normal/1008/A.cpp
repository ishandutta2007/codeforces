#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool vowel(char ch) {
  return ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u';
}

void solve() {
  string s;
  cin >> s;
  int idx = 0;
  while(idx < s.size()) {
    if(s[idx] == 'n') {
      idx++;
      continue;
    }
    if(!vowel(s[idx])) {
      if(idx + 1 == s.size() || !vowel(s[idx+1])) {
        cout << "NO\n";
        return;
      }
    }
    idx++;
  }
  cout << "YES\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}