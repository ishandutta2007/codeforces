// 1207D
// divisione dell'array per massimizzare la somma dei prodotti
// idee: greedy (prefix sum minimi)

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, k1, t, n, a[300010], m, check1, res;
vector<long long> b;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n >> k;
  for (i = 0; i < n; i++) {
    cin >> a[i];
  }

  b.push_back(a[0]);
  for (i = 1; i < n; i++) {
    b.push_back(b[i - 1] + a[i]);
  }

  res = b[n - 1] * k;
  sort(b.begin(), b.end() - 1);
  for (i = 0; i < k - 1; i++) {
    res -= b[i];
  }

  cout << res;

  return 0;
}