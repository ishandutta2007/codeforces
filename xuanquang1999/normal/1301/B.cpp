#include <bits/stdc++.h>

using namespace std;

const int MAXN = 100005;
const int oo = 1000000007;

int n, a[MAXN];

int main() {
  int nTest;
  scanf("%d", &nTest);

  while (nTest--) {
    scanf("%d", &n);
    for(int i = 0; i < n; ++i) 
      scanf("%d", &a[i]);

    int lo = oo, hi = 0;
    for(int i = 0; i < n; ++i) {
      if (a[i] == -1) {
        if (i > 0 && a[i-1] != -1) {
          lo = min(lo, a[i-1]);
          hi = max(hi, a[i-1]);
        }
        if (i < n-1 && a[i+1] != -1) {
          lo = min(lo, a[i+1]);
          hi = max(hi, a[i+1]);
        }
      }
    }

    if (hi == 0) {
      lo = 0;      
    }

    int ansK = (lo + hi) / 2;
    for(int i = 0; i < n; ++i)
      if (a[i] == -1)
        a[i] = ansK;

    int ansM = 0;
    for(int i = 1; i < n; ++i)    
      ansM = max(ansM, abs(a[i] - a[i-1]));
    
    printf("%d %d\n", ansM, ansK);
  }

  return 0;
}