#include <algorithm>
#include <bitset>
#include <cassert>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <vector>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, double> pdd;

vector<pii> edges[300050];
int n, m;
bool seen[300050];
void solve() {
  cin >> n >> m;
  for(int i = 0; i <= 3*n; i++) {
    edges[i].clear();
    seen[i] = false;
  }
  for(int i = 1; i <= m; i++) {
    int a, b;
    cin >> a >> b;
    edges[a].push_back({b, i});
    edges[b].push_back({a, i});
  }
  vector<int> matching;
  vector<int> indep;
  for(int i = 1; i <= 3*n && matching.size() < n && indep.size() < n; i++) {
    if(seen[i]) continue;
    seen[i] = true;
    bool matched = false;
    for(pii out: edges[i]) {
      if(!seen[out.first]) {
        seen[out.first] = true;
        matched = true;
        matching.push_back(out.second);
        break;
      }
    }
    if(!matched) indep.push_back(i);
  }
  if(matching.size() >= n) {
    cout << "Matching\n";
    for(int i = 0; i < n; i++) {
      cout << matching[i] << "\n";
    }
    return;
  }
  if(indep.size() >= n) {
    cout << "IndSet\n";
    for(int i = 0; i < n; i++) {
      cout << indep[i] << "\n";
    }
    return;
  }
  cout << "Impossible\n";
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    // cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  // solve();
  casesolve();
}