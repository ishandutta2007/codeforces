#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define eprintf(...) fprintf(stderr, __VA_ARGS__)
#else
#define eprintf(...) 42
#endif

const int N = (int)1e5 + 10;
int ors[N], ands[N];
int a[N];
int target[N];

int query(int type, int a, int b) {
  /*
  return type == 0 ? (target[a] | target[b]) : (target[a] & target[b]);
  */
  cout << (type == 0 ? "or" : "and") << " " << a + 1 << " " << b + 1 << endl;
  int result;
  cin >> result;
  return result;
}

void finish(int x) {
  cout << "finish " << x << endl;
}

int main() {
#ifdef LOCAL
//  freopen("input.txt", "r", stdin);
#endif

  int n, k;
  cin >> n >> k;

  /*
  for (int i = 0; i < n; i++) {
    cin >> target[i];
  }
  */

  for (int i = 1; i < n; i++) {
    ors[i] = query(0, 0, i);
    ands[i] = query(1, 0, i);
  }
  int help_or = query(0, 1, 2);
  int help_and = query(1, 1, 2);

  for (int b = 30; b >= 0; b--) {
    int current_bit = -1;
    for (int i = 1; i < n; i++) {
      if ((ors[i] & (1 << b)) == 0) {
        current_bit = 0;
      } else if ((ands[i] & (1 << b)) != 0) {
        current_bit = 1;
      }
    }
    if (current_bit == -1) {
      if ((help_and & (1 << b)) != 0) {
        current_bit = 0;
      } else {
        current_bit = 1;
      }
    }
    a[0] |= (current_bit << b);
    for (int i = 1; i < n; i++) {
      int value = (current_bit == 0 ? ors[i] : ands[i]);
      value = (value >> b) & 1;
      a[i] |= (value << b);
    }
  }
  for (int i = 0; i < n; i++) {
    eprintf("%d ", a[i]);
  }
  eprintf("\n");
  nth_element(a, a + k - 1, a + n);
  finish(a[k - 1]);

  return 0;
}