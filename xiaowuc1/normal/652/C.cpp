#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int from[1000000];
int latest[1000000];

void solve() {
  int n, m;
  cin >> n >> m;
  vector<int> v;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
    from[v[i]] = i;
    latest[i] = -1;
  }
  while(m--) {
    int a, b;
    cin >> a >> b;
    a = from[a];
    b = from[b];
    if(a > b) latest[a] = max(latest[a], b);
    else latest[b] = max(latest[b], a);
  }
  int lhs = -1;
  ll ret = 0;
  for(int i = 0; i < n; i++) {
    lhs = max(lhs, latest[i]);
    ret += i-lhs;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}