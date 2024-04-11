#include <bits/stdc++.h>
using namespace std;

int N;
vector<int> ans;

int Query(vector<int> a) {
#ifndef LOCAL
  cout << "?";
  for (int u : a) cout << " " << u;
  cout << endl;
  int res;
  cin >> res;
  return res - 1;
#else
  vector<int> s = ans;
  for (int i = 0; i < N; ++i) {
    assert(a[i] >= 1 && a[i] <= N);
    s[i] += a[i];
  }
  map<int, int> p;
  for (int i = 0; i < N; ++i) {
    if (p.find(s[i]) != p.end()) {
      return p[s[i]];
    }
    p[s[i]] = i;
  }
  return -1;
#endif
}

int main() {
  cin >> N;
#ifdef LOCAL
  srand(clock() + time(0));
  ans.resize(N);
  iota(ans.begin(), ans.end(), 0);
  random_shuffle(ans.begin(), ans.end());
#endif
  vector<int> p(N, -1);
  for (int i = 1; i < N; ++i) {
    vector<int> query(N, 1);
    query[N - 1] = i + 1;
    if (Query(query) == -1) {
      p[N - 1] = N - i;
      break;
    }
  }
  if (p[N - 1] == -1) {
    p[N - 1] = 0;
  }
  assert(p[N - 1] != -1);
#ifdef LOCAL
  assert(ans[N - 1] == p[N - 1]);
#endif
  for (int i = 0; i < N; ++i) {
    if (i == p[N - 1]) continue;
    vector<int> query(N, 1);
    int diff = p[N - 1] - i;
    if (diff > 0) {
      query[N - 1] = 1;
      for (int j = 0; j < N - 1; ++j) {
        query[j] = diff + 1;
      }
      int k = Query(query);
      assert(k != -1);
      p[k] = i;
    } else {
      query[N - 1] = N;
      for (int j = 0; j < N - 1; ++j) {
        query[j] = diff + N;
      }
      int k = Query(query);
      assert(k != -1);
      p[k] = i;
    }
  }
  cout << "!";
  for (int i = 0; i < N; ++i) {
    cout << " " << p[i] + 1;
  }
  cout << endl;
#ifdef LOCAL
  assert(p == ans);
#endif
  return 0;
}