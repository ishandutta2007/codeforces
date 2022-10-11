#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

int to[1005];
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) {
    cin >> to[i];
  }
  for(int i = 1; i <= n; i++) {
    bool seen[1005];
    memset(seen, 0, sizeof(seen));
    int curr = i;
    while(true) {
      if(seen[curr]) {
        cout << curr << " ";
        break;
      }
      seen[curr] = true;
      curr = to[curr];
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}