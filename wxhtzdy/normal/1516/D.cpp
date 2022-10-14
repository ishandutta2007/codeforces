#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define vi vector<int>
#define pi pair<int, int>
#define mod 1000000007
template<typename T> chkmin(T &a, T b){return (b < a) ? a = b, 1 : 0;}
template<typename T> chkmax(T &a, T b){return (b > a) ? a = b, 1 : 0;}
ll ksm(ll a, ll b){if (b == 0) return 1; ll ns = ksm(a, b >> 1); ns = ns * ns % mod; if (b & 1) ns = ns * a % mod; return ns;}
using namespace std;

const int maxn=100005;
const int lg=20;

int n, q;
int a[maxn];
int nxt[maxn][lg];
int lst[maxn];
vi divs[maxn];
int main() {
    scanf("%d %d", &n, &q);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    for (int i = 2; i < maxn; i++) {
        lst[i] = n;
        for (int j = i; j < maxn; j += i) {
            divs[j].pb(i);
        }
    }
    for (int i = 0; i < lg; i++) {
        nxt[n][i] = n;
    }
    for (int i = n - 1; i >= 0; i--) {
        nxt[i][0] = nxt[i + 1][0];
        for (int x : divs[a[i]]) {
            nxt[i][0] = min(nxt[i][0], lst[x]);
            lst[x] = i;
        }
    }
    for (int j = 1; j < lg; j++) {
        for (int i = 0; i < n; i++) {
            nxt[i][j] = nxt[nxt[i][j - 1]][j - 1];
        }
    }
    while (q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        --l, --r;
        int ans = 1;
        for (int i = lg - 1; i >= 0; i--) {
            if (nxt[l][i] <= r) {
                ans += (1 << i);
                l = nxt[l][i];
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}