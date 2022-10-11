#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int w, h;
  int u1, d1;
  int u2, d2;
  cin >> w >> h >> u1 >> d1 >> u2 >> d2;
  while(h) {
    w += h;
    if(h == d1) w = max(0, w - u1);
    if(h == d2) w = max(0, w - u2);
    h--;
  }
  cout << w << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}