/**
 *    author:  tourist
 *    created: 10.11.2018 18:43:51       
**/
#include <bits/stdc++.h>

using namespace std;

template <typename T>
vector<int> kmp_table(int n, const T &s) {
  vector<int> p(n, 0);
  int k = 0;
  for (int i = 1; i < n; i++) {
    while (k > 0 && !(s[i] == s[k])) {
      k = p[k - 1];
    }
    if (s[i] == s[k]) {
      k++;
    }
    p[i] = k;
  }
  return p;
}

template <typename T>
vector<int> kmp_table(const T &s) {
  return kmp_table((int) s.size(), s);
}

template <typename T>
vector<int> kmp_search(int n, const T &s, int m, const T &w, const vector<int> &p) {
  assert(n >= 1 && (int) p.size() == n);
  vector<int> res;
  int k = 0;
  for (int i = 0; i < m; i++) {
    while (k > 0 && (k == n || !(w[i] == s[k]))) {
      k = p[k - 1];
    }
    if (w[i] == s[k]) {
      k++;
    }
    if (k == n) {
      res.push_back(i - n + 1);
    }
  }
  return res;
  // returns 0-indexed positions of occurrences of s in w
}

template <typename T>
vector<int> kmp_search(const T &s, const T &w, const vector<int> &p) {
  return kmp_search((int) s.size(), s, (int) w.size(), w, p);
}

void err() {
  cout << "NO" << '\n';
  exit(0);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<string> have(n), want(n);
  for (int i = 0; i < n; i++) {
    cin >> have[i];
  }
  for (int i = 0; i < n; i++) {
    cin >> want[i];
  }
  vector<int> first(n, -1), last(n, -1);
  int mai = -1;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < (int) have[i].size(); j++) {
      if (have[i][j] != want[i][j]) {
        if (first[i] == -1) {
          first[i] = j;
        }
        last[i] = j;
      }
    }
    if (first[i] != -1) {
      mai = i;
    }
  }
  for (int i = 0; i < n; i++) {
    if (first[i] == -1) {
      continue;
    }
    if (last[i] - first[i] != last[mai] - first[mai]) {
      err();
    }
    for (int j = first[i]; j <= last[i]; j++) {
      if (have[i][j] != have[mai][j - first[i] + first[mai]]) {
        err();
      }
      if (want[i][j] != want[mai][j - first[i] + first[mai]]) {
        err();
      }
    }
  }
  while (true) {
    char c = '?';
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (first[i] == -1) {
        continue;
      }
      if (first[i] == 0) {
        ok = 0;
        break;
      }
      if (have[i][first[i] - 1] != c && c != '?') {
        ok = 0;
        break;
      }
      c = have[i][first[i] - 1];
    }
    if (!ok) {
      break;
    }
    for (int i = 0; i < n; i++) {
      if (first[i] == -1) {
        continue;
      }
      first[i]--;
    }
  }
  while (true) {
    char c = '?';
    int ok = 1;
    for (int i = 0; i < n; i++) {
      if (first[i] == -1) {
        continue;
      }
      if (last[i] == (int) have[i].size() - 1) {
        ok = 0;
        break;
      }
      if (have[i][last[i] + 1] != c && c != '?') {
        ok = 0;
        break;
      }
      c = have[i][last[i] + 1];
    }
    if (!ok) {
      break;
    }
    for (int i = 0; i < n; i++) {
      if (first[i] == -1) {
        continue;
      }
      last[i]++;
    }
  }
  string s = have[mai].substr(first[mai], last[mai] - first[mai] + 1);
  string t = want[mai].substr(first[mai], last[mai] - first[mai] + 1);
  vector<int> p = kmp_table(s);
  for (int i = 0; i < n; i++) {
    vector<int> pos = kmp_search(s, have[i], p);
    string get = have[i];
    if (!pos.empty()) {
      int x = pos[0];
      for (int j = 0; j < (int) t.size(); j++) {
        get[x + j] = t[j];
      }
    }
    if (get != want[i]) {
      err();
    }
  }
  cout << "YES" << '\n';
  cout << s << '\n';
  cout << t << '\n';
  return 0;
}