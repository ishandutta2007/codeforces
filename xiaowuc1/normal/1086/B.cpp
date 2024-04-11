#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<vector<int>> matrix;

int deg[1000000];

void solve() {
  int n;
  cin >> n;
  int s;
  cin >> s;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    deg[a]++;
    deg[b]++;
  }
  ll denom = 0;
  for(int i = 0; i < n; i++) {
    if(deg[i] == 1) denom++;
  }
  double ret = 2*s/(double)(denom);
  cout << fixed << setprecision(10) << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}