#include <bits/stdc++.h>
using namespace std;

int N, M;
int Cnt[1005][5], A[1005];

int main() {
  cin >> N >> M;
  for (int i = 1; i <= N; ++i) {
    string str;
    cin >> str;
    for (int j = 0; j < M; ++j)
      Cnt[j + 1][str[j] - 'A']++;
  }
  for (int i = 1; i <= M; ++i) cin >> A[i];
  int ans = 0;
  for (int i = 1; i <= M; ++i) {
    sort(Cnt[i], Cnt[i] + 5);
    ans += Cnt[i][4] * A[i];
  }
  cout << ans << endl;
  return 0;
}