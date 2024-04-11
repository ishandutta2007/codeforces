#include <bits/stdc++.h>

using namespace std;

const int N = 1000010;

vector <int> b[N];
pair <int, int> e[N];
int a[N], s[N];
int pr[N], ne[N];

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  for (int i = 1; i <= n; i++) {
    scanf("%d", a + i);
  }
  s[0] = 0;
  for (int i = 1; i <= n; i++) {
    s[i] = (s[i - 1] + a[i]) % k;
  }
  for (int z = 0; z < k; z++) {
    b[z].clear();
  }
  for (int i = 0; i <= n; i++) {
    b[s[i]].push_back(i);
  }
  for (int i = 1; i <= n; i++) {
    e[i - 1] = make_pair(a[i], i);
  }
  sort(e, e + n);
  for (int i = 0; i <= n + 1; i++) {
    pr[i] = i - 1;
    ne[i] = i + 1;
  }
  long long ans = 0;
  for (int id = 0; id < n; id++) {
    int i = e[id].second;
    int what = a[i] % k;
    int from = pr[i] + 1;
    int to = ne[i] - 1;
    if (i - from < to - i) {
      for (int pos = from; pos <= i; pos++) {
        int z = s[pos - 1] + what;
        if (z >= k) {
          z -= k;
        }
        ans += lower_bound(b[z].begin(), b[z].end(), to + 1) - lower_bound(b[z].begin(), b[z].end(), i);
      }
    } else {
      for (int pos = i; pos <= to; pos++) {
        int z = s[pos] - what;
        if (z < 0) {
          z += k;
        }
        ans += lower_bound(b[z].begin(), b[z].end(), i) - lower_bound(b[z].begin(), b[z].end(), from - 1);
      }
    }
    pr[ne[i]] = pr[i];
    ne[pr[i]] = ne[i];
  }
  cout << (ans - n) << endl;
  return 0;
}