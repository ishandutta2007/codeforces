#include <bits/stdc++.h>
using namespace std;

const int maxn = 100000 + 5;
int N, l[maxn], r[maxn], L, R;

int main() {
  cin >> N;
  for (int i = 1; i <= N; ++i) cin >> l[i] >> r[i], L += l[i], R += r[i];
  int beauty = abs(L - R), best = 0;
  for (int i = 1; i <= N; ++i) {
    int tL = L + r[i] - l[i], tR = R + l[i] - r[i];
    if (abs(tL - tR) > beauty) best = i, beauty = abs(tL - tR);
  }
  cout << best << '\n';
  return 0;
}