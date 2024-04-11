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
#define maxN 105

int n, m, k, a[maxN][maxN], ans[maxN];
vector<int> c[maxN];
bool locked[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, n)
        fto(j, 1, m) scanf("%d", &a[i][j]);

    fto(j, 1, m) {
        fto(t, 1, k) c[t].clear();
        fto(i, 1, n)
            if (ans[i] == 0) {
                if (locked[a[i][j]]) ans[i] = j;
                else c[a[i][j]].pb(i);
            }
        fto(t, 1, k)
            if (c[t].size() >= 2) {
                locked[t] = true;
                fto(i, 0, c[t].size()-1) ans[c[t][i]] = j;
            }
    }

    fto(i, 1, n) printf("%d\n", ans[i]);

    return 0;
}