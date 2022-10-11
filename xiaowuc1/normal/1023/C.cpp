#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  string s;
  int n, k;
  cin >> n >> k >> s;
  int needPos = k/2;
  for(int i = 0; k && i < s.size(); i++) {
    if(s[i] == '(') {
      if(needPos > 0) {
        needPos--;
        k--;
        cout << '(';
      }
    }
    else {
      k--;
      cout << ')';
    }
  }
  cout << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}