// Author: wlzhouzhuan
#pragma GCC optimize(2)
#pragma GCC optimize(3)
#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ull unsigned long long
#define pii pair<int, int>
#define pb push_back
#define fir first
#define sec second
#define rep(i, l, r) for (int i = l; i <= r; i++)
#define per(i, l, r) for (int i = l; i >= r; i--)
#define mset(s, t) memset(s, t, sizeof(s))
#define mcpy(s, t) memcpy(s, t, sizeof(t))
template<typename T1, typename T2> void ckmin(T1 &a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> void ckmax(T1 &a, T2 b) { if (a < b) a = b; }
int read() {
  int x = 0, f = 0; char ch = getchar();
  while (!isdigit(ch)) f |= ch == '-', ch = getchar();
  while (isdigit(ch)) x = 10 * x + ch - '0', ch = getchar();
  return f ? -x : x;
}
template<typename T> void print(T x) {
  if (x < 0) putchar('-'), x = -x;
  if (x >= 10) print(x / 10);
  putchar(x % 10 + '0');
}
template<typename T> void print(T x, char let) {
  print(x), putchar(let);
}

const int table[29][6] = {
{1, 0, 0, 1, 0},
{1, 1, 0, 2, 0},
{2, 0, 0, 1, 1},
{2, 1, 0, 1, 2},
{1, 1, 0, 1, 1},
{2, 1, 0, 2, 1}, // f
{2, 2, 0, 2, 2},
{1, 2, 0, 2, 1},
{1, 1, 0, 1, 1},
{1, 2, 0, 1, 2},
{1, 0, 1, 2, 0}, // k
{1, 1, 1, 3, 0},
{2, 0, 1, 2, 1},
{2, 1, 1, 2, 2}, // n
{1, 1, 1, 2, 1},
{2, 1, 1, 3, 1},
{2, 2, 1, 3, 2}, // q
{1, 2, 1, 3, 1}, // r
{1, 1, 1, 2, 1}, // s
{1, 2, 1, 2, 2},
{1, 0, 2, 2, 1},
{1, 1, 2, 3, 1},
{1, 2, 1, 1, 3},
{2, 0, 2, 2, 2},
{2, 1, 2, 2, 3},
{1, 1, 2, 2, 2}, // z
};

int main() {
  int t = read();
  while (t--) {
    int a = read(), b=read(),c=read(),d=read(),e=read();
    for(int i=0;i<26;i++){
      if(table[i][0]==a&&table[i][1]==b&&table[i][2]==c&&table[i][3]==d&&table[i][4]==e){
        printf("%c",'a'+i);
        break; 
      }
    }
  }
  puts("");
}