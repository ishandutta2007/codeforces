#include <bits/stdc++.h>
using namespace std;

const int maxn = 50 + 5;
int n, L, a[maxn], b[maxn];

int main() {
  cin >> n >> L;
  for (int i = 0; i < n; ++i) cin >> a[i];
  for (int i = 0; i < n; ++i) cin >> b[i];
  for (int i = 0; i < L; ++i) {
    for (int j = 0; j < L; ++j) {
      vector<int> aa, bb;
      for (int k = 0; k < n; ++k) {
        int A = i + a[k];
        if (A >= L) A -= L;
        int B = j + b[k];
        if (B >= L) B -= L;
        // if (A != B) yes = false;
        aa.push_back(A); bb.push_back(B);
      }
      sort(aa.begin(), aa.end());
      sort(bb.begin(), bb.end());
      if (aa == bb) { cout << "YES\n"; return 0; }
    }
  }
  cout << "NO\n";
  return 0;
}