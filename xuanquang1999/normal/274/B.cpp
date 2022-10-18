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

int n;
ll a[maxN], maxD[maxN], minD[maxN];
vector<int> ke[maxN];
bool visited[maxN];
ll ans;

ll DFS(int u) {
    visited[u] = true;
    forit(it, vector<int>, ke[u]) {
        int v = *it;
        if (!visited[v]) {
            DFS(v);
            minD[u] = min(minD[u], minD[v]);
            maxD[u] = max(maxD[u], maxD[v]);
        }
    }
    //ans+=a[u]+minD+maxD;
    a[u]-=minD[u]+maxD[u];
    if (a[u] < 0) minD[u]+=a[u];
    else maxD[u]+=a[u];

//    debug(u);
//    debug(minD[u]);
//    debug(maxD[u]);
//    debug(ans);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n-1) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
        ke[v].pb(u);
    }
    fto(i, 1, n) scanf("%I64d", &a[i]);

    //ke[1].pb(1);

    DFS(1);

    cout << maxD[1]-minD[1];

    return 0;
}