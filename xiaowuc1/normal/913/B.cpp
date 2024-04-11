#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> edges[1005];

void solve() {
  int n;
  cin >> n;
  for(int i = 2; i <= n; i++) {
    int p;
    cin >> p;
    edges[p].push_back(i);
  }
  for(int i = 1; i <= n; i++) {
    if(edges[i].empty()) continue;
    int leaves = 0;
    for(int out: edges[i]) if(edges[out].empty()) leaves++;
    if(leaves < 3) {
      cout << "No\n";
      return;
    }
  }
  cout << "Yes\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}