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

ll fexp(ll p, ll e) {
        ll r = 1;
        for(; e; e >>= 1) {
                if(e & 1) r = mod(r * p);
                p = mod(p * p);
        }
        return r;
}

void solve0(ll p) {
        printf("%d\n", (int) fexp(p, p - 1));
        exit(0);
}

const int N = 1000009;
int nu[N], ct[N], seen[N]; bool head[N];
int main() {
        int i, j, p, k;
        scanf("%d %d", &p, &k);
        if(k == 0) solve0(p);
        for(i = 0; i < p; i++) {
                if(seen[i]) continue;
                int j = i, sz = 0;
                while(!seen[j]) {
                        seen[j] = 1;
                        sz++;
                        j = int((ll(j) * ll(k)) % ll(p));
                }
                head[i] = true;
                seen[i] = sz;
                nu[sz] += sz;
        }
        for(i = 1; i <= p; i++) {
                if(!nu[i]) continue;
                for(j = i; j <= p; j += i)
                        ct[j] += nu[i];
        }
        ll tot = 1;
        for(i = 0; i < p; i++) {
                if(!head[i]) continue;
                tot = mod(tot * ll(ct[seen[i]]));
        }
        printf("%d\n", (int) tot);
}