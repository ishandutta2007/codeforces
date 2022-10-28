#include <bits/stdc++.h>
using namespace std;

const int N = 100'000;

long long a[N];
int l;

map<int, int> segments;

void update(int i, int x) {
  if (a[i] > l) {
    return;
  }
  a[i] += x;
  if (a[i] <= l) {
    return;
  }

  auto prv = segments.upper_bound(i);
  auto nxt = prv;

  int finish = i + 1;
  int start = i;

  if (prv != segments.begin() && (--prv)->second == start) {
    start = prv->first;
    segments.erase(prv);
  }

  if (nxt != segments.end() && nxt->first == finish) {
    finish = nxt->second;
    segments.erase(nxt);
  }

  segments[start] = finish;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, m;
  cin >> n >> m >> l;

  for (int i = 0; i < n; ++i) {
    int x;
    cin >> x;
    update(i, x);
  }

  while (m--) {
    int type;
    cin >> type;

    if (type == 0) {
      cout << segments.size() << "\n";
    } else {
      int i, x;
      cin >> i >> x;
      update(i - 1, x);
    }
  }
}