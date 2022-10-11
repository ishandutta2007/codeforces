#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  string x, z;
  cin >> x >> z;
  for(int i = 0; i < x.size(); i++) {
    if(x[i] < z[i]) {
      cout << "-1\n";
      return;
    }
  }
  cout << z << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}