#include <bits/stdc++.h>
using namespace std;
long long N, i, j, k, n, s, x, res;
map<long long, long long> closed;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  cin >> N;
  for (i = 0; i < N; i++) {
    closed.clear();
    cin >> n >> s >> k;
    for (j = 0; j < k; j++) {
      cin >> x;
      closed[x] = 1;
    }
    for (j = 0; j <= 1000; j++) {
      if (s - j >= 1) {
        if (closed[s - j] == 0) {
          res = j;
          break;
        }
      }
      if (s + j <= n) {
        if (closed[s + j] == 0) {
          res = j;
          break;
        }
      }
    }
    cout << res << "\n";
  }
  return 0;
}