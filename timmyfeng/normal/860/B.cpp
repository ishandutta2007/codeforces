#include <bits/stdc++.h>
using namespace std;

const int N = 70'000;

string ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  map<string, vector<int>> sequences;
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    for (int j = 0; j < 9; ++j) {
      for (int k = 1; j + k - 1 < 9; ++k) {
        sequences[s.substr(j, k)].push_back(i);
      }
    }
    ans[i] = s;
  }

  for (auto &[s, a] : sequences) {
    a.erase(unique(a.begin(), a.end()), a.end());
    if (a.size() == 1u && s.size() < ans[a[0]].size()) {
      ans[a[0]] = s;
    }
  }

  for (int i = 0; i < n; ++i) {
    cout << ans[i] << "\n";
  }
}