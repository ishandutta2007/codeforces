#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, a, b, c, d, x, y, z;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> a >> b >> c >> d;
  if (abs(a + c - b - d) > 1 || a - b > 1 || d - c > 1) {
    cout << "NO";
  } else if (a - b == 1) {
    if (c + d != 0) {
      cout << "NO";
    } else {
      cout << "YES" << endl;
      for (i = 0; i < b; i++) {
        cout << "0 1 ";
      }
      cout << "0 ";
    }
  } else if (d - c == 1) {
    if (a + b != 0) {
      cout << "NO";
    } else {
      cout << "YES" << endl;
      for (i = 0; i < c; i++) {
        cout << "3 2 ";
      }
      cout << "3 ";
    }
  } else if (a + c - b - d == 1 && a == 0) {
    cout << "YES" << endl;
    cout << "2 ";
    for (i = 0; i < b; i++) {
      cout << "1 2 ";
    }
    for (i = 0; i < d; i++) {
      cout << "3 2 ";
    }
  } else if (a + c - b - d == -1 && d == 0) {
    cout << "YES" << endl;
    cout << "1 ";
    for (i = 0; i < a; i++) {
      cout << "0 1 ";
    }
    for (i = 0; i < c; i++) {
      cout << "2 1 ";
    }
  } else {
    cout << "YES" << endl;
    if (a + c - b - d == 1) {
      cout << "0 ";
      a--;
      for (i = 0; i < a; i++) {
        cout << "1 0 ";
      }
      for (i = 0; i < b - a; i++) {
        cout << "1 2 ";
      }
      for (i = 0; i < d; i++) {
        cout << "3 2 ";
      }
    } else if (a + c - b - d == -1) {
      cout << "3 ";
      d--;
      for (i = 0; i < d; i++) {
        cout << "2 3 ";
      }
      for (i = 0; i < c - d; i++) {
        cout << "2 1 ";
      }
      for (i = 0; i < a; i++) {
        cout << "0 1 ";
      }
    } else {
      for (i = 0; i < d; i++) {
        cout << "3 2 ";
      }
      for (i = 0; i < c - d; i++) {
        cout << "1 2 ";
      }
      for (i = 0; i < a; i++) {
        cout << "1 0 ";
      }
    }
  }

  return 0;
}