#include <bits/stdc++.h>
using namespace std;

mt19937 rng((unsigned long long) new char);

int rand_int(int a, int b) {
  return uniform_int_distribution<int>(a, b)(rng);
}

const int N = 1 << 18;
const int Q = 420;

int query(int a, int b, int c) {
  cout << "? " << a << " " << b << " " << c << endl;
  int res;
  cin >> res;
  return res;
}

int indices[N];
int freq[N];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);

  int h;
  cin >> h;
  int n = (1 << h) - 1;

  for (int i = 0; i < Q; ++i) {
    int a = rand_int(1, n);
    int b = rand_int(1, n);
    int c = rand_int(1, n);
    if (a == b || a == c || b == c) {
      --i;
      continue;
    }

    int u = query(a, b, c);
    if (u != a && u != b && u != c) {
      ++freq[u];
    }
  }

  int u = 0, v = 0;
  for (int i = 1; i <= n; ++i) {
    if (freq[i] > freq[u]) {
      v = u, u = i;
    } else if (freq[i] > freq[v]) {
      v = i;
    }
  }

  for (int i = 1; i <= n; ++i) {
    if (i != u && i != v) {
      if (query(u, v, i) == i) {
        cout << "! " << i << endl;
        exit(0);
      }
    }
  }
}