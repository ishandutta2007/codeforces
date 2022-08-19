#include <bits/stdc++.h>

using namespace std;

const int N = 1234567;

vector <int> g[N];
int cap[N];
bool was[N];
int x[N];
vector <int> yes, no;

int main() {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  for (int i = 0; i < k; i++) {
    int foo;
    scanf("%d", &foo);
    foo--;
    cap[foo] = 1;
  }
  for (int i = 0; i < m; i++) {
    int foo, bar;
    scanf("%d %d", &foo, &bar);
    foo--; bar--;
    g[foo].push_back(bar);
    g[bar].push_back(foo);
  }
  for (int i = 0; i < n; i++) {
    was[i] = false;
  }
  for (int i = 0; i < n; i++) {
    if (was[i]) {
      continue;
    }
    int b = 0, e = 1;
    x[0] = i;
    was[i] = true;
    while (b < e) {
      for (int j = 0; j < (int) g[x[b]].size(); j++) {
        int u = g[x[b]][j];
        if (!was[u]) {
          x[e] = u;
          was[u] = true;
          e++;
        }
      }
      b++;
    }
    int have = 0;
    for (int j = 0; j < e; j++) {
      have += cap[x[j]];
    }
    if (have) {
      yes.push_back(e);
    } else {
      no.push_back(e);
    }
  }
  int all_no = 0;
  int max_yes = 0;
  for (int i = 0; i < (int) yes.size(); i++) {
    max_yes = max(max_yes, yes[i]);
  }
  for (int i = 0; i < (int) no.size(); i++) {
    all_no += no[i];
  }
  long long ans = 0;
  for (int i = 0; i < (int) yes.size(); i++) {
    if (yes[i] == max_yes) {
      yes[i] += all_no;
      max_yes = -1;
    }
    ans += yes[i] * 1LL * (yes[i] - 1) / 2;
  }
  cout << (ans - m) << endl;
  return 0;
}