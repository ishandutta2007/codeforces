#include <bits/stdc++.h>
using namespace std;

long long i, i1, j, k, t, n, m, res, mt[1000][1000], x;

int main() {
  ios::sync_with_stdio(0);
  cin.tie(0);

  //ifstream cin("input.txt");
  //ofstream cout("output.txt");

  cin >> n;
  x = n / 2;
  for (i = 0; i < x; i++) {
    for (j = 0; j < x; j++) {
      mt[i][j] = 1 + 4 * i * x + 4 * j;
      mt[i][j + x] = mt[i][j] + 1;
      mt[i + x][j] = mt[i][j] + 2;
      mt[i + x][j + x] = mt[i][j] - 1;
    }
  }

  for (i = 0; i < n; i++) {
    for (j = 0; j < n; j++) {
      cout << mt[i][j] << ' ';
    }
    cout << endl;
  }

  return 0;
}