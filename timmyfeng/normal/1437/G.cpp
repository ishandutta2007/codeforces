#include <bits/stdc++.h>
using namespace std;

const int N = 300000 + 1;
const int A = 26;

struct aho_corasick {

  multiset<int> sus[N];
  int target[N];

  int to[N][A];
  int link[N];
  int sz = 1;

  int update(const string& s) {
    int cur = 0;
    for (int c : s) {
      c -= 'a';
      if (to[cur][c] == 0) {
        to[cur][c] = sz;
        ++sz;
      }
      cur = to[cur][c];
    }
    sus[cur].insert(0);
    target[cur] = 0;
    return cur;
  }

  void push() {
    queue<int> que;
    que.push(0);

    while (!que.empty()) {
      int u = que.front();
      que.pop();
      for (int i = 0; i < A; ++i) {
        if (to[u][i] != 0) {
          link[to[u][i]] = (u == 0) ? 0 : to[link[u]][i];
          que.push(to[u][i]);
        } else {
          to[u][i] = to[link[u]][i];
        }
      }
    }
  }

} aho;

int where[N];
int value[N];
int memo[N];
vector<int> done;

int get(int u) {
  if (u == 0) {
    return -1;
  } else if (memo[u] != -1) {
    return memo[u];
  } else {
    memo[u] = max(aho.target[u], get(aho.link[u]));
    if (memo[u] == -1) {
      memo[u] = -2;
    }
    done.push_back(u);
    return memo[u];
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  memset(aho.target, -1, sizeof aho.target);
  for (int i = 0; i < n; ++i) {
    string s;
    cin >> s;
    where[i] = aho.update(s);
  }
  aho.push();
  memset(memo, -1, sizeof memo);

  while (q--) {
    int type;
    cin >> type;

    if (type == 1) {
      int i, x;
      cin >> i >> x;
      multiset<int> &s = aho.sus[where[--i]];
      s.erase(s.find(value[i]));
      value[i] = x;
      s.insert(value[i]);
      aho.target[where[i]] = *(--s.end());
      for (auto i : done) {
        memo[i] = -1;
      }
      done.clear();
    } else {
      string s;
      cin >> s;

      int cur = 0;
      int max_sus = -1;
      for (auto i : s) {
        cur = aho.to[cur][i - 'a'];
        max_sus = max(max_sus, get(cur));
      }
      cout << max_sus << "\n";
    }
  }
}