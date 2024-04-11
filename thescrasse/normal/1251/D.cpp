#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, bsl, bsm, bsu, a, b, s, s1;
pair<long long, long long> p[200010];
vector<long long> df;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    cin >> n >> s;
    for (i = 0; i < n; i++) {
      cin >> a >> b;
      p[i] = {a, b};
      s -= a;
    }
    // sort(p, p + n);
    bsl = 0;
    bsu = 1000000010;
    while (bsl != bsu) {
      df.clear();
      bsm = (bsl + bsu) / 2;
      for (i = 0; i < n; i++) {
        if (p[i].second >= bsm) {
          df.push_back(max((long long)0, bsm - p[i].first));
        }
      }
      if (df.empty() == false) {
        if (df.size() >= (n + 1) / 2) {
          s1 = 0;
          sort(df.begin(), df.end());
          for (i = 0; i < (n + 1) / 2; i++) {
            s1 += df[i];
          }
        } else {
          s1 = s + 1;
        }
      } else {
        s1 = s + 1;
      }
      if (s1 <= s) {
        bsl = bsm + 1;
      } else {
        bsu = bsm;
      }
    }
    cout << bsl - 1 << endl;
  }

  return 0;
}