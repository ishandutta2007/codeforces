#include <iostream>

using namespace std;

const int md = 1000003;

int f[2222][2222];
int a[2222], x[2222], y[2222], st[2222];

int main() {
  string s;
  cin >> s;
  int n = s.length(), i, j, k;
  for (i=0;i<n-1;i++)
    if (s[i] < '0' || s[i] > '9')
      if (s[i+1] == '*' || s[i+1] == '/') {
        cout << 0 << endl;
        return 0;
      }
  if (s[0] == '*' || s[0] == '/') {
    cout << 0 << endl;
    return 0;
  }
  int m = 0, t = 0;
  for (i=0;i<n;i++)
    if (s[i] < '0' || s[i] > '9') t++; else
    if (t || i == 0) {
      a[m] = t-1;
      m++;
      t = 0;
    }
  a[0]++;
  if (t) {
    cout << 0 << endl;
    return 0;
  }
  n = 0;
  for (i=0;i<m;i++) {
    st[i] = n;
    for (j=a[i];j>=0;j--) {
      x[n] = i;
      y[n] = j;
      n++;
    }
  }
  long long g;
  for (i=n-1;i>=0;i--) {
    f[i][x[i]] = 1;
    for (j=x[i]+1;j<m;j++) {
      if (y[i] > 0) f[i][j] = f[i+1][j];
      else f[i][j] = 0;
      g = 0;
      for (k=x[i];k<j;k++) g += (long long)f[i][k]*f[st[k+1]][j];
      f[i][j] = (f[i][j]+g) % md;
    }
  }
  cout << f[0][m-1] << endl;
  return 0;
}