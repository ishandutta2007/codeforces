#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 2;

int lis[N], where[N], length[N], link[N], a[N], b[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }
  a[n] = INT_MAX;

  int m;
  cin >> m;
  for (int i = 0; i < m; ++i) {
    cin >> b[i];
  }
  sort(b, b + m);

  fill(lis, lis + n + 2, INT_MAX);
  fill(where, where + n + 2, -1);
  lis[0] = 0;

  for (int i = 0; i <= n; ++i) {
    if (a[i] == -1) {
      int fill = m - 1;
      for (int index = n + 1; index > 0; --index) {
        while (fill > 0 && b[fill - 1] > lis[index - 1]) {
          --fill;
        }
        if (b[fill] > lis[index - 1] && b[fill] <= lis[index]) {
          lis[index] = b[fill], where[index] = i;
        }
      }

      link[i] = i - 1;
      while (link[i] >= 0 && a[link[i]] != -1) {
        --link[i];
      }
      length[i] = -1;
    } else {
      int index = lower_bound(lis, lis + n + 2, a[i]) - lis;
      lis[index] = a[i], where[index] = i;
      link[i] = where[index - 1];
      length[i] = index;
    }
  }

  int index = n, prv = -1;
  while (index != -1) {
    if (a[index] == -1) {
      length[index] = length[prv] - 1;
      int fill = m - 1;
      while (b[fill] >= a[prv]) {
        --fill;
      }

      a[index] = b[fill];
      b[fill] = INT_MAX;
      prv = index;

      if (length[index] == 1) {
        index = -1;
      } else {
        for (int i = 0; i < index; ++i) {
          if (a[i] < a[index] && length[i] + 1 == length[index]) {
            index = i;
            break;
          }
        }

        if (index == prv) {
          index = link[index];
        }
      }
    } else {
      prv = index, index = link[index];
    }
  }

  int ptr = 0;
  for (int i = 0; i < n; ++i) {
    if (a[i] == -1) {
      while (b[ptr] == INT_MAX) {
        ++ptr;
      }
      a[i] = b[ptr++];
    }
    cout << a[i] << " ";
  }
  cout << "\n";
}