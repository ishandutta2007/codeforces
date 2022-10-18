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

int a[maxN][maxN], g[maxN], n;
vector <int> ans;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d\n", &n);
    fto(u, 1, n) {
        fto(v, 1, n) {
            char c;
            scanf("%c", &c);
            a[u][v] = c-48;
        }
        scanf("\n");
    }
    fto(u, 1, n) scanf("%d", &g[u]);

    while (1) {
        int u = 0;
        fto(v, 1, n)
            if (g[v] == 0) {
                u = v;
                break;
            }
        if (!u) break;

        ans.pb(u);
        fto(v, 1, n)
            if (a[u][v]) --g[v];
    }

    printf("%d\n", ans.size());
    forit(it, vector<int>, ans) printf("%d ", *it);
    printf("\n");

    return 0;
}