#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
#define for_tests(t, tt) int t; scanf("%d", &t); for(int tt = 1; tt <= t; tt++)
template<typename T> inline T abs(T t) { return t < 0? -t : t; }
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }

int dif, c[1000009], a[500009], k;
inline bool ok(int x) { return c[x] || dif < k; }
inline void rem(int x) { dif -= ((--c[x]) == 0); }
inline void add(int x) { dif += ((++c[x]) == 1); }

int main() {
   int i, n;
   scanf("%d %d", &n, &k);
   for(i = 0; i < n; i++)
       scanf("%d", &a[i]);
   c[a[0]] = 1;
   dif = 1;
   int r = 0;
   int b = 0, bi;
   for(i = 0; i < n; i++) {
       if(i) rem(a[i - 1]);
       while(r + 1 < n && ok(a[r + 1])) add(a[++r]);
       if(r - i + 1 > b) b = r - i + 1, bi = i;
   }
   printf("%d %d\n", bi + 1, bi + b);
}