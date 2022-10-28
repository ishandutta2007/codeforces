#include <bits/stdc++.h>
using namespace std;

const int N = 100'000 + 1;

int mapping_n[N];
int mapping_p[N];

bool suffix[N];
bool sign[N];
int a[N];

array<int, 2> events[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, q;
  cin >> n >> q;

  for (int i = 0; i < n; ++i) {
    cin >> a[i];
  }

  for (int i = 0; i < q; ++i) {
    int x;
    char c;
    cin >> c >> x;
    sign[i] = (c == '<');

    if (sign[i] ^ (x < 0)) {
      suffix[i] = true;
    }
    events[i] = {abs(x) + !suffix[i], i};
  }

  for (int i = q - 1; i >= 0; --i) {
    suffix[i] ^= suffix[i + 1];
  }

  int ptr = 0;
  int last = -1;
  bool force = false;
  sort(events, events + q);

  for (int i = 1; i < N; ++i) {
    while (ptr < q && events[ptr][0] <= i) {
      int index = events[ptr][1];
      if (index > last) {
        last = index;
        force = sign[index];
      }
      ++ptr;
    }

    if (last == -1) {
      mapping_p[i] = suffix[0] ^ true;
      mapping_n[i] = suffix[0];
    } else {
      mapping_p[i] = force ^ suffix[last + 1];
      mapping_n[i] = force ^ suffix[last + 1];
    }
  }

  for (int i = 0; i < n; ++i) {
    bool positive = (a[i] > 0) ? mapping_p[a[i]] : mapping_n[-a[i]];
    cout << (positive ? abs(a[i]) : -abs(a[i])) << " ";
  }
  cout << "\n";
}