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
    int n, i, j, a, b, c;
    scanf("%d %d %d %d", &n, &a, &b, &c);
    int mx = 0;
    for(i = 0; a * i <= n; i++)
        for(j = 0; a * i + b * j <= n; j++) {
            if((n - a * i - b * j) % c) continue;
            mx = max(mx, i + j + (n - a * i - b * j) / c);
        }
    printf("%d\n", mx);
}