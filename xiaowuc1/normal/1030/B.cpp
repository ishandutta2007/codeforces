#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, d;
  cin >> n >> d;
  int q;
  cin >> q;
  while(q--) {
    int x, y;
    cin >> x >> y;
    bool in = false;
    bool topInc = true;
    bool bottomInc = false;
    int top = d;
    int bottom = d;
    if(x == 0) in = bottom <= y && y <= top;
    for(int i = 1; i <= n; i++) {
      if(topInc && top < n) top++;
      else {topInc = false; top--;}
      if(!bottomInc && bottom > 0) bottom--;
      else {bottomInc = true; bottom++;}
      if(i == x) in = (bottom <= y && y <= top);
    }
    if(in) cout << "YES\n";
    else cout << "NO\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}