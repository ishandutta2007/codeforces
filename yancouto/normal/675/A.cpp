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
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        bool ok = false;
        if(c > 0) ok = (b >= a && ((b - a) % c) == 0);
        else if(c == 0) ok = b == a;
        else ok = (b <= a && ((a - b) % (-c)) == 0);
        if(ok) puts("YES");
        else puts("NO");
}