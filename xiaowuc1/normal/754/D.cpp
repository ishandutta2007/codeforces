#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<pii, int> ppiii;

void solve() {
  priority_queue<pii> q;
  int n, k;
  cin >> n >> k;
  vector<ppiii> v;
  v.resize(n);
  for(int i = 0; i < n; i++) {
    int lhs, rhs;
    cin >> lhs >> rhs;
    v[i] = {{lhs, rhs}, i+1};
  }
  sort(v.begin(), v.end());
  int ret = 0;
  vector<int> ans;
  for(ppiii out: v) {
    q.push({-out.first.second, out.second});
    while(q.size() > k) q.pop();
    if(q.size() == k) {
      int cand = (-q.top().first) - out.first.first + 1;
      if(cand > ret) {
        ret = cand;
      }
    }
  }
  while(q.size()) q.pop();
  for(ppiii out: v) {
    q.push({-out.first.second, out.second});
    while(q.size() > k) q.pop();
    if(q.size() == k) {
      int cand = (-q.top().first) - out.first.first + 1;
      if(cand > 0 && cand == ret) {
        while(q.size()) {
          ans.push_back(q.top().second);
          q.pop();
        }
        break;
      }
    }
  }
  if(ret == 0) {
    for(int i = 1; i <= k; i++) {
      ans.push_back(i);
    }
  }
  cout << ret << "\n";
  for(int out: ans) cout << out << " ";
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}