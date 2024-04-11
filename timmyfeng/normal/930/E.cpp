#include <bits/stdc++.h>
using namespace std;

const int M = 1e9 + 7;

int add(int a, int b) {
  a += b;
  if (a >= M) {
    a -= M;
  }
  return a;
}

int sub(int a, int b) {
  a -= b;
  if (a < 0) {
    a += M;
  }
  return a;
}

int mul(int a, int b) {
  return 1LL * a * b % M;
}

int mod_pow(int a, int b) {
  int res = 1;
  while (b) {
    if (b % 2) {
      res = mul(res, a);
    }
    a = mul(a, a);
    b /= 2;
  }
  return res;
}

map<int, int> segment[2];
map<int, int> mp[2];
int bound[2];
int cnt[2];
int n[2];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int k;
  cin >> k >> n[0] >> n[1];

  set<int> vals = {k};
  for (int i = 0; i < 2; ++i) {
    for (int j = 0; j < n[i]; ++j) {
      int l, r;
      cin >> l >> r;
      if (segment[i].count(l) == 0) {
        segment[i][l] = k + 1;
      }
      segment[i][l] = min(segment[i][l], r);
      vals.insert(l);
      vals.insert(r);
    }
  }

  mp[0][k + 1] = 1;
  cnt[0] = 1;

  for (int i = 1; i <= k; ++i) {
    auto it = vals.lower_bound(i);
    if (*it != i) {
      int cnt_new = mul(add(cnt[0], cnt[1]), mod_pow(2, *it - i - 1));
      for (int j = 0; j < 2; ++j) {
        mp[j][k + 1] = add(mp[j][k + 1], sub(cnt_new, cnt[j]));
        cnt[j] = cnt_new;
      }
      i = *it;
    }

    for (int j = 0; j < 2; ++j) {
      bound[j] = (segment[j].count(i) == 0) ? k + 1 : segment[j][i];
    }

    for (int j = 0; j < 2; ++j) {
      int sum = cnt[j ^ 1];
      while (!mp[j].empty() && (--mp[j].end())->first >= bound[j]) {
        sum = add(sum, (--mp[j].end())->second);
        mp[j].erase(--mp[j].end());
      }
      mp[j][bound[j]] = sum;
    }

    cnt[0] = add(cnt[0], cnt[1]);
    cnt[1] = cnt[0];

    for (int j = 0; j < 2; ++j) {
      if (!mp[j].empty() && mp[j].begin()->first == i) {
        cnt[j] = sub(cnt[j], mp[j].begin()->second);
        mp[j].erase(mp[j].begin());
      }
    }
  }

  cout << add(cnt[0], cnt[1]) << "\n";
}