#include <bits/stdc++.h>

using namespace std;

const int N = 5e5;
const int M = 8 * N;

int st1[M], st2[M];

void build(int node, int l, int r) {
  st1[node] = -1e9;
  st2[node] = -1e9;
  if (l == r) {
    return;
  }
  int mid = l + r >> 1;
  build(node + node, l, mid);
  build(node + node + 1, mid + 1, r);
}

int get1(int node, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) {
    return -1e9;
  }
  if (ll <= l && r <= rr) {
    return st1[node];
  }
  int mid = l + r >> 1;
  return max(get1(node + node, l, mid, ll, rr), get1(node + node + 1, mid + 1, r, ll, rr));
}

int get2(int node, int l, int r, int ll, int rr) {
  if (l > r || l > rr || r < ll) {
    return -1e9;
  }
  if (ll <= l && r <= rr) {
    return st2[node];
  }
  int mid = l + r >> 1;
  return max(get2(node + node, l, mid, ll, rr), get2(node + node + 1, mid + 1, r, ll, rr));
}

void modify1(int node, int l, int r, int x, int v) {
  if (l == r) {
    st1[node] = max(st1[node], v);
    return; 
  }
  int mid = l + r >> 1;
  if (x <= mid) {
    modify1(node + node, l, mid, x, v);
  } else {
    modify1(node + node + 1, mid + 1, r, x, v);
  }
  st1[node] = max(st1[node + node], st1[node + node + 1]);
}

void modify2(int node, int l, int r, int x, int v) {
  if (l == r) {
    st2[node] = max(st2[node], v);
    return; 
  }
  int mid = l + r >> 1;
  if (x <= mid) {
    modify2(node + node, l, mid, x, v);
  } else {
    modify2(node + node + 1, mid + 1, r, x, v);
  }
  st2[node] = max(st2[node + node], st2[node + node + 1]);
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);  
  int tt;
  cin >> tt;
  while (tt--) {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    vector<long long> pref(n);
    for (int i = 0; i < n; i++) {
      if (i > 0) {
        pref[i] = pref[i - 1];
      }                       
      pref[i] += a[i];
    }           
    vector<long long> cpr;
    for (int i = 0; i < n; i++) {
      cpr.push_back(pref[i]);
    }
    build(1, 0, n - 1);
    sort(cpr.begin(), cpr.end());
    cpr.erase(unique(cpr.begin(), cpr.end()), cpr.end());
    map<long long, int> val;
    val[0] = 0;
    vector<int> dp(n, -n);
    for (int i = 0; i < n; i++) {
      if (val.count(pref[i])) {
        dp[i] = val[pref[i]];
      }
      int my = lower_bound(cpr.begin(), cpr.end(), pref[i]) - cpr.begin();
      dp[i] = max(dp[i], get1(1, 0, n - 1, 0, my - 1) + i);
      dp[i] = max(dp[i], get2(1, 0, n - 1, my + 1, n - 1) - i);
      if (pref[i] > 0) {
        dp[i] = max(dp[i], i + 1);
      }
      if (pref[i] < 0) {
        dp[i] = max(dp[i], -i - 1);
      }
      if (!val.count(pref[i])) {
        val[pref[i]] = dp[i];
      }
      val[pref[i]] = max(val[pref[i]], dp[i]);
      modify1(1, 0, n - 1, my, dp[i] - i);
      modify2(1, 0, n - 1, my, dp[i] + i);
    }
    cout << dp[n - 1] << '\n';
  }                                                                    
  return 0;
}