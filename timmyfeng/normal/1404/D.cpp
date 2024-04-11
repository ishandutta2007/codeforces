#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  if (n % 2 == 0) {
    cout << "First\n";
    for (int k = 0; k < 2; ++k) {
      for (int i = 1; i <= n; ++i) {
        cout << i << " ";
      }
    }
    cout << endl;
  } else {
    cout << "Second" << endl;

    vector<int> first(n + 1);
    vector<int> oth(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
      int a;
      cin >> a;
      if (first[a] > 0) {
        oth[i] = first[a];
        oth[first[a]] = i;
      } else {
        first[a] = i;
      }
    }

    vector<int> ans;
    vector<bool> visited(2 * n + 1);
    for (int i = 1; i <= 2 * n; ++i) {
      if (!visited[i]) {
        int cur = i;
        do {
          ans.push_back(cur);
          int nxt = (cur - 1 + n) % (2 * n) + 1;
          visited[cur] = true;
          visited[nxt] = true;
          cur = oth[nxt];
        } while (cur != i);
      }
    }

    if (accumulate(ans.begin(), ans.end(), 0LL) % (2 * n) != 0) {
      for (auto i : ans) {
        cout << (i - 1 + n) % (2 * n) + 1 << " ";
      }
    } else {
      for (auto i : ans) {
        cout << i << " ";
      }
    }
    cout << endl;
  }

  int verdict;
  cin >> verdict;
  assert(verdict == 0);
}