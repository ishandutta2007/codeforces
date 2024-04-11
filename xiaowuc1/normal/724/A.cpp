#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  map<string, int> dp;
  dp["monday"] = 0;
  dp["tuesday"] = 1;
  dp["wednesday"] = 2;
  dp["thursday"] = 3;
  dp["friday"] = 4;
  dp["saturday"] = 5;
  dp["sunday"] = 6;
  string a, b;
  cin >> a >> b;
  int x = dp[a];
  int y = dp[b];
  bool good = false;
  good |= x == y;
  good |= (x+2)%7 == y;
  good |= (x+3)%7 == y;
  cout << (good ? "YES\n" : "NO\n");
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}