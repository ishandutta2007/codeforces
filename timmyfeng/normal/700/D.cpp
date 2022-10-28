#include <bits/stdc++.h>
using namespace std;

const int N = 100000 + 1;
const int B = 800;

array<int, 3> query[N];
int a[N];

int occurences[N];
int freq[N];

void add(int i, int j) {
  --freq[occurences[a[i]]];
  occurences[a[i]] += j;
  ++freq[occurences[a[i]]];
}

int in_que[B];
int ans[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int n;
  cin >> n;
  vector<int> heavy;
  for (int i = 1; i <= n; ++i) {
    cin >> a[i];
    if (++occurences[a[i]] == B) {
      heavy.push_back(a[i]);
    }
  }

  fill(occurences, occurences + N, 0);
  freq[0] = N;

  int q;
  cin >> q;
  for (int i = 0; i < q; ++i) {
    cin >> query[i][0] >> query[i][1];
    query[i][2] = i;
  }

  sort(query, query + q, [&](array<int, 3> a, array<int, 3> b) {
    return a[0] / B == b[0] / B ? a[1] < b[1] : a[0] < b[0];
  });

  int l = 1, r = 0;
  for (int i = 0; i < q; ++i) {
    while (l > query[i][0]) add(--l, 1);
    while (r < query[i][1]) add(++r, 1);
    while (l < query[i][0]) add(l++, -1);
    while (r > query[i][1]) add(r--, -1);

    int res = 0, extra = 0;
    priority_queue<int, vector<int>, greater<int>> que;
    for (auto j : heavy) {
      if (occurences[j] >= B) {
        que.push(occurences[j]);
      }
    }

    for (int j = 1; j < B; ++j) {
      in_que[j] += freq[j];
      if (in_que[j] > 0) {
        if (extra) {
          res += j + extra;
          if (j + extra < B) {
            ++in_que[j + extra];
          } else {
            que.push(j + extra);
          }
          --in_que[j];
          extra = 0;
        }

        if (in_que[j] % 2 == 1) {
          --in_que[j];
          extra = j;
        }

        res += j * in_que[j];
        if (2 * j < B) {
          in_que[2 * j] += in_que[j] / 2;
        } else {
          for (int k = 0; k < in_que[j] / 2; ++k) {
            que.push(2 * j);
          }
        }
        in_que[j] = 0;
      }
    }

    if (extra > 0) {
      que.push(extra);
    }

    while (que.size() > 1) {
      int a = que.top();
      que.pop();
      int b = que.top();
      que.pop();
      res += a + b;
      que.push(a + b);
    }

    ans[query[i][2]] = res;
  }

  for (int i = 0; i < q; ++i) {
    cout << ans[i] << "\n";
  }
}