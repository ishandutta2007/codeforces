#include <bits/stdc++.h>
#pragma GCC optimize("O3")
using namespace std;
typedef long long ll;
typedef long double ld;
#define int ll
#define F first
#define S second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define SZ(x) (int)x.size()
#define pii pair<int, int>
const int MOD = 1e9 + 7;

const int N = 27;
int len1[N], len2[N][N], len3[N][N][N], calc[N][N][N];

void source() {
  string t;
  cin >> t;
  int n = SZ(t);
  for (int i = 1; i <= 26; i++) {
    len1[i] = n / 26 + (n % 26 >= i);
  }
  for (int i = 1; i <= 26; i++) {
    int sum = 0;
    for (int j = 1; j <= 26; j++) {
      len2[i][j] = len1[i] / 26 + (len1[i] % 26 >= j);
      sum += len2[i][j];
    }
    assert(sum == len1[i]);
  }
  for (int i = 1; i <= 26; i++) {
    for (int j = 1; j <= 26; j++) {
      for (int k = 1; k <= 26; k++) {
        len3[i][j][k] = len2[i][j] / 26 + (len2[i][j] % 26 >= k);
      }
    }
  }
  string s1, s2, s3;
  for (int i = 1; i <= 26; i++) {
    for (int j = 0; j < len1[i]; j++) {
      s1 += char('a' + i - 1);
    }
  }
  for (int i = 1; i <= 26; i++) {
    for (int j = 1; j <= 26; j++) {
      for (int k = 0; k < len2[i][j]; k++) {
        s2 += char('a' + j - 1);
      }
    }
  }
  for (int i = 1; i <= 26; i++) {
    for (int j = 1; j <= 26; j++) {
      for (int k = 1; k <= 26; k++) {
        for (int p = 0; p < len3[i][j][k]; p++) {
          s3 += char('a' + k - 1);
        }
      }
    }
  }
  int pos = 0;
  for (int i = 1; i <= 26; i++) {
    int pos2 = pos;
    for (int j = 1; j <= 26; j++) {
      int pos3 = pos2;
      for (int k = 1; k <= 26; k++) {
        calc[i][j][k] = pos3;
        pos3 += len3[i][j][k];
      }
      pos2 += len2[i][j];
    }
    pos += len1[i];
  }
  cout << "? " << s1 << endl;
  string ans1, ans2, ans3;
  cin >> ans1; 
  cout << "? " << s2 << endl;
  cin >> ans2;
  cout << "? " << s3 << endl;
  cin >> ans3;
  string ans = t;
  for (int i = 0; i < n; i++) {
    ans[calc[ans1[i] - 'a' + 1][ans2[i] - 'a' + 1][ans3[i] - 'a' + 1]] = t[i];
  }
  cout << "! " << ans << endl;
}

signed main() {
#ifdef extraterrestrial_
  assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#else
#define TASK ""
  //assert(freopen(TASK".in", "r", stdin));
  //assert(freopen(TASK".out", "w", stdout));
  //assert(freopen("input.txt", "r", stdin));
  //assert(freopen("output.txt", "w", stdout));
#endif
  ios_base::sync_with_stdio(0);
  cin.tie(0);
  cout.tie(0);
  source();
  return 0;
}