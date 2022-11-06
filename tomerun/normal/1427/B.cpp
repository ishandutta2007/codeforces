#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include <string>
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>

using namespace std;

void solve() {
  int N, K;
  cin >> N >> K;
  string S;
  cin >> S;
  vector<int> c;
  int start = -1;
  int cw = S[0] == 'W';
  for (int i = 1; i < N; ++i){
    if (S[i] == 'W') cw++;
    if (S[i - 1] == 'W' && S[i] == 'L') {
      start = i;
    } else if (S[i - 1] == 'L' && S[i] == 'W' && start != -1) {
      c.push_back(i - start);
    }
  }
  if (cw == 0) {
    cout << max(0, K * 2 - 1) << endl;
    return;
  }
  sort(c.begin(), c.end());
  int gw = c.size() + 1;
  for (int i = 0; i < c.size(); ++i) {
    if (K < c[i]) break;
    K -= c[i];
    gw--;
    cw += c[i];
  }
  cw += K;
  if (cw > N) cw = N;
  cout << cw * 2 - gw << endl;
}

int main() {
  int T;
  cin >> T;
  for (int i = 0; i < T; ++i){
    solve();
  }
}