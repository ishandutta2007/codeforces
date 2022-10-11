#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int want;
  cin >> want;
  for(int len = 2; len <= 2000; len++) {
    for(int deficit = 1; deficit <= len; deficit++) {
      // k versus len * (k-deficit)
      // k * len - len * deficit - k == want
      // k(len-1) == want+len*deficit
      // k == (want+len*deficit)/(len-1)
      int num = want + len*deficit;
      int denom = len-1;
      if(num%denom == 0 && num/denom <= 1000000) {
        int k = num/denom;
        cout << len << "\n";
        for(int a = 0; a < len-2; a++) cout << "0 ";
        cout << -deficit << " ";
        cout << k << "\n";
        return;
      }
    }
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}