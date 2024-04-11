#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void die() {
  cout << "No\n";
  exit(0);
}

void solve() {
  int x, y;
  cin >> x >> y;
  if(y == 0) die();
  x -= y-1;
  if(y == 1) {
    if(x) die();
  }
  if(x < 0) die();
  if(x%2) die();
  cout << "Yes\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}