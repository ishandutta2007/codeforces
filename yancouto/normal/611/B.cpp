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

ll x;
ll memo[64][2][2][2];
ll solve(int i, bool has, bool pre, bool lead) {
        if(i < 0) return has;
        ll &r = memo[i][has][pre][lead];
        if(r != -1) return r;
        r = 0;
        if(!pre || ((1ll << i) & x)) r = solve(i - 1, has, pre && ((1ll << i) & x), false);
        if(!has || lead) r += solve(i - 1, !lead, pre && !((1ll << i) & x) , lead);
        return r;
}

ll ans(ll a) {
        x = a;
        memset(memo, -1, sizeof memo);
        return solve(61, 0, true, true);
}

int main() {
        ll a, b;
        scanf("%I64d %I64d", &a, &b);
        printf("%I64d\n", ans(b) - ans(a - 1));
}