//84104971101048411497
#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define forit(it, type, var) for(type::iterator it = var.begin(); it != var.end(); it++)
#define forrit(rit, type, var) for(type::reverse_iterator rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define mp make_pair
#define ff first
#define ss second
#define pb push_back
#define ll long long
#define ull unsigned long long
#define mapii map<int, int>
#define maxN 100000
#define oo 1000000007

int n, w[maxN], p[maxN*2+1];
ii a[maxN], ans[maxN];
vector<ii> v[maxN*2+1];

bool cmp (ii a, ii b) {
    return (a.ff <= b.ff && a.ss <= b.ss);
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d%d", &a[i].ff, &a[i].ss);
    sort(a, a+n);

    fto(i, 0, n-1) v[a[i].ss-a[i].ff+maxN].pb(a[i]);

    fto(i, 0, n-1) scanf("%d", &w[i]);
    fto(i, 0, n-1) {
        int x = w[i] + maxN;
        if (p[x] < v[x].size()) {
            ans[i] = v[x][p[x]];
            ++p[x];
        }
        else {
            puts("NO");
            return 0;
        }
    }

    fto(i, 0, n-2)
        if (cmp(ans[i+1], ans[i])) {
            puts("NO");
            return 0;
        }

    puts("YES");
    fto(i, 0, n-1) printf("%d %d\n", ans[i].ff, ans[i].ss);

    return 0;
}