#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int t;
  cin >> t;
  while (t--) {
    string s;
    cin >> s;

    int depth = 0;
    multiset<int> all;
    map<int, int> down, up;
    for (auto i : s) {
      all.insert(depth);
      if (i == '0') {
        ++down[depth--];
      } else {
        ++up[depth++];
      }
    }

    depth = 0;
    for (int i = 0; i < (int) s.size(); ++i) {
      bool zero = false;
      if (down[depth]) {
        all.erase(all.find(depth));
        if (up[depth - 1] || all.empty() || *(--all.end()) < depth) {
          zero = true;
          --down[depth--];
        } else {
          all.insert(depth);
        }
      }

      if (zero) {
        cout << "0";
      } else {
        cout << "1";
        all.erase(all.find(depth));
        --up[depth++];
      }
    }
    cout << "\n";
  }
}