#include <bits/stdc++.h>
using namespace std;

const int N = 2e5;

vector<int64_t> a[N];
int64_t cnt[N];
int64_t w[N];
int64_t h[N];

int64_t gcd(int64_t a, int64_t b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

void unique(vector<int64_t>& vals) {
  sort(vals.begin(), vals.end());
  vals.erase(unique(vals.begin(), vals.end()), vals.end());
}

int get(const vector<int64_t>& vals, int64_t u) {
  return lower_bound(vals.begin(), vals.end(), u) - vals.begin();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;

  vector<int64_t> vals_w;
  vector<int64_t> vals_h;
  for (int i = 0; i < n; ++i) {
    cin >> w[i] >> h[i] >> cnt[i];
    vals_w.push_back(w[i]);
    vals_h.push_back(h[i]);
  }

  unique(vals_w);
  unique(vals_h);

  if (int64_t(vals_w.size()) * int64_t(vals_h.size()) != n) {
    cout << 0 << "\n";
    exit(0);
  }

  for (int i = 0; i < int(vals_w.size()); ++i) {
    a[i].resize(vals_h.size());
  }

  int64_t sum = 0;
  for (int i = 0; i < n; ++i) {
    a[get(vals_w, w[i])][get(vals_h, h[i])] = cnt[i];
    sum += cnt[i];
  }

  int64_t gcd_h = a[0][0];
  for (int i = 1; i < int(vals_h.size()); ++i) {
    gcd_h = gcd(gcd_h, a[0][i]);
    int64_t k_cur = a[0][i] / gcd_h;
    int64_t k_pre = a[0][i - 1] / gcd_h;

    for (int j = 1; j < int(vals_w.size()); ++j) {
      if (a[j][i] % k_cur != 0 || a[j][i - 1] % k_pre != 0 || a[j][i] / k_cur != a[j][i - 1] / k_pre) {
        cout << 0 << "\n";
        exit(0);
      }
    }
  }

  int64_t cnt_h = 0;
  for (int i = 0; i < int(vals_h.size()); ++i) {
    cnt_h += a[0][i] / gcd_h;
  }

  int64_t gcd_w = 0;
  for (int i = 0; i < int(vals_w.size()); ++i) {
    gcd_w = gcd(gcd_w, a[i][0]);
  }

  int64_t cnt_w = 0;
  for (int i = 0; i < int(vals_w.size()); ++i) {
    cnt_w += a[i][0] / gcd_w;
  }

  sum /= cnt_h;
  sum /= cnt_w;

  int ans = 0;
  for (int64_t i = 1; i * i <= sum; ++i) {
    if (sum % i == 0) {
      ans += 1 + (i * i != sum);
    }
  }
  cout << ans << "\n";
}