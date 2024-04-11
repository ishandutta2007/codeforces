// max linee bianche utilizzando la gomma

#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, pl, t, n, res, a, m, b, c1[2010], c2[2010], lr[2010], rr[2010], lc[2010], rc[2010], m1[2010][2010], m2[2010][2010], m3[2010][2010], m4[2010][2010];
char mt[2010][2010];

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  pl = 0;
  cin >> n >> k;
  for (i = 0; i < n; i++) {
    c1[i] = 0;
    c2[i] = 0;
    for (j = 0; j < n; j++) {
      cin >> mt[i][j];
      m1[i][j] = 0;
      m2[i][j] = 0;
      m3[i][j] = 0;
      m4[i][j] = 0;
    }
  }

  for (i = 0; i < n; i++) {
    lr[i] = 0;
    rr[i] = n - k;
    for (j = 0; j < n; j++) {
      if (mt[i][j] == 'B') {
        c1[i]++;
        lr[i] = max(lr[i], j - k + 1);
        rr[i] = min(rr[i], j);
      }
    }
  }

  for (i = 0; i < n; i++) {
    lc[i] = 0;
    rc[i] = n - k;
    for (j = 0; j < n; j++) {
      if (mt[j][i] == 'B') {
        c2[i]++;
        lc[i] = max(lc[i], j - k + 1);
        rc[i] = min(rc[i], j);
      }
    }
  }

  for (i = 0; i < n; i++) {
    // cout << lr[i] << ' ' << rr[i] << endl;
    if (c1[i] == 0) {
      pl++;
    } else {
      for (j = lr[i]; j <= rr[i]; j++) {
        m1[i][j]++;
      }
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      m3[0][i] += m1[j][i];
    }
    for (j = k; j < n; j++) {
      m3[j - k + 1][i] = m3[j - k][i] + m1[j][i] - m1[j - k][i];
    }
  }

  for (i = 0; i < n; i++) {
    // cout << lc[i] << ' ' << rc[i] << endl;
    if (c2[i] == 0) {
      pl++;
    } else {
      for (j = lc[i]; j <= rc[i]; j++) {
        m2[j][i]++;
      }
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < k; j++) {
      m4[i][0] += m2[i][j];
    }
    for (j = k; j < n; j++) {
      m4[i][j - k + 1] = m4[i][j - k] + m2[i][j] - m2[i][j - k];
    }
  }

  res = 0;

  /*for (i = 0; i < n - k + 1; i++) {
    for (j = 0; j < n - k + 1; j++) {
      cout << m3[i][j] << ' ';
    }
    cout << endl;
  }
  cout << endl;

  for (i = 0; i < n - k + 1; i++) {
    for (j = 0; j < n - k + 1; j++) {
      cout << m4[i][j] << ' ';
    }
    cout << endl;
  }*/

  for (i = 0; i < n - k + 1; i++) {
    for (j = 0; j < n - k + 1; j++) {
      m3[i][j] += m4[i][j];
      // cout << m3[i][j] << ' ';
      res = max(res, m3[i][j]);
    }
    // cout << endl;
  }

  res += pl;

  cout << res;

  return 0;
}