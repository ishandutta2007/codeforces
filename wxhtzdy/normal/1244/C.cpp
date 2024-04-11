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
ll n, p, w, d;
int main() {
    scanf("%lld %lld %lld %lld", &n, &p, &w, &d);
    for (int i = 0; i <= maxn; i++) {
        if (i * d > p) break;
        ll x = (p - i * d) / w;
        if ((p - i * d) % w == 0 && x + i <= n) {
            printf("%lld %d %lld\n", x, i, n - x - i);
            return 0;
        }
    }
    printf("-1");
    return 0;
}