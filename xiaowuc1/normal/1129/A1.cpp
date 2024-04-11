#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m;
vector<int> edges[5005];

void solve(int start) {
  int need = 0;
  for(int move = 0; move < n; move++) {
    int currLoc = (start+move)%n;
    if(edges[currLoc].empty()) continue;
    int cand = move;
    int closestDest = edges[currLoc][0];
    if(edges[currLoc][edges[currLoc].size()-1] > currLoc){
      closestDest = edges[currLoc][lower_bound(edges[currLoc].begin(), edges[currLoc].end(), currLoc) - edges[currLoc].begin()];
    }
    cand += (edges[currLoc].size()-1) * n;
    cand += (closestDest - currLoc + n) % n;
    need = max(need, cand);
  }
  cout << need;
}

void solve() {
  cin >> n >> m;
  while(m--) {
    int a, b;
    cin >> a >> b;
    a--;
    b--;
    edges[a].push_back(b);
  }
  for(int i = 0; i < n; i++) sort(edges[i].begin(), edges[i].end());
  for(int start = 0; start < n; start++) {
    solve(start);
    if(start == n-1) cout << "\n";
    else cout << " ";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}