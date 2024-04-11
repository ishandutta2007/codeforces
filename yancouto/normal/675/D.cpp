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

int a[N], l[N], r[N], p[N];
struct cmp {
        bool operator()(int i, int j) { return a[i] < a[j]; }
};

int main() {
        int i, j, n;
        scanf("%d", &n);
        scanf("%d", &a[0]);
        set<int, cmp> s;
        s.insert(0);
        for(i = 1; i < n; i++) {
                scanf("%d", &a[i]);
                auto it = s.upper_bound(i);
                if(it != s.end() && !l[*it]) {
                        l[*it] = 1;
                } else {
                        assert(it != s.begin() && !r[*prev(it)]); it = prev(it);
                        r[*it] = 1;
                }
                p[i] = *it;
                s.insert(i);
        }
        for(i = 1; i < n; i++)
                printf("%d ", a[p[i]]);
        putchar('\n');
}