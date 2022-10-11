#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int w, h, k;
  cin >> w >> h >> k;
  int ret = 0;
  while(k--) {
    ret += 2*(w+h-2);
    w -= 4;
    h -= 4;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}