#include <bits/stdc++.h>
using namespace std;

int c;

int calc(int a, int b, int c) {
  if (min(a, b) == 0) {
    return max(a, b) < 2 ? 0 : calc(2, max(a, b), 1);
  } else if (min(a, b) == 1) {
    return (max(a, b) == 1 && c == 1) ? 0 : calc(2, max(a, b), 1);
  } else if (c == 0) {
    return (a + b) / 2;
  }
  return calc(a, b, 0) - ((a - b) % 4 == 0);
}

vector<int> read() {
  string s;
  cin >> s;
  c ^= s[0] - 'a';
  vector<int> res;
  while (!s.empty()) {
    char cur = s.back();
    int len = 0;
    while (!s.empty() && s.back() == cur) {
      s.pop_back();
      ++len;
    }
    res.push_back(len);
  }
  return res;
}

int load(vector<int>& a, vector<int>& b, int c) {
  int sum = 0;
  for (int i = 0; i < c; ++i) {
    b.push_back(a.back());
    sum += a.back();
    a.pop_back();
  }
  return sum;
}

void merge(vector<int>& a, vector<int>& b) {
  if (min(a.size(), b.size()) >= 1u) {
    b.back() += a.back();
    a.pop_back();
  }
  load(a, b, a.size());
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  vector<int> a = read();
  vector<int> b = read();
  vector<int> aa, bb;

  bool flip = false;
  if (a.size() > b.size()) {
    flip ^= true;
    swap(a, b);
  }

  cout << calc(a.size(), b.size(), c) << "\n";

  while (b.size() > 1u) {
    bool done = false;
    for (int i = 1; i >= 0 && !done; --i) {
      for (int j = 1; j <= int(b.size()) && !done; ++j) {
        bool ok = (i ^ j ^ c) % 2 == 1;
        int a_new = int(a.size()) - i + j - (ok && min(int(a.size()) - i, j) > 0);
        int b_new = int(b.size()) - j + i - (ok && min(int(b.size()) - j, i) > 0);
        int c_new = (min(i, j) > 0 || max(i, j) == 0) ? c : max(i, j) % 2;

        if (calc(a_new, b_new, c_new) + 1 == calc(a.size(), b.size(), c)) {
          int x = load(a, aa, i);
          int y = load(b, bb, j);
          merge(bb, a);
          merge(aa, b);
          c = c_new;

          if (flip) {
            cout << y << " " << x << "\n";
          } else {
            cout << x << " " << y << "\n";
          }

          if (a.size() > b.size()) {
            flip ^= true;
            swap(a, b);
          }
          done = true;
        }
      }
    }
    assert(done);
  }
}