#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define F first
#define S second
#define pb push_back  
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll

bool check(int n, vector<int> &a) {
  return (*max_element(all(a)) <= n * ((n + 1) / 2) && accumulate(all(a), 0) <= n * n - (n / 2) * (n / 2));
}

vector<vector<int>> construct(int n, vector<int> &a) {
  vector<vector<int>> answer(n, vector<int>(n, 0));
  if (n == 1) {
    answer[0][0] = max_element(all(a)) - a.begin() + 1;
    return answer;
  }
  priority_queue<pair<int, int>> q;
  for (int i = 0; i < SZ(a); i++) {
    q.push({a[i], i + 1});
  }
  auto ok = [&](pair<int, int> a) {
    return a.F >= 1 && a.S >= 1 && a.F <= n && a.S <= n;
  };
  auto next = [&](pair<int, int> a) {
    if (ok(make_pair(a.F, a.S + 2))) {
      return make_pair(a.F, a.S + 2);
    }
    return make_pair(a.F + 2, (a.S - 1) % 2 + 1);
  };
  pair<int, int> current = {2, 1}, current2 = {1, 2}, current3 = {1, 1};
  while (!q.empty()) {
    pair<int, int> kek = q.top();
    q.pop();
    while (kek.F > 0) {
      kek.F--;
      if (ok(current)) {
        answer[current.F - 1][current.S - 1] = kek.S; 
        current = next(current);
      } else if (ok(current3)) {
        answer[current3.F - 1][current3.S - 1] = kek.S;
        current3 = next(current3);
      }
      else {
        assert(ok(current2));
        answer[current2.F - 1][current2.S - 1] = kek.S;
        current2 = next(current2);
      }
    }
  }
  return answer;
}
 
signed main() {
  ios_base::sync_with_stdio(0);
  cin.tie(0); 
  cout.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int m, k;
    cin >> m >> k;
    vector<int> a(k);
    for (int i = 0; i < k; i++) {
      cin >> a[i];
    }
    int l = 0, r = 1e5 + 10;
    while (r - l > 1) {
      int mid = (l + r) / 2;
      if (check(mid, a)) {
        r = mid;
      }
      else {
        l = mid;
      }
    }
    vector<vector<int>> answer = construct(r, a);
    cout << r << '\n';
    for (int i = 0; i < r; i++) {
      for (int j = 0; j < r; j++) {
        cout << answer[i][j] << ' ';
      }
      cout << '\n';
    }
  }
}