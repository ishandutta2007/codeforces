using namespace std;
#include <bits/stdc++.h>
#define fdto(i, r, l) for(int i = r; i >= l; --i)
#define fto(i, l, r) for(int i = l; i <= r; ++i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 300005
#define maxW 100005

int n, m, f[maxN], tmp[maxN], ans;
vector<ii> e[maxW];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, m-1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        e[w].pb(mp(u, v));
    }

    fto(i, 1, maxW-1) {
        forit(it, vector<ii>, e[i]) {
            int u = (*it).fi, v = (*it).se;
            tmp[v] = max(tmp[v], f[u]+1);
        }
        forit(it, vector<ii>, e[i]) {
            int u = (*it).fi, v = (*it).se;
            f[v] = max(f[v], tmp[v]);
            ans = max(ans, f[v]);
        }
    }

    printf("%d", ans);

    return 0;
}