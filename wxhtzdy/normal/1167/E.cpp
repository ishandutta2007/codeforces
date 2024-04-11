#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1234567
template<typename T> bool chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> bool chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b)  {if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;
const int maxn = 1000005;
int n, x;
int a[maxn];
int mx[maxn], mn[maxn];
bool pr[maxn], po[maxn];
vi pos[maxn];
void init() {
    pr[0] = po[x + 1] = true;
    mx[0] = -1;
    mn[x + 1] = n + 1;
    for (int i = 1; i <= x; i++) {
        pr[i] = pr[i - 1];
        mx[i] = mx[i - 1];
        for (int j : pos[i]) pr[i] &= (j > mx[i - 1]);
        for (int j : pos[i]) chkmax(mx[i], j);
    }
    for (int i = x; i >= 1; i--) {
        po[i] = po[i + 1];
        mn[i] = mn[i + 1];
        for (int j : pos[i]) po[i] &= (j < mn[i + 1]);
        for (int j : pos[i]) chkmin(mn[i], j);
    }
}
bool can(int L, int R) {
    if (!pr[L - 1]) return false;
    if (!po[R + 1]) return false;
    return mx[L - 1] <= mn[R + 1];
}
int main() {
    scanf("%d %d", &n, &x);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        pos[a[i]].pb(i);
    }
    init();
    ll ans = 0;
    for (int i = 1; i <= x; i++) {
        if (!pr[i - 1]) break;
        int bot = i, top = x, pos = x + 1;
        while (bot <= top) {
            int mid = bot + top >> 1;
            if (can(i, mid)) top = mid - 1, pos = mid;
            else bot = mid + 1;
        }
        ans += x - pos + 1;
    }
    printf("%lld", ans);
    return 0;
}