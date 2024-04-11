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

int a[200009];
int main() {
        int i, n;
        scanf("%d", &n);
        int mn = INT_MAX, mn_i;
        for(i = 0; i < n; i++) {
                scanf("%d", &a[i]);
                if(a[i] < mn) mn = a[i], mn_i = i;
        }
        int mx = 0;
        int cur = 0;
        int g = (mn_i + 1) % n;
        for(int g = (mn_i + 1) % n; g != mn_i; g = (g + 1) % n) {
                if(a[g] == mn) cur = 0;
                else cur++;
                mx = max(mx, cur);
        }
        printf("%I64d\n", ll(mn) * ll(n) + ll(mx));
}