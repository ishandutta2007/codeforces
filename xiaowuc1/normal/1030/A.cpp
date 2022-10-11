#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> edges[1005];

void solve() {
  int n;
  cin >> n;
  int t = 0;
  while(n-- && t==0) cin >> t;
  if(t) cout << "HARD\n";
  else cout << "EASY\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}