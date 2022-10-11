#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

void solve() {
  int n;
  cin >> n;
  vector<int> v;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    cin >> v[i];
  }
  stack<int> ret;
  while(v.size()) {
    int curr = v[v.size()-1];
    ret.push(curr);
    while(curr--) v.pop_back();
  }
  printf("%d\n", ret.size());
  while(ret.size()) {
    printf("%d ", ret.top());
    ret.pop();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}