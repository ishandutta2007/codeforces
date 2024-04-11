#include <bits/stdc++.h>

using namespace std;

long long ans;
int a1 = -1, a2 = -1, a3 = -1, a4 = -1;

void test(long long value, int b1, int b2, int b3, int b4) {
  if (abs(value) < ans) {
    ans = abs(value);
    a1 = b1;
    a2 = b2;
    a3 = b3;
    a4 = b4;
  }
}

const int N = 4444;

pair <int, int> a[N], b[N];

int main() {
  int n;
  scanf("%d", &n);
  for (int i = 0; i < n; i++) {
    scanf("%d", &a[i].first);
    a[i].second = i + 1;
  }
  int m;
  scanf("%d", &m);
  for (int j = 0; j < m; j++) {
    scanf("%d", &b[j].first);
    b[j].second = j + 1;
  }
  long long sa = 0;
  for (int i = 0; i < n; i++) {
    sa += a[i].first;
  }
  long long sb = 0;
  for (int j = 0; j < m; j++) {
    sb += b[j].first;
  }
  sort(a, a + n);
  sort(b, b + m);
  long long diff = sb - sa;
  ans = abs(diff);
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < m; j++) {
      test(diff + 2 * (a[i].first - 0LL - b[j].first), a[i].second, b[j].second, -1, -1);
    }
  }
  vector < pair < int, pair <int, int> > > as, bs;
  for (int i = 0; i < n; i++) {
    for (int j = i + 1; j < n; j++) {
      as.push_back(make_pair(a[i].first + a[j].first, make_pair(a[i].second, a[j].second)));
    }
  }
  for (int i = 0; i < m; i++) {
    for (int j = i + 1; j < m; j++) {
      bs.push_back(make_pair(b[i].first + b[j].first, make_pair(b[i].second, b[j].second)));
    }
  }
  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());
  int nn = as.size();
  int mm = bs.size();
  int j = 0;
  for (int i = 0; i < nn; i++) {
    while (j < mm && diff + 2 * (as[i].first - 0LL - bs[j].first) > 0) {
      j++;
    }
    if (j < mm) {
      test(diff + 2 * (as[i].first - 0LL - bs[j].first), as[i].second.first, bs[j].second.first, as[i].second.second, bs[j].second.second);
    }
    if (j - 1 >= 0) {
      j--;
      test(diff + 2 * (as[i].first - 0LL - bs[j].first), as[i].second.first, bs[j].second.first, as[i].second.second, bs[j].second.second);
      j++;
    }
  }
  cout << ans << endl;
  if (a1 == -1) {
    cout << 0 << endl;
    return 0;
  }
  if (a3 == -1) {
    cout << 1 << endl;
    cout << a1 << " " << a2 << endl;
    return 0;
  }
  cout << 2 << endl;
  cout << a1 << " " << a2 << endl;
  cout << a3 << " " << a4 << endl;
  return 0;
}