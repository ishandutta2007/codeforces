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
const int maxn = 200005;
const int lg = 25;
int n, a[maxn];
int st[maxn][lg];
int mb[maxn];
int pr[maxn], su[maxn];
int nxt[maxn];
vi pos[maxn];
void compress() {
    vi cp;
    for (int i = 0; i < n; i++) cp.pb(a[i]);
    sort(cp.begin(), cp.end());
    cp.erase(unique(cp.begin(), cp.end()), cp.end());
    for (int i = 0; i < n; i++) {
        a[i] = lower_bound(cp.begin(), cp.end(), a[i]) - cp.begin() + 1;
    }
}
void build() {
    mb[1] = 0;
    for (int i = 2; i <= n; i++) mb[i] = mb[i / 2] + 1;
    for (int i = 0; i < n; i++) {
        st[i][0] = a[i];
    }
    for (int j = 1; j < lg; j++)
        for (int i = 0; i + (1 << j) <= n; i++)
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
}
int qmn(int l, int r) {
    int sz = r - l + 1;
    int j = mb[sz];
    return min(st[l][j], st[r - (1 << j) + 1][j]);
}
int main() {
    int t;
    scanf("%d", &t);
    while (t--) {
        scanf("%d", &n);
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        for (int i = 1; i <= n; i++) nxt[i] = 0, pos[i].clear();
        compress();
        build();
        pr[0] = a[0];
        for (int i = 1; i < n; i++) pr[i] = max(pr[i - 1], a[i]);
        su[n - 1] = a[n - 1];
        pos[su[n - 1]].pb(n - 1);
        for (int i = n - 2; i >= 0; i--) {
            su[i] = max(su[i + 1], a[i]);
            pos[su[i]].pb(i);
        }
        for (int i = 1; i <= n; i++) {
            reverse(pos[i].begin(), pos[i].end());
        }
        int a = -1, b, c;
        for (int i = 0; i < n; i++) {
            nxt[su[i]]++;
            int bot = nxt[pr[i]], top = pos[pr[i]].size() - 1;
            bool ok = false;
            while (bot <= top) {
                int mid = bot + top >> 1;
                if (pos[pr[i]][mid] == i + 1) {
                    bot = mid + 1;
                    continue;
                }
                int mn = qmn(i + 1, pos[pr[i]][mid] - 1);
                if (mn == pr[i]) {
                    ok = true;
                    break;
                }
                if (mn > pr[i]) bot = mid + 1;
                else top = mid - 1;
            }
            if (ok) {
                a = i;
                b = pos[pr[i]][bot + top >> 1];
                c = n;
                break;
            }
        }
        if (a == -1) printf("NO\n");
        else printf("YES\n%d %d %d\n", a + 1, b - a - 1, c - b);
    }
    return 0;
}