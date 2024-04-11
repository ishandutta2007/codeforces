#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, r, a;
vector<long long> st;

long long xorv(vector<long long> x, long long p) {
  if (x.empty() || p < 0) {
    return 0;
  }
  vector<long long> l, r;
  for (auto u : x) {
    if (((u >> p) & 1) == 0) {
      l.push_back(u);
    } else {
      r.push_back(u);
    }
  }
  if (l.empty()) {
    return xorv(r, p - 1);
  } else if (r.empty()) {
    return xorv(l, p - 1);
  }
  return (1 << p) + min(xorv(l, p - 1), xorv(r, p - 1));
}

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  for (i = 0; i < n; i++) {
    cin >> a;
    st.push_back(a);
  }

  cout << xorv(st, 31);

  return 0;
}