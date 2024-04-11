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
#define maxN 100005
#define maxM 100005
#define maxC 100005

set<int> nc[maxC];
int c[maxN], n, m;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) {
        scanf("%d", &c[i]);
        nc[c[i]].insert(c[i]);
    }

    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        nc[c[u]].insert(c[v]);
        nc[c[v]].insert(c[u]);
    }


    int maxNC = 0; int ans = 0;
    fto(i, 1, maxC-1) {
        int x = nc[i].size();
        if (x > maxNC) {
            maxNC = x;
            ans = i;
        }
    }

    printf("%d", ans);

    return 0;
}