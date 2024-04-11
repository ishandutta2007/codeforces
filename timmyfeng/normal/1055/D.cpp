#include <bits/stdc++.h>
using namespace std;

vector<int> z_function(const string& s) {
  int n = s.size();
  vector<int> z(n);
  for (int i = 1, l = 0, r = 0; i < n; ++i) {
    z[i] = i >= r ? 0 : min(z[i - l], r - i);
    while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
      ++z[i];
    }
    if (i + z[i] > r) {
      l = i;
      r = i + z[i];
    }
  }
  return z;
}

const int N = 3'000;

string initial[N];
string target[N];
int l[N];
int r[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> initial[i];
  }

  for (int i = 0; i < n; ++i) {
    cin >> target[i];
  }

  string s, t;
  for (int i = 0; i < n; ++i) {
    if (initial[i] == target[i]) {
      l[i] = -2;
      continue;
    }

    while (initial[i][l[i]] == target[i][l[i]]) {
      ++l[i];
    }

    r[i] = initial[i].size() - 1u;
    while (initial[i][r[i]] == target[i][r[i]]) {
      --r[i];
    }

    string s_cur = initial[i].substr(l[i], r[i] - l[i] + 1);
    string t_cur = target[i].substr(l[i], r[i] - l[i] + 1);

    if (s.empty()) {
      s = s_cur;
      t = t_cur;
    } else if (s_cur != s || t_cur != t) {
      cout << "NO\n";
      exit(0);
    }

    --l[i];
    ++r[i];
  }

  bool ok_prefix = true;
  bool ok_suffix = true;

  for (int i = 0; i < N; ++i) {
    char prefix_s = 0;
    char prefix_t = 0;
    char suffix_s = 0;
    char suffix_t = 0;

    for (int j = 0; j < n; ++j) {
      if (l[j] == -2) {
        continue;
      }

      if (l[j] - i >= 0) {
        if (prefix_s != 0) {
          ok_prefix &= (initial[j][l[j] - i] == prefix_s && target[j][l[j] - i] == prefix_t);
        }
        prefix_s = initial[j][l[j] - i];
        prefix_t = target[j][l[j] - i];
      } else {
        ok_prefix = false;
      }

      if (r[j] + i < (int) initial[j].size()) {
        if (suffix_s != 0) {
          ok_suffix &= (initial[j][r[j] + i] == suffix_s && target[j][r[j] + i] == suffix_t);
        }
        suffix_s = initial[j][r[j] + i];
        suffix_t = target[j][r[j] + i];
      } else {
        ok_suffix = false;
      }
    }

    ok_prefix &= (prefix_s != 0);
    ok_suffix &= (suffix_s != 0);

    if (ok_prefix) {
      s = prefix_s + s;
      t = prefix_t + t;
    }

    if (ok_suffix) {
      s += suffix_s;
      t += suffix_t;
    }
  }

  for (int i = 0; i < n; ++i) {
    vector<int> z = z_function(s + "#" + initial[i]);
    for (int j = 0; j < (int) initial[i].size(); ++j) {
      if (z[(int) s.size() + 1 + j] == (int) s.size()) {
        initial[i] = initial[i].substr(0, j) + t + initial[i].substr(j + (int) t.size());
        break;
      }
    }

    if (initial[i] != target[i]) {
      cout << "NO\n";
      exit(0);
    }
  }

  cout << "YES\n";
  cout << s << "\n";
  cout << t << "\n";
}