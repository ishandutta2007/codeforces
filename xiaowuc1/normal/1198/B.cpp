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

int amt[300000];
vector<int> payouts;
vector<int> maxV;
int idx[300000];
void solve() {
  int n;
  cin >> n;
  for(int i = 1; i <= n; i++) cin >> amt[i];
  int q;
  cin >> q;
  for(int i = 0; i < q; i++) {
    int t;
    cin >> t;
    if(t == 2) {
      int v;
      cin >> v;
      payouts.push_back(v);
      maxV.push_back(0);
    }
    else {
      int i, a;
      cin >> i >> a;
      idx[i] = payouts.size();
      amt[i] = a;
    }
  }
  if(payouts.size()) {
    maxV[maxV.size()-1] = payouts.back();
    int idx = maxV.size();
    idx -= 2;
    while(idx >= 0) {
      maxV[idx] = max(maxV[idx+1], payouts[idx]);
      idx--;
    }
  }
  for(int i = 1; i <= n; i++) {
    if(idx[i] == payouts.size()) cout << amt[i];
    else cout << max(amt[i], maxV[idx[i]]);
    if(i == n) cout << "\n";
    else cout << " ";
  }
}

void casesolve() {
  int t;
  cin >> t;
  for(int i = 1; i <= t; i++) {
    cout << "Case #" << i << ": ";
    solve();
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);
  solve();
  // casesolve();
}