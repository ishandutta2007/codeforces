#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  string s, t;
  cin >> s >> t;
  int ret = s.size() + t.size();
  int si = s.size()-1;
  int ti = t.size()-1;
  while(si >= 0 && ti >= 0 && s[si] == t[ti]) {
    ret -= 2;
    si--;
    ti--;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}