#include <bits/stdc++.h>

using namespace std;

const int BLOCK = 448;

struct query{
  int l, r, id;
  bool operator<(query other) const{
    return (r / BLOCK < other.r / BLOCK) || (r / BLOCK == other.r / BLOCK && l < other.l);
  }
};

int n, q, a[200005];
query b[200005];
long long cnt[1000005], curr;
long long ans[200005];

void Add(long long x) {
  curr -= cnt[x] * cnt[x] * x;
  cnt[x]++;
  curr += cnt[x] * cnt[x] * x;
}

void Rem(long long x) {
  curr -= cnt[x] * cnt[x] * x;
  cnt[x]--;
  curr += cnt[x] * cnt[x] * x;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cin >> n >> q;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
  }
  for (int i = 0; i < q; i++) {
    cin >> b[i].l >> b[i].r;
    --b[i].l, --b[i].r;
    b[i].id = i;
  }
  sort(b, b + q);
  int ll = 1, rr = 0;
  for (int i = 0; i < q; i++) {
    while (ll > b[i].l) {
      Add(a[--ll]);
    }
    while (ll < b[i].l) {
      Rem(a[ll++]);
    }
    while (rr < b[i].r) {
      Add(a[++rr]);
    }
    while (rr > b[i].r) {
      Rem(a[rr--]);
    }
    ans[b[i].id] = curr;
  }
  for (int i = 0; i < q; i++) {
    cout << ans[i] << '\n';
  }
  return 0;
}