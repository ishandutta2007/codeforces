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

inline int fp(int i) {
        if(i == 2) return 2;
        if(i == 1) return 1;
        return !(i & 1);
}

int fi(int i) {
        if(i == 1) return 1;
        if(i == 2) return 0;
        if(i == 3) return 1;
        if(i == 4) return 2;
        if(i & 1) return 0;
        int s[3] = {1, 0, 0};
        s[fi(i >> 1)] = 1;
        if(s[1]) return 2;
        else return 1;
}

int main() {
        int i, n, k, x;
        scanf("%d %d", &n, &k);
        k = k & 1;
        int tot = 0;
        for(i = 0; i < n; i++) {
                scanf("%d", &x);
                if(k) tot ^= fi(x);
                else tot ^= fp(x);
        }
        if(tot) puts("Kevin");
        else puts("Nicky");
}