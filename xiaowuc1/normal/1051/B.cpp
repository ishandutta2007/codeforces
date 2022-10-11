#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  ll lhs, rhs;
  cin >> lhs >> rhs;
  cout << "YES\n";
  while(lhs < rhs) {
    cout << lhs << " " << (lhs+1) << "\n";
    lhs += 2;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}