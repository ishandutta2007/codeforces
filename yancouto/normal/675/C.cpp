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
const int N = 212345;
ll a[N];

int main() {
        int i, j, n;
        scanf("%d", &n);
        for(i = 0; i < n; i++)
                scanf(LLD, &a[i]);
        for(i = n; i < 2*n; i++)
                a[i] = a[i - n];
        for(i = 1; i < 2*n; i++)
                a[i] += a[i - 1];
        map<ll, int> ct;
        int mn = INT_MAX;
        for(i = 0; i < 2 * n; i++) {
                ct[a[i]]++;
                if(i >= n) ct[a[i - n]]--;
                if(i >= n - 1)
                        mn = min(mn, n - ct[a[i - (n - 1)]]);
        }
        printf("%d\n", mn);
}