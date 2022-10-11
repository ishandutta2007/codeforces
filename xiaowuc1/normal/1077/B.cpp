#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int l[105];

void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) cin >> l[i];
  int ret = 0;
  for(int i = 1; i < n; i++) {
    if(l[i-1] && l[i] == 0 && l[i+1]) {
      ret++;
      l[i+1] = 0;
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}