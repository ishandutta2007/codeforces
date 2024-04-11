#include <bits/stdc++.h>
using namespace std;
long long N, Q, i, j, k, n, s, x, a, b, res;
map<long long, long long> cl;
set<long long> pr;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  cin >> N >> Q;
  for (i = 0; i < Q; i++) {
    cin >> a >> b;
    if (cl[b] % (2 * a) < a) {
      cl[b] += a + 100;
      if (b != 1) {
        if (cl[b] + cl[b - 1] == 203 || cl[b] + cl[b - 1] >= 300) {
          pr.insert(b - 1);
        }
      }
      if (b != N) {
        if (cl[b] + cl[b + 1] == 203 || cl[b] + cl[b + 1] >= 300) {
          pr.insert(b);
        }
      }
    } else {
      cl[b] -= a + 100;
      if (b != 1) {
        if (cl[b] + cl[b - 1] != 203 && cl[b] + cl[b - 1] < 300) {
          pr.erase(b - 1);
        }
      }
      if (b != N) {
        if (cl[b] + cl[b + 1] != 203 && cl[b] + cl[b + 1] < 300) {
          pr.erase(b);
        }
      }
    }
    //cout << cl[b] << "\n";
    if (pr.empty()) {
      cout << "YES" << "\n";
    } else {
      cout << "NO" << "\n";
    }
  }
  return 0;
}