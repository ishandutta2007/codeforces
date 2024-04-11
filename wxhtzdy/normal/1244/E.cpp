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
const int maxn = 100005;
int n, a[maxn];
ll k, x[maxn];
bool canL(int w) {
    ll ssum = 1e18;
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        if (i > 0) cur += a[i] * 1LL * i - x[i - 1];
        int bot = i + 1, top = n - 1, pos = n;
        while (bot <= top) {
            int mid = bot + top >> 1;
            if (a[mid] > a[i] + w) pos = mid, top = mid - 1;
            else bot = mid + 1;
        }
        if (pos < n) {
            cur += (x[n - 1] - x[pos - 1]) - (a[i] + w) * 1LL * (n - pos);
        }
        chkmin(ssum, cur);
    }
    return ssum <= k;
}
bool canR(int w) {
    ll ssum = 1e18;
    for (int i = 0; i < n; i++) {
        ll cur = 0;
        if (i < n - 1) cur += x[n - 1] - x[i] - a[i] * 1LL * (n - i - 1);
        int bot = 0, top = i - 1, pos = -1;
        while (bot <= top) {
            int mid = bot + top >> 1;
            if (a[mid] + w < a[i]) pos = mid, bot = mid + 1;
            else top = mid - 1;
        }
        if (pos != -1) {
            cur += (a[i] - w) * 1LL * (pos + 1) - x[pos];
        }
        chkmin(ssum, cur);
    }
    return ssum <= k;
}
int main() {
    scanf("%d %lld", &n, &k);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++) {
        x[i] = (i == 0 ? 0LL : x[i - 1]) + a[i];
    }
    int bot = 0, top = 1e9, ans = 1e9;
    while (bot <= top) {
        int mid = bot + top >> 1;
        if (canL(mid) || canR(mid)) ans = mid, top = mid - 1;
        else bot = mid + 1;
    }
    printf("%d", ans);
    return 0;
}