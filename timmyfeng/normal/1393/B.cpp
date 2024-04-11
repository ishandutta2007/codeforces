#include <bits/stdc++.h>
using namespace std;

const int A = 1e5 + 1;

int cnt2, cnt4, cnt6, cnt8;
int cnt[A];

void update(int a, int d) {
  if (d == -1) {
    cnt8 -= (cnt[a] == 8);
    cnt6 -= (cnt[a] == 6);
    cnt4 -= (cnt[a] == 4);
    cnt2 -= (cnt[a] == 2);
  }
  cnt[a] += d;
  if (d == 1) {
    cnt8 += (cnt[a] == 8);
    cnt6 += (cnt[a] == 6);
    cnt4 += (cnt[a] == 4);
    cnt2 += (cnt[a] == 2);
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int a;
    cin >> a;
    update(a, 1);
  }

  int q;
  cin >> q;
  while (q--) {
    char c;
    int a;
    cin >> c >> a;

    if (c == '-') {
      update(a, -1);
    } else {
      update(a, 1);
    }

    cout << (cnt8 >= 1 || (cnt6 >= 1 && cnt2 >= 2) || (cnt4 >= 1 && cnt2 >= 3) || cnt4 >= 2 ? "YES" : "NO") << "\n";
  }
}