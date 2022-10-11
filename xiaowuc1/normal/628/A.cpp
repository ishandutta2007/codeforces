#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

void solve() {
  int n, b, p;
  cin >> n >> b >> p;
  int br = 0;
  int tr = n*p;
  while(n > 1) {
    int x = 1;
    while(2*x < n) {
      x *= 2;
    }
    br += x*(2*b+1);
    n -= x;
  }
  cout << br << " " << tr << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cout.tie(NULL);
  cerr.tie(NULL);
  solve();
}