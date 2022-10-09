#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, m, res1, res2, d[100010];
vector<long long> cs[100010];
vector<long long> l, r;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> k;
  for (i = 1; i <= n; i++) {
    cin >> d[i];
    cs[d[i]].push_back(i);
  }

  for (i = 1; i < n; i++) {
    if (cs[i - 1].empty() && !cs[i].empty()) {
      cout << -1;
      return 0;
    }
  }

  if (cs[0].size() > 1) {
    cout << -1;
    return 0;
  }

  for (i = 1; i < n; i++) {
    if (cs[i].empty()) {
      break;
    }
    k1 = k;
    if (i == 1) {
      k1++;
    }
    if (cs[i].size() > (k1 - 1) * cs[i - 1].size()) {
      cout << -1;
      return 0;
    } else {
      for (j = 0; j < cs[i].size(); j++) {
        l.push_back(cs[i - 1][(j % cs[i - 1].size())]);
        r.push_back(cs[i][j]);
      }
    }
  }

  cout << n - 1 << endl;
  for (i = 0; i < n - 1; i++) {
    cout << l[i] << ' ' << r[i] << endl;
  }

  return 0;
}