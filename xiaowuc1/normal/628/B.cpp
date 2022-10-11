#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

void solve() {
  string s;
  cin >> s;
  ll ret = 0;
  for(int i = 0; i < s.size(); i++) {
    if((s[i]-'0')%4 == 0) {
      ret++;
    }
    if(i >= 0 && (10*(s[i-1]-'0')+(s[i]-'0'))%4 == 0) {
      ret += i;
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}