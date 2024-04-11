#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

int n, m, k;
int buy[11][101];
// [planet][item type]
int sell[11][101];
int item[11][101];

void solve() {
  cin >> n >> m >> k;
  for(int i = 0; i < n; i++) {
    string unused;
    cin >> unused;
    for(int j = 0; j < m; j++) {
      cin >> buy[i][j];
      cin >> sell[i][j];
      cin >> item[i][j];
    }
  }
  int ret = 0;
  for(int i = 0; i < n; i++) {
    for(int j = 0; j < n; j++) {
      if(i == j) continue;
      priority_queue<int> q;
      for(int a = 0; a < m; a++) {
        if(sell[j][a] > buy[i][a]) {
          for(int x = 0; x < item[i][a]; x++) {
            q.push(sell[j][a] - buy[i][a]);
          }
        }
      }
      int cand = 0;
      for(int a = 0; a < k && q.size(); a++) {
        cand += q.top();
        q.pop();
      }
      ret = max(ret, cand);
    }
  }
  cout << ret << endl;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL); cerr.tie(NULL);
  solve();
}