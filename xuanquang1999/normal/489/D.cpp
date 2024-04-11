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
#define maxN 3005
#define maxM 30005
#define maxC 1000000009
int n, m, a[maxN][maxN], f[maxN][maxN], u[maxM], v[maxM];
ll ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, m-1) {
        scanf("%d%d", &u[i], &v[i]);
        a[u[i]][v[i]] = 1;
    }

    fto(i, 0, m-1)
        fto(t, 1, n)
            if (t!=u[i] && t!=v[i] && a[v[i]][t]) ++f[u[i]][t];

    ans = 0;
    fto(s, 1, n)
        fto(t, 1, n) ans+=((f[s][t]-1)*f[s][t])/2;
    printf("%I64d", ans);

    return 0;
}