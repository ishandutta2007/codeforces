#include <bits/stdc++.h>
using namespace std;

string a, b, c, ans;
int cnt[3][26], B, C, MaxA, MaxB;

int main() {
  ios_base::sync_with_stdio(false); cin.tie(nullptr);
  cin >> a >> b >> c;
  B = INT_MAX; C = INT_MAX;
  for (int i = 0; i < a.length(); ++i) cnt[0][a[i] - 'a']++;
  for (int i = 0; i < b.length(); ++i) cnt[1][b[i] - 'a']++;
  for (int i = 0; i < c.length(); ++i) cnt[2][c[i] - 'a']++;
  for (int i = 0; i < 26; ++i) {
    if (cnt[1][i]) B = min(B, cnt[0][i] / cnt[1][i]);
    if (cnt[2][i]) C = min(C, cnt[0][i] / cnt[2][i]);
  }
  if (B == INT_MAX) B = 0;
  if (C == INT_MAX) C = 0;
  if (C > B) swap(B, C), swap(b, c), swap(cnt[1], cnt[2]);
  for (int i = 0; i <= B; ++i) {
    int jizz = INT_MAX;
    for (int j = 0; j < 26; ++j) {
      if (cnt[2][j]) jizz = min(jizz, (cnt[0][j] - cnt[1][j] * i) / cnt[2][j]);
    }
    if (jizz == INT_MAX) jizz = 0;
    if (jizz + i > MaxA + MaxB) MaxA = i, MaxB = jizz;
  }
  for (int i = 0; i < MaxA; ++i) ans += b;
  for (int i = 0; i < MaxB; ++i) ans += c;
  for (int i = 0; i < b.length(); ++i) cnt[0][b[i] - 'a'] -= MaxA;
  for (int i = 0; i < c.length(); ++i) cnt[0][c[i] - 'a'] -= MaxB;
  for (int i = 0; i < 26; ++i) while (cnt[0][i]--) ans += (char)(i + 'a');
  cout << ans << '\n';
  return 0;
}