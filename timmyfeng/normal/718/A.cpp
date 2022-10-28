#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, t;
  string s;
  cin >> n >> t >> s;

  char digit = s.back();
  int trunc = n - 1;
  int nxt = -1;

  for (int i = n - 2; i >= 0; --i) {
    if (s[i] == '.') {
      continue;
    }

    int cost = -1;
    if (digit >= '5') {
      cost = 1;
    } else if (digit == '4' && nxt != -1) {
      cost = nxt + 1;
    }

    if (cost != -1 && cost <= t) {
      trunc = i;
    }
    nxt = cost;
    digit = s[i];

    if (s[i + 1] == '.') {
      break;
    }
  }

  while ((int) s.size() > trunc + 1) {
    s.pop_back();
  }

  if (trunc != n - 1) {
    while (true) {
      if (trunc == -1) {
        s = '1' + s;
        break;
      } if (s[trunc] == '.') {
        --trunc;
      } else if (s[trunc] != '9') {
        ++s[trunc];
        break;
      } else {
        s[trunc--] = '0';
      }
    }
  }

  if (count(s.begin(), s.end(), '.') > 0) {
    while (s.back() == '0') {
      s.pop_back();
    }

    if (s.back() == '.') {
      s.pop_back();
    }
  }

  cout << s << "\n";
}