#include <iostream>
#include <algorithm>
using namespace std;

const int maxn = 100 + 5;
int n, A[maxn], B[maxn];

int main() {
  cin >> n;
  for (int i = 1; i <= n; ++i) cin >> A[i];
  while (true) {
    bool p = false;
    int st, ed = n;
    int i = 1;
    while (i < n) {
      if (A[i] > A[i + 1]) {
        st = i;
        p = true;
        i += 2;
        while (i <= n) {
          if (A[i] < A[i + 1]) { ed = i - 1; break; }
          i += 2;
        }
        break;
      }
      i++;
    }
    if (!p) break;
    p = false;
    if ((ed - st + 1) & 1) ed--;
    cout << st << ' ' << ed << '\n';
    // return 0;
    for (int i = st; i <= ed; i += 2) swap(A[i], A[i + 1]);
  }
  return 0;
}