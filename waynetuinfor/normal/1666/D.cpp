#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  int N;
  cin >> N;
  for (int x = 0; x < N; ++x) {
    string s, t;
    cin >> s >> t;
    vector<vector<int>> pos(26);
    for (int i = 0; i < s.size(); ++i) {
      pos[s[i] - 'A'].push_back(i);
    }
    vector<int> vec;
    bool no = false;
    for (int i = 0; i < t.size(); ++i) {
      if (pos[t[i] - 'A'].empty()) {
        no = true;
        break;
      }
      vec.push_back(pos[t[i] - 'A'].back());
      pos[t[i] - 'A'].pop_back();
    }
    if (no) {
      cout << "NO\n";
      continue;
    }
    sort(vec.begin(), vec.end());
    string r = "";
    for (int i : vec) {
      r += s[i];
    }
    if (r == t) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}