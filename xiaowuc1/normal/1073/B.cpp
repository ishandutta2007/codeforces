#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int l[200005];

void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    int c;
    cin >> c;
    l[c] = i;
  }
  int last = 0;
  for(int i = 0; i < n; i++) {
    int c;
    cin >> c;
    cout << max(0, l[c] - last) << " ";
    last = max(last, l[c]);
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}