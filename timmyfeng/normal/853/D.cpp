#include <bits/stdc++.h>
using namespace std;

const int N = 3e5 + 1;

int a[N];
int one;
int two;
int n;

int calc(int cnt1, int cnt2) {
  int res = 0;
  int credit = 0;
  for (int i = 0; i < n; ++i) {
    if ((a[i] == 1000 && cnt1 > 0) || (a[i] == 2000 && cnt2 > 0)) {
      credit += a[i] / 10;
      res += a[i];
      if (a[i] == 1000) {
        --cnt1;
      } else {
        --cnt2;
      }
    } else {
      res += max(0, a[i] - credit);
      credit = max(0, credit - a[i]);
    }
  }
  return res;
}

int get(int k) {
  int lo = 0;
  int hi = two - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (calc(k, mid) >= calc(k, mid + 1)) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  return calc(k, lo);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    if (a[i] == 1000) {
      ++one;
    } else {
      ++two;
    }
  }

  int lo = 0;
  int hi = one - 1;
  while (lo <= hi) {
    int mid = (lo + hi) / 2;
    if (get(mid) >= get(mid + 1)) {
      lo = mid + 1;
    } else {
      hi = mid - 1;
    }
  }
  cout << get(lo) << "\n";
}