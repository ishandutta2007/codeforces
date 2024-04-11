#include <bits/stdc++.h>
using namespace std;

struct Bitset {
  vector<uint64_t> bs;

  Bitset(int n) {
    bs.resize((n + 63) >> 6);
  }

  void Set(int b) {
    bs[b >> 6] |= (1ULL << (b & 63));
  }

  void Unset(int b) {
    bs[b >> 6] &= ~(1ULL << (b & 63));
  }

  int FindFirst() {
    for (int i = 0; i < bs.size(); ++i) {
      if (bs[i] != 0) {
        int bit = __builtin_ctzll(bs[i]);
        return bit | (i << 6);
      }
    }
    return -1;
  }

  int FindNext(int b) {
    // cout << "FindNext b = " << b << endl;
    for (int i = b >> 6; i < bs.size(); ++i) {
      if (i == (b >> 6)) {
        if ((b & 63) == 63) continue;
        uint64_t sft = (bs[i] >> ((b & 63) + 1));
        if (sft != 0) {
          int bit = __builtin_ctzll(sft);
          // cout << "find = " << ((bit + (b & 63) + 1) | (i << 6)) << endl;
          return (bit + (b & 63) + 1) | (i << 6);
        }
      } else {
        if (bs[i] != 0) {
          int bit = __builtin_ctzll(bs[i]);
          // cout << "find = " << (bit | (1 << 6)) << endl;
          return bit | (i << 6);
        }
      }
    }
    return -1;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; ++i) {
    cin >> a[i];
    a[i]--;
  }
  vector<int> ds(a.begin(), a.end());
  sort(ds.begin(), ds.end());
  ds.resize(unique(ds.begin(), ds.end()) - ds.begin());
  for (int i = 0; i < n; ++i) {
    a[i] = lower_bound(ds.begin(), ds.end(), a[i]) - ds.begin();
  }
  const int kM = ds.size();
  constexpr int kB = 500;
  int q;
  cin >> q;
  vector<int> l(q), r(q), ord(q);
  for (int i = 0; i < q; ++i) {
    cin >> l[i] >> r[i];
    l[i]--, r[i]--;
    ord[i] = i;
  }
  sort(ord.begin(), ord.end(), [&](int i, int j) {
    if (l[i] / kB == l[j] / kB) return r[i] < r[j];
    return l[i] / kB < l[j] / kB;
  });
  vector<int> cnt(kM), ck(n + 1);
  constexpr int kN = 100'000 + 1;
  Bitset bs(n + 1);
  ck[0] = kM;

  auto Add = [&](int v) {
    if (--ck[cnt[v]] == 0) bs.Unset(cnt[v]);
    cnt[v]++;
    if (ck[cnt[v]]++ == 0) bs.Set(cnt[v]);
  };

  auto Sub = [&](int v) {
    if (--ck[cnt[v]] == 0) bs.Unset(cnt[v]);
    cnt[v]--;
    if (ck[cnt[v]]++ == 0) bs.Set(cnt[v]);
  };

  vector<int64_t> ans(q);

  for (int i = 0, tl = 0, tr = -1; i < q; ++i) {
    while (tr < r[ord[i]]) Add(a[++tr]);
    while (tr > r[ord[i]]) Sub(a[tr--]);
    while (tl > l[ord[i]]) Add(a[--tl]);
    while (tl < l[ord[i]]) Sub(a[tl++]);
    int64_t res = 0;
    int z = -1;
    vector<pair<int *, int>> hist;
    vector<pair<uint64_t *, uint64_t>> bhist;

    auto Assign = [&](int *p, int v) {
      hist.emplace_back(p, *p);
      *p = v;
    };

    auto AssignSet = [&](int p) {
      bhist.emplace_back(&bs.bs[p >> 6], bs.bs[p >> 6]);
      bs.Set(p);
    };

    for (int j = bs.FindFirst(); j != -1; j = bs.FindNext(j)) {
      // cout << "j = " << j << endl;
      if (j == 0) continue;
      int cv = ck[j];
      assert(cv > 0);
      if (z != -1) {
        AssignSet(z + j);
        Assign(&ck[z + j], ck[z + j] + 1);
        res += z + j;
        cv--;
      }
      z = -1;
      if (cv >= 2) {
        assert(j + j < kN);
        res += 1LL * (j + j) * (cv / 2);
        Assign(&ck[j + j], ck[j + j] + cv / 2);
        AssignSet(j + j);
        cv %= 2;
      }
      if (cv == 1) z = j;
    }
    ans[ord[i]] = res;
    // cout << "res = " << res << endl;
    while (!hist.empty()) {
      *hist.back().first = hist.back().second;
      hist.pop_back();
    }
    while (!bhist.empty()) {
      *bhist.back().first = bhist.back().second;
      bhist.pop_back();
    }
  }
  for (int i = 0; i < q; ++i) cout << ans[i] << "\n";
  return 0;
}