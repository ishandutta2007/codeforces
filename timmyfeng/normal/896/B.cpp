#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m, c;
  cin >> n >> m >> c;

  vector<int> a(n + 1);

  while (count(a.begin() + 1, a.end(), 0) > 0) {
    int p;
    cin >> p;
    int ptr;
    if (p > c / 2) {
      ptr = n;
      while (a[ptr] >= p) {
        --ptr;
      }
      a[ptr] = p;
    } else {
      ptr = 1;
      while (a[ptr] <= p && a[ptr] != 0) {
        ++ptr;
      }
      a[ptr] = p;
    }
    cout << ptr << endl;
  }
}