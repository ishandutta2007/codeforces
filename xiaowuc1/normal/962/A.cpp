#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int l[1000000];

void solve() {
  int n;
  cin >> n;
  ll total = 0;
  for(int i = 1; i <= n; i++) {
    cin >> l[i];
    total += l[i];
  }
  ll curr = 0;
  for(int i = 1; i <= n; i++) {
    curr += l[i];
    if(2 * curr >= total) {
      cout << i << "\n";
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}