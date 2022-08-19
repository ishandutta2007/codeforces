/**
 *    author:  tourist
 *    created: 16.09.2017 22:07:38       
**/
#include <bits/stdc++.h>

using namespace std;

int solve(vector<long long> a) {
  int n = a.size();
  for (int i = 2; i * i <= n; i++) {
    if (n % i == 0) {
      if (n % (i * i) != 0) {
        for (int j = 0; j < n; j += i) {
          long long delta = a[j];
          int k = j;
          do {
            a[k] -= delta;
            k = (k + n / i) % n;
          } while (k != j);
        }
      } 
      vector< vector<long long> > w(i);
      for (int j = 0; j < n; j++) {
        w[j % i].push_back(a[j]);
      }
      bool ok = true;
      for (int j = 0; j < i; j++) {
        if (!solve(w[j])) {
          ok = false;
          break;
        }
      }
      return ok;
    }
  }
  for (int i = 1; i < (int) a.size(); i++) {
    if (a[i] != a[0]) {
      return false;
    }
  }
  return true;
}

int main() {
  int n;
  string s;
  cin >> n >> s;
  vector<long long> a(n);
  for (int i = 0; i < n; i++) {
    a[i] = s[i] - '0';
  }
  puts(solve(a) ? "YES" : "NO");
  return 0;
}