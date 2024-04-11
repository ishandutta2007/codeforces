#include <bits/stdc++.h>

using namespace std;

const int N = 300010;

const int MAGIC = 500;

const int LONGS = N / MAGIC + 10;

char foo[N];

string s[LONGS]; 
int cost[LONGS];

int a[N][29];
int value[N];
int p[N];

int main() {
  int tt;
  scanf("%d", &tt);
  int n = 1;
  int cnt = 0;
  while (tt--) {
    int type;
    scanf("%d %s", &type, foo);
    int len = strlen(foo);
    if (type == 1 || type == 2) {
      if (len <= MAGIC) {
        int t = 1;
        for (int j = 0; j < len; j++) {
          int c = foo[j] - 'a';
          if (a[t][c] == 0) {
            a[t][c] = ++n;
          }
          t = a[t][c];
        }
        value[t] += 3 - 2 * type;
      } else {
        s[cnt] = "";
        for (int j = 0; j < len; j++) {
          s[cnt] += foo[j];
        }
        s[cnt] += "{";
        cost[cnt] = 3 - 2 * type;
        cnt++;
      }
    } else {
      long long ans = 0;
      for (int j = 0; j < len; j++) {
        int t = 1;
        for (int k = j; k < len; k++) {
          int c = foo[k] - 'a';
          if (a[t][c] == 0) {
            break;
          }
          t = a[t][c];
          ans += value[t];
        }
      }
      for (int id = 0; id < cnt; id++) {
        int long_len = s[id].length();
        long_len--;
        if (long_len > len) {
          continue;
        }
        int k = 0;
        p[1] = 0;
        for (int i = 2; i <= long_len; i++) {
          while (k > 0 && s[id][i - 1] != s[id][k]) {
            k = p[k];
          }
          if (s[id][i - 1] == s[id][k]) {
            k++;
          }
          p[i] = k;
        }
        k = 0;
        for (int i = 1; i <= len; i++) {
          while (k > 0 && foo[i - 1] != s[id][k]) {
            k = p[k];
          }
          if (foo[i - 1] == s[id][k]) {
            k++;
          }
          if (k == long_len) {
            ans += cost[id];
          }
        }
      }
      cout << ans << endl;
    }
  }
  return 0;
}