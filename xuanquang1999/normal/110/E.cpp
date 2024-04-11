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

vector<int> ke[maxN];
bool visited[maxN];
ll ans, cnt, tmp;
int n;

bool isLucky(int n) {
    while (n > 0) {
        if (n%10 != 4 && n%10 != 7) return false;
        n/=10;
    }
    return true;
}

void DFS(int u) {
    visited[u] = true;
    ++cnt;
    forit(it, vector<int>, ke[u])
        if (!visited[*it]) DFS(*it);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v, w;
        scanf("%d%d%d", &u, &v, &w);
        if (!isLucky(w)) {
            ke[u].pb(v);
            ke[v].pb(u);
        }
    }

    tmp = n;
    ans = tmp*(tmp-1)*(tmp-2);
    fto(u, 1, n)
        if (!visited[u]) {
            cnt = 0;
            DFS(u);
            //printf("%I64d\n", cnt);
            ans-=2*cnt*(cnt-1)*(tmp-cnt)+cnt*(cnt-1)*(cnt-2);
        }

    printf("%I64d", ans);

    return 0;
}