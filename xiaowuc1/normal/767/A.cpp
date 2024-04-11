#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool present[100005];

void solve() {
  int n;
  cin >> n;
  int last = n;
  for(int d = 1; d <= n; d++) {
    int t;
    cin >> t;
    present[t] = true;
    while(present[last]) {
      cout << last-- << " ";
    }
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}