#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int dpCover[1000000];
int dpNoCover[1000000];
int dpSafeNoCover[1000000];
int n;
vector<int> edges[1000000];
int depth[1000000];

int dfsCover(int curr);
int dfsNoCover(int curr);
int dfsSafeNoCover(int curr);

int dfsCover(int curr) {
  if(dpCover[curr] >= 0) return dpCover[curr];
  dpCover[curr] = 1;
  for(int out: edges[curr]) {
    if(depth[out] < depth[curr]) continue;
    dpCover[curr] += min(dfsCover(out), min(dfsSafeNoCover(out), dfsNoCover(out)));
  }
  return dpCover[curr];
}

int dfsNoCover(int curr) {
  if(dpNoCover[curr] >= 0) return dpNoCover[curr];
  dpNoCover[curr] = 0;
  vector<int> diffs;
  for(int out: edges[curr]) {
    if(depth[out] < depth[curr]) continue;
    dpNoCover[curr] += dfsNoCover(out);
    diffs.push_back(dfsNoCover(out) - dfsCover(out));
  }
  if(diffs.empty()) {
    dpNoCover[curr] = 1e6;
    return dpNoCover[curr];
  }
  sort(diffs.begin(), diffs.end());
  dpNoCover[curr] -= diffs[diffs.size()-1];
  if(diffs.size() >= 2) {
    for(int i = diffs.size()-2; i >= 0; i--) {
      if(diffs[i] > 0) {
        dpNoCover[curr] -= diffs[i];
      }
    }
  }
  return dpNoCover[curr];
}

int dfsSafeNoCover(int curr) {
  if(dpSafeNoCover[curr] >= 0) return dpSafeNoCover[curr];
  dpSafeNoCover[curr] = 0;
  for(int out: edges[curr]) {
    if(depth[out] < depth[curr]) continue;
    dpSafeNoCover[curr] += min(dfsCover(out), dfsNoCover(out));
  }
  return dpSafeNoCover[curr];
}

void dfsForDepth(int curr, int par) {
  for(int out: edges[curr]) {
    if(out == par) continue;
    depth[out] = depth[curr] + 1;
    dfsForDepth(out, curr);
  }
}

void solve() {
  cin >> n;
  for(int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edges[b].push_back(a);
  }
  for(int i = 1; i <= n; i++) {
    dpCover[i] = -1;
    dpNoCover[i] = -1;
    dpSafeNoCover[i] = -1;
  }
  dfsForDepth(1, -1);
  int ret = 0;
  for(int i = 1; i <= n; i++) {
    if(depth[i] == 2) {
      ret += min(dfsCover(i), min(dfsSafeNoCover(i), dfsNoCover(i)));
    }
  }
  for(int i = 1; i <= n; i++) {
    if(depth[i] < 2) continue;
    // cout << i << " " << dfsCover(i) << " " << dfsNoCover(i) << " " << dfsSafeNoCover(i) << endl;
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}