#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int n, d;
  cin >> n >> d;
  vector<int> v;
  v.resize(n);
  for(int i = 0; i < n; i++) cin >> v[i];
  int ret = 2;
  for(int i = 1; i < n; i++) {
    if(v[i] - v[i-1] == 2 * d) ret++;
    if(v[i] - v[i-1] > 2 * d) ret+=2;
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}