#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> children[300000];
int treesz[300000];
int loc[300000];
vector<int> ordering;
int n;

void dfs(int curr) {
  treesz[curr]++;
  loc[curr] = ordering.size();
  ordering.push_back(curr);
  for(int out: children[curr]) {
    dfs(out);
    treesz[curr] += treesz[out];
  }
}

void solve() {
  int q;
  cin >> n >> q;
  for(int i = 2; i <= n; i++) {
    int pp;
    cin >> pp;
    children[pp].push_back(i);
  }
  dfs(1);
  while(q--) {
    int u, k;
    cin >> u >> k;
    if(k > treesz[u]) cout << "-1" << endl;
    else cout << ordering[loc[u]+k-1] << endl;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}