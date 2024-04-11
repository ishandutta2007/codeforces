using namespace std;
#include <bits/stdc++.h>
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
#define maxN 100005

int n, m, k, cur;
vector<ii> ans[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    int i = 1, j = 1, cnt = 1, cur = 0;
    while (i <= n) {
        ans[cnt].pb(mp(i, j));

        ++cur;
        if (cur == 2) {
            if (cnt < k) ++cnt;
            cur = 0;
        }

        if ((i%2 == 1 && j == m) || (i%2 == 0 && j == 1)) ++i;
        else if (i%2 == 1) ++j;
        else --j;
    }

    fto(i, 1, k) {
        int x = ans[i].size();
        printf("%d", x);
        fto(j, 0, x-1) printf(" %d %d", ans[i][j].fi, ans[i][j].se);
        printf("\n");
    }

    return 0;
}