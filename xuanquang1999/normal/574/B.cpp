using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
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
#define maxN 4005
#define maxM 4005
#define oo 1000000007
int n, m, eu[maxM], ev[maxM], deg[maxN], ans;
bool a[maxN][maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        scanf("%d%d", &eu[i], &ev[i]);
        ++deg[eu[i]]; ++deg[ev[i]];
        a[eu[i]][ev[i]] = a[ev[i]][eu[i]] = true;
    }

    ans = oo;
    fto(i, 1, m)
        fto(u, 1, n)
            if (a[eu[i]][u] && a[ev[i]][u]) ans = min(ans, deg[eu[i]]+deg[ev[i]]+deg[u]-6);

    printf("%d", (ans == oo) ? -1 : ans);

    return 0;
}