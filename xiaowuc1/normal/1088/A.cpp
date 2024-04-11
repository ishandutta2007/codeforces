#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  int x; cin >> x;
  for(int a = 1; a <= x; a++) {
    for(int b = 1; b <= x; b++) {
      if(a%b == 0 && a*b>x && a/b < x) {
        cout << a << " " << b << "\n";
        return;
      }
    }
  }
  cout << "-1\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  solve();
}