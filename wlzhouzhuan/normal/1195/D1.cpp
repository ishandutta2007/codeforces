%:pragma GCC optimize(2)
%:pragma GCC optimize(3)
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define lll __int128
#define dd double
#define _i int
#define RE register
#define rep(i, l, r) for (RE int i = l; i <= r; i++)
#define req(i, l, r) for (RE int i = l; i >= r; i--)
#define range(i, l, r) rep(i, l, r - 1)
#define Be(s, t) memset(s, t, sizeof(s))
#define poly vector <int>
#define pii pair <int, int>
template <typename T> void read(T &x) { x = 0; int FF = 1; char op = getchar(); while (!isdigit(op)) { if (op == '-') FF = -1; op = getchar(); } while (isdigit(op)) { x = (x << 1) + (x << 3) + op - '0'; op = getchar(); } x *= FF; }
template <typename T> void print(T x) { if (x < 0) { putchar('-'); x = -x; } if (x < 1) return ; print(x / 10); putchar(x % 10 + '0'); }
template <typename T> void print(T x, char _tab) { print(x); putchar(_tab); }

#define int long long
const int N = 100005;
const int mod = 998244353;

int a[N], len[N], sub[100];
ll s[N];
int n;

void print() {
  for (int i = 1; i <= 5; i++)
    printf("%d ", s[i]); printf("\n");
}

signed main() {
  scanf("%lld", &n);
  for (int i = 1; i <= n; i++) {
    scanf("%lld", &a[i]);
    if (a[i] == 0) len[i] = 1;
    else len[i] = (int)log10(a[i]) + 1;
    //printf("%d\n", len[i]);
    sub[len[i]]++; 
  } 
  /*
  for (int i = 1; i <= 10; i++)
    printf("%d ", sub[i]);
  printf("\n");
  */
  for (int i = 1; i <= n; i++) {
    //memset(s, 0, sizeof(s));
    int b = a[i];
    for (int l = 1; l <= 11; l++) {
      //if (sub[l] == 0) continue; 
      int pp = 1;
      if (l >= len[i]) {
        while (a[i] > 0) {
          s[pp] += sub[l] * (a[i] % 10);
          a[i] /= 10; pp += 2;
        }
      }
      else {
        for (int p = 1; p <= l; p++) {
          s[pp] += sub[l] * (a[i] % 10);
          a[i] /= 10; pp += 2; 
        }
        int times = len[i] - l;
        for (int p = 1; p <= times; p++) {
          s[pp] += sub[l] * (a[i] % 10);
          a[i] /= 10; pp++;
        }
      }
      a[i] = b;
      
      //assert(pp <= 20);
    }
    //print();
    //putchar('\n');
    //memset(s, 0, sizeof(s));
    //memset(s, 0, sizeof(s));
    
    for (int l = 1; l <= 11; l++) {
      //if (sub[l] == 0) continue; 
      int pp = 2;
      if (l >= len[i]) {
        while (a[i] > 0) {
          s[pp] += sub[l] * (a[i] % 10);
          a[i] /= 10; pp += 2;
        }
      }
      else {
        for (int p = 1; p < l; p++) {
          s[pp] += sub[l] * (a[i] % 10);
          a[i] /= 10; pp += 2;
        }
        int times = len[i] - l + 1;
        for (int p = 1; p <= times; p++) {
          s[pp] += sub[l] * (a[i] % 10);
          a[i] /= 10; pp++;
        }
      }
      a[i] = b;
    }
    
   // print();
    //system("pause");
  }
  
  long long ans = 0;
  for (int i = 25; i >= 1; i--)
    ans = (10 * ans + s[i]) % mod;
  printf("%lld\n", ans);
  return 0;
}