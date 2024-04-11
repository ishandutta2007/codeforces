#include <bits/stdc++.h>
using namespace std;

const int N = 500'000 + 2;

int count_left[N];
int prv[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  string s;
  cin >> n >> s;

  long long ans = 0;
  vector<int> zeroes;
  vector<int> ones;

  if (s[0] == '1') {
    zeroes.push_back(0);
  }

  for (int i = 0, j = 0; i < n; i = j) {
    while (j < n && s[i] == s[j]) {
      ++j;
    }
    (s[i] == '0' ? zeroes : ones).push_back(j - i);
  }

  if (s.back() == '1') {
    zeroes.push_back(0);
  }

  for (int i = 0; i < (int) ones.size(); ++i) {
    for (int j = 1; j <= ones[i] - 2; ++j) {
      ans += (long long) j * (j + 1) / 2;
    }
  }

  int index = zeroes[0];
  fill(prv, prv + n + 2, -1);
  for (int i = 0; i < (int) ones.size(); ++i) {
    count_left[i] = index - prv[ones[i]];
    for (int j = 1; j < ones[i]; ++j) {
      ans += (long long) j * (index - prv[j]);
    }
    for (int j = 0; j < ones[i]; ++j) {
      prv[ones[i] - j] = index + j;
    }
    index += ones[i] + zeroes[i + 1];
  }

  index = n - 1 - zeroes.back();
  fill(prv, prv + n + 2, n);
  for (int i = ones.size() - 1u; i >= 0; --i) {
    for (int j = 1; j < ones[i]; ++j) {
      ans += (long long) j * (prv[j + 1] - index);
    }
    for (int j = 0; j < ones[i]; ++j) {
      prv[ones[i] - j] = index - j;
    }
    ans += (long long) ones[i] * count_left[i] * (prv[ones[i] + 1] - index);
    index -= ones[i] + zeroes[i];
  }

  cout << ans << "\n";
}