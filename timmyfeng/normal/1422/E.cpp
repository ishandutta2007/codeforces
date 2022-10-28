#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

string ans[N];
int length[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s;
  cin >> s;
  int n = s.size();

  string t;
  vector<int> index;
  vector<bool> compare;

  for (int i = n - 1; i >= 0; --i) {
    if (t.size() < 2u || t[t.size() - 2u] < s[i]) {
      compare.push_back(true);
    } else if (t[t.size() - 2u] > s[i]) {
      compare.push_back(false);
    }
    index.push_back(i);
    t += s[i];

    if (t.size() >= 2u) {
      if (t[t.size() - 2u] == t[t.size() - 1u]) {
        if (index[t.size() - 2u] - 1 == index[t.size() - 1u]) {
          if (compare.back()) {
            for (int j = 0; j < 2; ++j) {
              if (t.size() < 3u || t[t.size() - 3u] != t.back()) {
                compare.pop_back();
              }
              index.pop_back();
              t.pop_back();
            }
          }
        }
      }
    }

    length[i] = t.size();
    if (t.size() <= 10u) {
      ans[i] = t;
    } else {
      ans[i] += t[0];
      ans[i] += t[1];
      ans[i] += "...";
      ans[i] += t.substr(t.size() - 5u);
    }
  }

  for (int i = 0; i < n; ++i) {
    reverse(ans[i].begin(), ans[i].end());
    cout << length[i] << " " << ans[i] << "\n";
  }
}