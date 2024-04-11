#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int lhs[300005];
int rhs[300005];

vector<int> ls, rs;
void solve() {
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> lhs[i] >> rhs[i];
    ls.push_back(lhs[i]);
    rs.push_back(rhs[i]);
  }
  sort(ls.begin(), ls.end());
  sort(rs.begin(), rs.end());
  int ret = 0;
  for(int i = 0; i < n; i++) {
    int nlhs = (lhs[i] == ls[n-1] ? ls[n-2] : ls[n-1]);
    int nrhs = (rhs[i] == rs[0] ? rs[1] : rs[0]);
    ret = max(ret, nrhs - nlhs);
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}