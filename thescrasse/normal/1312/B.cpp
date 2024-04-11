#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, res, a, b, check1;
vector<long long> v;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    v.clear();
    cin >> n;
    for (i = 0; i < n; i++) {
      cin >> a;
      v.push_back(a);
    }
    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());
    for (i = 0; i < n; i++) {
      cout << v[i] << ' ';
    }
    cout << endl;
  }

  return 0;
}