#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

pii l[100000];
set<pii> ret;
int n;

void solve(int lhs, int rhs) {
  if(lhs >= rhs) return;
  int m = (lhs+rhs)/2;
  for(int i = lhs; i <= rhs; i++) {
    ret.insert({l[m].first, l[i].second});
  }
  solve(lhs, m);
  solve(m+1, rhs);
}

void solve() {
  cin >> n;
  for(int i = 0; i < n; i++) {
    cin >> l[i].first >> l[i].second;
    ret.insert(l[i]);
  }
  sort(l, l+n);
  solve(0, n-1);
  cout << ret.size() << "\n";
  for(pii out: ret) {
    cout << out.first << " " << out.second << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}