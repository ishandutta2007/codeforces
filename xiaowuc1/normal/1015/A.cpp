#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

bool bad[105];
int n, m;

void solve() {
  cin >> n >> m;
  while(n--) {
    int lhs, rhs;
    cin >> lhs >> rhs;
    for(int i = lhs; i <= rhs; i++) bad[i] = true;
  }
  vector<int> ret;
  for(int i = 1; i <= m; i++) if(!bad[i]) ret.push_back(i);
  cout << ret.size() << endl;
  for(int out: ret) cout << out << " ";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}