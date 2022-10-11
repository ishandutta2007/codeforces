#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

ll amt[55];
void solve() {
  int r, c;
  cin >> r >> c;
  for(int i = 0; i < r; i++) {
    string s;
    cin >> s;
    for(int j = 0; j < c; j++) {
      amt[i] *= 2;
      amt[i] |= s[j] == '#';
    }
  }
  for(int j = 0; j < c; j++) {
    ll curr = 0;
    for(int i = 0; i < r; i++) {
      if(amt[i] % 2 == 0) continue;
      curr |= amt[i];
    }
    for(int i = 0; i < r; i++) {
      if((amt[i] & curr) == 0) continue;
      if(amt[i] != curr) {
        cout << "No\n";
        return;
      }
    }
    for(int i = 0; i < r; i++) {
      amt[i] /= 2;
    }
  }
  cout << "Yes\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}