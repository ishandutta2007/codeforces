#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n, s;
  cin >> n >> s;
  vector<int> v;
  for(int i = 0; i < n; i++) {
    int h, m;
    cin >> h >> m;
    v.push_back(60 * h + m);
  }
  if(0 < v[0] - s) {
    cout << "0 0\n";
    return;
  }
  for(int i = 0; i < n; i++) {
    int t = v[i] + s + 1;
    if(i+1 == n || v[i+1] - t > s) {
      cout << t/60 << " " << t%60 << "\n";
      break;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}