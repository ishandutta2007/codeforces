#include <bits/stdc++.h>
using namespace std;
#define fst first
#define snd second
typedef unsigned long long ull;
typedef long long ll;
typedef pair<int, int> pii;
#define pb push_back
const ll modn = 1000000007;
inline ll mod(ll x) { return x % modn; }
#ifdef ONLINE_JUDGE
#       define LLD "%I64d"
#       define debug(args...) {}
#else
#       define LLD "%lld"
#       define debug(args...) fprintf(stderr, args)
#endif

int main() {
        int i, j, n, a, b, c, d;
        scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
        ll tot = 0;
        for(i = 1; i <= n; i++)
                if(b - c + i >= 1 && b - c + i <= n &&
                        a - d + i >= 1 && a - d + i <= n &&
                        b - c + a - d + i >= 1 && b - c + a - d + i <= n)
                        tot += n;
        printf(LLD "\n", tot);
}