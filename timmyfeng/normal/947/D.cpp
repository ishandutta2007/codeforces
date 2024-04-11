#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;

int pre_sum_s[N];
int pre_sum_t[N];
int suf_s[N];
int suf_t[N];

void process(const string& a, int* suf, int* pre_sum) {
  for (int i = 0; i < int(a.size()); ++i) {
    suf[i + 1] = (a[i] == 'A') ? suf[i] + 1 : 0; 
    pre_sum[i + 1] = pre_sum[i] + (a[i] != 'A');
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  string s, t;
  cin >> s >> t;

  process(s, suf_s, pre_sum_s);
  process(t, suf_t, pre_sum_t);

  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;

    int cnt_s = pre_sum_s[b] - pre_sum_s[a - 1];
    int cnt_t = pre_sum_t[d] - pre_sum_t[c - 1];
    int len_s = min(b - a + 1, suf_s[b]);
    int len_t = min(d - c + 1, suf_t[d]);

    bool ok = (cnt_s % 2 == cnt_t % 2 && cnt_s <= cnt_t);
    if (cnt_s == cnt_t) {
      ok &= (len_s % 3 == len_t % 3 && len_s >= len_t);
    } else {
      if (cnt_s == 0) {
        ok &= (len_s > len_t);
      } else {
        ok &= (len_s >= len_t);
      }
    }
    cout << ok;
  }
  cout << "\n";
}