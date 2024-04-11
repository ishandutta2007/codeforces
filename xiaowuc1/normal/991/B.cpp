#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  vector<int> v;
  int n;
  cin >> n;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  int ret = 0;
  while(true) {
    int sum = 0;
    for(int out: v) sum += out;
    // sum / out.length >= 9/2
    // 2 * sum >= 9 * out.length
    if(2 * sum >= 9 * n) {
      break;
    }
    sort(v.begin(), v.end());
    ret++;
    v[0] = 5;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}