#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  string s;
  cin >> n >> k >> s;

  set<string> visited;
  queue<string> que;
  que.push(s);
  int ans = 0;

  while (k > 0 && !que.empty()) {
    string t = que.front();
    que.pop();

    if (visited.count(t) == 0) {
      visited.insert(t);
      ans += n - t.size();
      for (int i = 0; i < (int) t.size(); ++i) {
        que.push(t.substr(0, i) + t.substr(i + 1));
      }
      --k;
    }
  }

  cout << (k == 0 ? ans : -1) << "\n";
}