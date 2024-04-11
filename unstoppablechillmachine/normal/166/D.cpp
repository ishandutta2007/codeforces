#include <bits/stdc++.h>
typedef long long ll;
typedef long double ld;
using namespace std;
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)(x).size()
#define int ll
#define F first
#define S second

const int INF = 1e9 + 10;

struct T {
  int cost, x, id;
  T() {};
  T(int _c, int _x, int _i) : cost(_c), x(_x), id(_i) {};
};

bool cmp(T a, T b) {
  return a.x == b.x ? a.cost < b.cost : a.x < b.x;
}

const int N = 1e5 + 10;
int dp[N][4];
pair<int, int> from[N][4];

signed main() {
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector<T> have;
  for (int i = 0; i < n; i++) {
    int a, b;
    cin >> a >> b;
    have.pb(T(a, b, i + 1));
  }
  sort(all(have), cmp);
  int m;
  cin >> m;
  vector<T> arr;
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    arr.pb(T(a, b, i + 1));
  }
  sort(all(arr), cmp);
  int ptr = 0, ptr2 = 0;
  for (int i = 1; i <= m; i++) {
    while (ptr < n && have[ptr].x < arr[i - 1].x) {
      ptr++;
    }
    while (ptr2 < n && have[ptr2].x <= arr[i - 1].x) {
      ptr2++;
    }
    if (i == 1) {
      dp[i][0] = 0;
      dp[i][3] = 0;
      if (ptr < n && have[ptr].x == arr[i - 1].x && arr[i - 1].cost >= have[ptr].cost) {
        dp[i][1] = have[ptr].cost;
        from[i][1] = {0, 1};
      }
      if (ptr2 < n && have[ptr2].x == arr[i - 1].x + 1 && arr[i - 1].cost >= have[ptr2].cost) {
        dp[i][2] = have[ptr2].cost;
        from[i][2] = {0, 2};
      }
      continue;
    }
    int cur = arr[i - 2].x;
    if (cur == arr[i - 1].x) {
      for (int cc = 0; cc < 4; cc++) {
        dp[i][cc] = dp[i - 1][cc];
        from[i][cc] = {cc, 0};
      }  
    }
    else if (cur + 1 == arr[i - 1].x) {
      for (int cc = 0; cc < 2; cc++) {
        if (dp[i - 1][cc] > dp[i][0]) {
          dp[i][0] = dp[i - 1][cc];
          from[i][0] = {cc, 0};
        }
      }
      for (int cc = 2; cc < 4; cc++) {
        if (dp[i - 1][cc] > dp[i][1]) {
          dp[i][1] = dp[i - 1][cc];
          from[i][1] = {cc, 0};
        }
      }
    }
    else {
      for (int cc = 0; cc < 4; cc++) {
        if (dp[i - 1][cc] > dp[i][0]) {
          dp[i][0] = dp[i - 1][cc];
          from[i][0] = {cc, 0};
        }  
      }
    }
    for (int cc = 0; cc < 4; cc++) {
      for (int fr = 0; fr < 4; fr++) {
        if (cc == 1 && cur + min(2ll, fr) - 1 < arr[i - 1].x && ptr < n && have[ptr].x == arr[i - 1].x && arr[i - 1].cost >= have[ptr].cost) {
          if (dp[i - 1][fr] + have[ptr].cost > dp[i][cc]) {
            dp[i][cc] = dp[i - 1][fr] + have[ptr].cost;
            from[i][cc] = {fr, 1};
          }
        }
        if (cc == 2 && cur + min(2ll, fr) - 1 < arr[i - 1].x && ptr2 < n && have[ptr2].x == arr[i - 1].x + 1 && arr[i - 1].cost >= have[ptr2].cost) {
          if (dp[i - 1][fr] + have[ptr2].cost > dp[i][cc]) {
            dp[i][cc] = dp[i - 1][fr] + have[ptr2].cost;
            from[i][cc] = {fr, 2};
          }
        }
        if (cc == 3) {
          if (cur == arr[i - 1].x - 1) {
            if (fr >= 2 && ptr2 < n && have[ptr2].x == arr[i - 1].x + 1 && arr[i - 1].cost >= have[ptr2].cost) {
              if (dp[i - 1][fr] + have[ptr2].cost > dp[i][cc]) {
                dp[i][cc] = dp[i - 1][fr] + have[ptr2].cost;
                from[i][cc] = {fr, 2};
              }
            }
          }
          if (cur == arr[i - 1].x) {
            if (fr == 1 && ptr2 < n && have[ptr2].x == arr[i - 1].x + 1 && arr[i - 1].cost >= have[ptr2].cost) {
              if (dp[i - 1][fr] + have[ptr2].cost > dp[i][cc]) {
                dp[i][cc] = dp[i - 1][fr] + have[ptr2].cost;
                from[i][cc] = {fr, 2};
              }
            }
            if (fr == 2 && ptr < n && have[ptr].x == arr[i - 1].x && arr[i - 1].cost >= have[ptr].cost) {
              if (dp[i - 1][fr] + have[ptr].cost > dp[i][cc]) {
                dp[i][cc] = dp[i - 1][fr] + have[ptr].cost;
                from[i][cc] = {fr, 1};
              }
            }
          }
        }
      }
    }
  }
  pair<int, int> best = {0, 0};
  for (int i = 0; i < 4; i++) {
    best = max(best, {dp[m][i], i});
  }
  cout << best.F << '\n';
  ptr = ptr2 = n - 1;
  vector<pair<int, int>> ans;
  for (int i = m; i >= 1; i--) {
    pair<int, int> kek = from[i][best.S];
    while (ptr > 0 && have[ptr].x > arr[i - 1].x) {
      ptr--;
    }
    while (ptr2 > 0 && have[ptr2].x > arr[i - 1].x + 1) {
      ptr2--;
    }
    if (kek.S == 2) {
      ans.pb({arr[i - 1].id, have[ptr2].id});
    }
    else if (kek.S == 1) {
      ans.pb({arr[i - 1].id, have[ptr].id});
    }
    best.S = kek.F;
  }
  cout << SZ(ans) << '\n';
  for (auto it : ans) {
    cout << it.F << ' ' << it.S << '\n';
  }
}