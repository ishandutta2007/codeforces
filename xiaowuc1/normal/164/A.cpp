#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

vector<int> edges[100005];
vector<int> edgesR[100005];
int n, m;
int l[100005];
bool canDown[100005];
bool canUp[100005];

void down() {
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(l[i] == 1) {
      canDown[i] = true;
      q.push(i);
    }
  }
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    for(int out: edges[curr]) {
      if(l[out] == 1) continue;
      if(canDown[out]) continue;
      canDown[out] = true;
      q.push(out);
    }
  }
}

void up() {
  queue<int> q;
  for(int i = 1; i <= n; i++) {
    if(l[i] == 2) {
      canUp[i] = true;
      q.push(i);
    }
  }
  while(!q.empty()) {
    int curr = q.front();
    q.pop();
    if(l[curr] == 1) continue;
    for(int out: edgesR[curr]) {
      if(canUp[out]) continue;
      canUp[out] = true;
      q.push(out);
    }
  }
}

void solve() {
  cin >> n >> m;
  for(int i = 1; i <= n; i++) cin >> l[i];
  while(m--) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back(b);
    edgesR[b].push_back(a);
  }
  down();
  up();
  for(int i = 1; i <= n; i++) {
    cout << (canDown[i] && canUp[i] ? 1 : 0) << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}