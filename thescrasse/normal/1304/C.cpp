#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, tm1[110], l[110], h[110], la, ha, check1;
string s;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> t;
  for (i1 = 0; i1 < t; i1++) {
    check1 = 0;
    cin >> n >> m;
    tm1[0] = 0;
    for (i = 0; i < n; i++) {
      cin >> tm1[i + 1] >> l[i] >> h[i];
    }
    la = m;
    ha = m;
    for (i = 0; i < n; i++) {
      la = la + tm1[i] - tm1[i + 1];
      ha = ha - tm1[i] + tm1[i + 1];
      la = max(la, l[i]);
      ha = min(ha, h[i]);
      //cout << la << ' ' << ha << endl;
      if (la > ha) {
        check1 = 1;
        break;
      }
    }
    if (check1 == 1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
    }
  }

  return 0;
}