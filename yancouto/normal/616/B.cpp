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

int main() {
   int i, j, n, m, x;
   scanf("%d %d", &n, &m);
   int b = INT_MIN;
   for(i = 0; i < n; i++) {
       int p = INT_MAX;
       for(j = 0; j < m; j++) {
           scanf("%d", &x);
           p = min(p, x);
       }
       b = max(b, p);
   }
   printf("%d\n", b);
}