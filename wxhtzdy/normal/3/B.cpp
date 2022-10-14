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
int n, v;
vector<pi> a[2];
int pref[2][maxn];
int main() {
    scanf("%d%d", &n, &v);
    for (int i = 0; i < n; i++) {
        int t, p;
        scanf("%d%d", &t, &p);
        a[t - 1].pb(mp(p, i));
    }
    sort(a[0].rbegin(), a[0].rend());
    sort(a[1].rbegin(), a[1].rend());
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < a[i].size(); j++) {
            pref[i][j + 1] = pref[i][j] + a[i][j].fi;
        }
    }
    pi res = mp(0, 0);
    for (int i = 0; i <= min(v, (int) a[0].size()); i++) {
        int nv = v - i;
        int x = i, y = min((int) a[1].size(), nv / 2);
        if (pref[0][res.fi] + pref[1][res.se] < pref[0][x] + pref[1][y]) {
            res = mp(x, y);
        }
    }
    printf("%d\n", pref[0][res.fi] + pref[1][res.se]);
    for (int i = 1; i <= res.fi; i++) printf("%d ", a[0][i - 1].se + 1);
    for (int i = 1; i <= res.se; i++) printf("%d ", a[1][i - 1].se + 1);
    return 0;
}