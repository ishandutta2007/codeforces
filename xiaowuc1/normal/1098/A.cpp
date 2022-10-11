#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int n;
int par[100005];
vector<int> children[100005];
ll sumOf[100005];
int q[100005];
ll val[100005];
void solve() {
  cin >> n;
  for(int i = 2; i <= n; i++) {
    cin >> par[i];
    children[par[i]].push_back(i);
  }
  for(int i = 1; i <= n; i++) {
    cin >> sumOf[i];
  }
  int ql = 0;
  int qr = 0;
  q[qr++] = 1;
  while(ql < qr) {
    int curr = q[ql++];
    for(int out: children[curr]) {
      q[qr++] = out;
    }
  }
  val[1] = sumOf[1];
  for(int qqq = 1; qqq < n; qqq++) {
    int actualV = q[qqq];
    if(sumOf[actualV] == -1) {
      // even
      // if there are no children, floor
      if(children[actualV].empty()) {
        val[actualV] = 0;
      }
      else {
        ll parSum = sumOf[par[actualV]];
        ll best = 2e9;
        for(int out: children[actualV]) {
          best = min(best, sumOf[out]);
        }
        if(best < parSum) {
          // gg
          cout << -1 << "\n";
          return;
        }
        val[actualV] = best - parSum;
        sumOf[actualV] = parSum + val[actualV];
      }
    }
    else {
      // odd, fixed by parent
      val[actualV] = sumOf[actualV] - sumOf[par[actualV]];
    }
  }
  ll ret = 0;
  for(int i = 1; i <= n; i++) {
    ret += val[i];
  }
  cout << ret << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
}