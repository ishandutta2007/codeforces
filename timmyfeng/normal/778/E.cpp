#include <bits/stdc++.h>
using namespace std;

const int N = 1000 + 2;
const int A = 10;

int suffix[N][A];
int prefix[N][A];
int value[N][N];
int cost[N];
string b[N];

string read() {
  string s;
  cin >> s;
  reverse(s.begin(), s.end());
  for (auto &i : s) {
    i -= i == '?' ? 0 : '0';
  }
  return s;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string a = read();

  int n;
  cin >> n;
  int max_s = a.size();
  for (int i = 0; i < n; ++i) {
    b[i] = read();
    max_s = max(max_s, (int) b[i].size());
  }
  ++max_s;

  for (int i = 0; i < A; ++i) {
    cin >> cost[i];
  }

  for (int i = 0; i <= max_s; ++i) {
    fill(value[i], value[i] + n + 1, -1);
  }
  value[0][0] = 0;

  for (int i = 0; i < max_s; ++i) {
    for (int j = 0; j < n; ++j) {
      for (int k = 0; k < A; ++k) {
        prefix[j + 1][k] = prefix[j][k];
        if (i < (int) b[j].size()) {
          prefix[j + 1][k] += b[j][i] == k;
        } else {
          prefix[j + 1][k] += k == 0;
        }
      }
    }

    for (int j = n - 1; j >= 0; --j) {
      for (int k = 0; k < A; ++k) {
        suffix[j][k] = suffix[j + 1][k];
        if (i < (int) b[j].size()) {
          suffix[j][k] += b[j][i] == k;
        } else if (i < (int) a.size()) {
          suffix[j][k] += k == 0;
        }
      }
    }

    for (int j = 0; j <= n; ++j) {
      if (value[i][j] == -1) {
        continue;
      }

      int l = 0;
      int r = A - 1;
      if (i < (int) a.size()) {
        if (i == (int) a.size() - 1 && a[i] == '?') {
          l = 1;
        } else if (a[i] != '?') {
          l = a[i];
          r = a[i];
        }
      } else {
        r = 0;
      }

      for (int d = l; d <= r; ++d) {
        int carry = prefix[j][A - 1];
        int sum = value[i][j];
        for (int c = 0; c < A; ++c) {
          int freq = prefix[j][(c + A - 1) % A] + suffix[j][c];
          sum += cost[(c + d) % A] * freq;
          carry += c + d >= A ? freq : 0;
        }
        value[i + 1][carry] = max(value[i + 1][carry], sum);
      }
    }

    stable_sort(b, b + n, [&i](const string &a, const string &b) {
      return (i < (int) a.size() ? a[i] : 0) > (i < (int) b.size() ? b[i] : 0);
    });
  }

  cout << value[max_s][0] << "\n";
}