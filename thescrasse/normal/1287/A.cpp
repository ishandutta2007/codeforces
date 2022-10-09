#include <bits/stdc++.h>
using namespace std;
long long N, i, t, t1, j, k, r[110], m;
char a[110];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);
  //ifstream cin("input.txt");
  //ofstream cout("output.txt");
  cin >> t;
  for (t1 = 0; t1 < t; t1++) {
    cin >> N;
    for (i = 0; i < N; i++) {
      cin >> a[i];
    }
    k = 0;
    m = 0;
    while (a[k] == 'P' && k < N) {
      r[k] = 0;
      k++;
    }
    while (k < N) {
      if (a[k] == 'P') {
        r[k] = r[k - 1] + 1;
        m = max(m, r[k]);
        k++;
      } else {
        r[k] = 0;
        k++;
      }
    }
    cout << m << "\n";
  }
  return 0;
}