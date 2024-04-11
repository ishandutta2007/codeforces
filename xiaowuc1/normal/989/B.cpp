#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, p;
  string s;
  cin >> n >> p >> s;
  bool bad = true;
  for(int i = 0; i < p; i++) {
    set<char> seen;
    int amt = 0;
    for(int j = i; j < n; j += p) {
      amt++;
      seen.insert(s[j]);
    }
    if(seen.size() >= 2) bad = false;
    if(seen.count('.') && amt >= 2) bad = false;
  }
  if(bad) {
    cout << "No\n";
    return;
  }
  for(int i = 0; i < p; i++) {
    set<char> seen;
    for(int j = i; j < n; j += p) {
      seen.insert(s[j]);
    }
    for(int j = i; j < n; j += p) {
      if(s[j] == '.') {
        if(seen.count('1')) {
          s = s.substr(0, j) + "0" + s.substr(j+1);
          seen.insert('0');
        }
        else {
          s = s.substr(0, j) + "1" + s.substr(j+1);
          seen.insert('1');
        }
      }
    }
  }
  cout << s << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}