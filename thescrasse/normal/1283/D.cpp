#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, x[200010], a;
map<long long, long long> d;
queue<long long> q;
vector<long long> r;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  res = 0;
  cin >> n >> m;
  for (i = 0; i < n; i++) {
    cin >> x[i];
    q.push(x[i]);
    d[x[i]] = 1;
  }

  k = 0;
  while (k < m) {
    a = q.front();
    q.pop();
    if (d[a - 1] == 0) {
      q.push(a - 1);
      d[a - 1] = d[a] + 1;
      if (k < m) {
        r.push_back(a - 1);
        res += d[a - 1];
        k++;
      }
    }
    if (d[a + 1] == 0) {
      q.push(a + 1);
      d[a + 1] = d[a] + 1;
      if (k < m) {
        r.push_back(a + 1);
        res += d[a + 1];
        k++;
      }
    }
  }

  res -= m;
  
  cout << res << endl;
  for (i = 0; i < r.size(); i++) {
    cout << r[i] << ' ';
  }

  return 0;
}