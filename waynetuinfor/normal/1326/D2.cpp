#include <bits/stdc++.h>
using namespace std;

mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
constexpr int kP[2] = {1'000'000'000 + 123, 1'000'000'000 + 87};

template <class CharType>
vector<size_t> Manacher(const basic_string<CharType> &s) {
  basic_string<CharType> t(1, (CharType)-1);
  for (size_t i = 0; i < s.length(); ++i) {
    t += s[i];
    t += (CharType)-1;
  }
  vector<size_t> z(t.size());
  size_t l = 0, r = 0;
  for (size_t i = 1; i < t.length(); ++i) {
    z[i] = (r > i ? min(z[2 * l - i], r - i) : 1);
    while (i >= z[i] && i + z[i] < t.length() && t[i - z[i]] == t[i + z[i]]) z[i]++;
    if (i + z[i] > r) {
      r = i + z[i];
      l = i;
    }
  }
  return z;
}

// vector<int> Manacher(const string &s) {
  // string t = ".";
  // for (int i = 0; i < s.length(); ++i) t += s[i], t += '.';
  // vector<int> z(t.size());
  // int l = 0, r = 0, ans = 0;
  // for (int i = 1; i < t.length(); ++i) {
    // z[i] = (r > i ? min(z[2 * l - i], r - i) : 1);
    // while (i - z[i] >= 0 && i + z[i] < t.length() && t[i - z[i]] == t[i + z[i]]) ++z[i];
    // if (i + z[i] > r) r = i + z[i], l = i;
  // }
  // return z;
// }

int Brute(string s) {
  int n = s.size();
  int res = 0;
  for (int i = 0; i <= n; ++i) {
    for (int j = 0; j <= n; ++j) {
      string a = s.substr(0, i);
      string b = s.substr(n - j);
      string c = a + b;
      if (c.size() > s.size()) continue;
      string d = c;
      reverse(c.begin(), c.end());
      if (c == d) res = max(res, (int)c.size());
    }
  }
  return res;
}

void Solve() {
  srand(clock() + time(0));
  for (int it = 0; it < 1; ++it) {
    string s;
    // {
      // int n = rand() % 50 + 1;
      // int c = rand() % 5 + 5;
      // for (int i = 0; i < n; ++i) s += rand() % c + 'a';
    // }
    cin >> s;
    int n = s.size();
    auto z = Manacher(s);
    int p = 0;
    for (int i = 0; i < n; ++i) {
      if (s[i] == s[n - 1 - i]) p = i + 1;
      else break;
    }
    int res = -1, a = -1, b = -1;
    for (int i = 1; i + 1 < z.size(); ++i) {
      if (z[i] > 0) {
        if (i & 1) {
          int g = (z[i] - 2) / 2;
          int x = i / 2;
          if (p >= x - g && x - g <= n - 1 - x - g) {
            int r = min(x - g, n - 1 - x - g);
            int k = 2 * r + z[i] - 1;
            if (k > res) {
              res = k;
              a = r + z[i] - 1;
              b = r;
            }
          }
          if (p >= (n - 1 - (x + g)) && n - 1 - x - g <= x - g) {
            int r = min(x - g, n - 1 - x - g);
            int k = 2 * r + z[i] - 1;
            if (k > res) {
              res = k;
              a = r;
              b = r + z[i] - 1;
            }
          }
        } else {
          int x = i / 2;
          int g = (z[i] - 1) / 2;
          // cout << "x = " << x << " g = " << g << " p = " << p << endl;
          if (p >= x - g && x - g <= (n - (x + g))) {
            // cout << "x - g = " << x - g << endl;
            int r = min(x - g, (n - (x + g)));
            int k = 2 * r + z[i] - 1;
            if (k > res) {
              res = k;
              b = r;
              a = r + z[i] - 1;
            }
          }
          if (p >= (n - (x + g)) && n - (x + g) <= x - g) {
            // cout << "n - (x + g) = " << n - (x + g) << endl;
            int r = min(x - g, n - (x + g));
            int k = 2 * r + z[i] - 1;
            if (k > res) {
              res = k;
              a = r;
              b = r + z[i] - 1;
            }
          }
        }
      }
    }
    // cout << "a = " << a << " b = " << b << endl;
    for (int i = 0; i < a; ++i) cout << s[i];
    for (int i = n - b; i < n; ++i) cout << s[i];
    cout << "\n";
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int t;
  cin >> t;
  while (t--) Solve();
}