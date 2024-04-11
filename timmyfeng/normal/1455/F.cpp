#include <bits/stdc++.h>
using namespace std;

int k;

char f(char c) {
  if (c == 'a' || c == 'a' + k - 1) {
    return 'a';
  } else {
    return c - 1;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;

  while (t--) {
    int n;
    string s;
    cin >> n >> k >> s;

    bool free = true;
    int ptr = 0;

    while (ptr < n) {
      if (!free) {
        if (ptr + 2 < n && s[ptr + 2] < min(s[ptr], s[ptr + 1])) {
          swap(s[ptr + 1], s[ptr + 2]);
          swap(s[ptr + 1], s[ptr]);
          free = false;
          ptr += 2;
        } else if (ptr + 1 < n && s[ptr + 1] < s[ptr]) {
          swap(s[ptr + 1], s[ptr]);
          free = false;
          ++ptr;
        } else {
          free = true;
          ++ptr;
        }
      } else {
        if (ptr + 2 < n && s[ptr + 2] < min(f(s[ptr]), f(s[ptr + 1]))) {
          s[ptr] = f(s[ptr]);
          swap(s[ptr + 1], s[ptr + 2]);
          swap(s[ptr + 1], s[ptr]);
          free = false;
          ptr += 2;
        } else if (ptr + 1 < n && f(s[ptr + 1]) < f(s[ptr])) {
          if (s[ptr + 1] == 'a') {
            s[ptr] = f(s[ptr]);
            swap(s[ptr + 1], s[ptr]);
          } else {
            swap(s[ptr], s[ptr + 1]);
            s[ptr] = f(s[ptr]);
          }
          free = false;
          ++ptr;
        } else {
          s[ptr] = f(s[ptr]);
          free = true;
          ++ptr;
        }
      }
    }

    cout << s << "\n";
  }
}