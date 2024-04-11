#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void load(int& end, int& start, int n) {
  while(n--) {
    int a, b;
    cin >> a >> b;
    start = max(start, a);
    end = min(end, b);
  }
}

void solve() {
  int earlyEnd1 = 2e9, earlyEnd2 = 2e9;
  int lateStart1 = 0, lateStart2 = 0;
  int n; cin >> n; load(earlyEnd1, lateStart1, n);
  cin >> n; load(earlyEnd2, lateStart2, n);
  cout << max(0, max(lateStart1-earlyEnd2, lateStart2-earlyEnd1)) << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}