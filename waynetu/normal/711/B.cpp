#include <iostream>
#include <iomanip>
using namespace std;

long long int sq[500][500];
int n;
long long int sum;

bool b() {
  long long int ji;
  for (int i = 0; i < n; ++i) {
    ji = 0;
    for (int j = 0; j < n; ++j) {
      ji += sq[i][j];
    }
    if (ji != sum) return false;
  }
  for (int i = 0; i < n; ++i) {
    ji = 0;
    for (int j = 0; j < n; ++j) {
      ji += sq[j][i];
    }
    if (ji != sum) return false;
  }
  ji = 0;
  for (int i = 0; i < n; ++i) {
    ji += sq[i][i];
  }
  if (ji != sum) return false;
  ji = 0;
  for (int i = 0; i < n; ++i) {
    ji += sq[i][n - i - 1];
  }
  if (ji != sum) return false;
  return true;
}

int main() {
  cin >> n;
  int zi, zj;
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      cin >> sq[i][j];
      if (sq[i][j] == 0) {
        zi = i;
        zj = j;
      }
    }
  }
  if (n == 1) {
    cout << 1 << endl;
    return 0;
  }
  int r, c;
  if (zi == n - 1) r = 0;
  else r = zi + 1;
  long long int s1 = 0;
  for (int i = 0; i < n; ++i) {
    s1 += sq[r][i];
  }
  sum = s1;
  // cout << "sum: " << sum << endl;
  long long int ji = 0;
  for (int i = 0; i < n; ++i) {
    ji += sq[zi][i];
  }
  long long int ans = sum - ji;
  if (ans == 0 || ans < 0) {
    cout << -1 << endl;
    return 0;
  }
  // cout << "ans: " << ans << endl;
  sq[zi][zj] = ans;
  if (b()) {
    cout << ans << endl;
  }
  else
    cout << -1 << endl;
  return 0;
}