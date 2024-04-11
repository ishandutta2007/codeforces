#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  int ret = 2e9;
  for(int i = 1; i * i <= n; i++) {
    int j = (n/i);
    if(i*j < n) j++;
    ret = min(ret, i+j);
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}