#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int a[100050], nxt[100050], cnt[100050], id[100050], lst[100050];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int n, q;
  cin >> n >> q;

  const int BLOCK = 400;
  for (int i = 0; i < n; i++) {
    cin >> a[i], id[i] = i / BLOCK;
  }

	for (int i = n - 1; i >= 0; i--) {
		if (i + a[i] >= n || id[i] != id[i + a[i]]) {
			cnt[i] = 1;
			nxt[i] = i + a[i];
      lst[i] = i;
		} else {
			cnt[i] = cnt[i + a[i]] + 1;
			nxt[i] = nxt[i + a[i]];
      lst[i] = lst[i + a[i]];
    }
 	}

  function<void(int)> Update = [&](int x) {
    for (int i = (x + 1) * BLOCK - 1; i >= x * BLOCK; i--) {
      if (i + a[i] >= n || id[i] != id[i + a[i]]) {
  			cnt[i] = 1;
  			nxt[i] = i + a[i];
        lst[i] = i;
  		} else {
  			cnt[i] = cnt[i + a[i]] + 1;
  			nxt[i] = nxt[i + a[i]];
        lst[i] = lst[i + a[i]];
  		}
    }
  };

	while (q--) {
		int foo;
		cin >> foo;

		if (foo == 0) {
			int i, b;
			cin >> i >> b;
      --i;

      a[i] = b;
      Update(id[i]);
		} else {
      int x;
      cin >> x;
      --x;

      int ans = 0, gde = x;
      while (x < n) {
        ans += cnt[x];
        gde = lst[x];
        x = nxt[x];
      }
      cout << gde + 1 << " " << ans << '\n';
		}
	}
}