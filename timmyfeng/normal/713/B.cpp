#include <bits/stdc++.h>
using namespace std;

int query(array<int, 4> rect) {
  if (rect[0] > rect[2] || rect[1] > rect[3]) {
    return 0;
  }
 
  cout << "?";
  for (auto i : rect) {
    cout << " " << i;
  }
  cout << endl;

  int res;
  cin >> res;
  return res;
}

int n;

int find_upper(array<int, 4> rect, int l, int r, int index) {
  while (l < r) {
    int m = (l + r) / 2;
    rect[index] = m;
    if (query(rect) == 0) {
      l = m + 1;
    } else {
      r = m;
    }
  }
  return l;
}

int find_lower(array<int, 4> rect, int l, int r, int index) {
  while (l < r) {
    int m = (l + r + 1) / 2;
    rect[index] = m;
    if (query(rect) == 0) {
      r = m - 1;
    } else {
      l = m;
    }
  }
  return l;
}

array<int, 4> calc(array<int, 4> rect) {
  assert(query(rect) == 1);
  rect[0] = find_lower(rect, rect[0], rect[2], 0);
  rect[1] = find_lower(rect, rect[1], rect[3], 1);
  rect[2] = find_upper(rect, rect[0], rect[2], 2);
  rect[3] = find_upper(rect, rect[1], rect[3], 3);
  return rect;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  cin >> n;

  array<int, 4> a, b;
  int d = find_upper({1, 1, n, n}, 1, n, 2);
  if (query({d + 1, 1, n, n}) == 1) {
    a = calc({1, 1, d, n});
    b = calc({d + 1, 1, n, n});
  } else {
    d = find_upper({1, 1, n, n}, 1, n, 3);
    a = calc({1, 1, n, d});
    b = calc({1, d + 1, n, n});
  }

  cout << "!";
  for (auto i : a) {
    cout << " " << i;
  }
  for (auto i : b) {
    cout << " " << i;
  }
  cout << endl;
}