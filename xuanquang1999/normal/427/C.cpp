#include <bits/stdc++.h>

using namespace std;

#define debug(a) cout << #a << ": " << a << endl
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define fdto(i, r, l) for(int i = (r); i >= (l); ++i)
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
#define maxN 100005
#define oo 1000000007

int n, m, p[maxN], num[maxN], low[maxN], DFScnt, SCCcnt;
ll minP, cntP, ansP;
bool avail[maxN];
vector<int> ke[maxN];
vector<int> SCC[maxN];
stack<int> s;

void DFS(int u) {
    num[u] = ++DFScnt;
    low[u] = oo;
    s.push(u);
    forit(it, vector<int>, ke[u]) {
        int v = *it;
        if (!avail[v]) continue;
        if (!num[v]) {
            DFS(v);
            low[u] = min(low[u], low[v]);
        }
        else low[u] = min(low[u], num[v]);
    }
    if (low[u] >= num[u]) {
        minP = oo;
        ll cnt = 0;
        while (s.top() != u) {
            int v = s.top();
            avail[v] = false;
            if (minP > p[v]) {
                minP = p[v];
                cnt = 1;
            }
            else if (minP == p[v]) ++cnt;
            s.pop();
        }
        avail[u] = false;
        if (minP > p[u]) {
            minP = p[u];
            cnt = 1;
        }
        else if (minP == p[u]) ++cnt;
        s.pop();
        cntP = (cntP*cnt)%oo;
        ansP += minP;
    }
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &p[i]);
    scanf("%d", &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
    }

    cntP = 1;
    memset(avail, true, sizeof avail);
    fto(u, 1, n)
        if (!num[u]) DFS(u);
//    fto(u, 1, n) printf("%d ", num[u]);
//    printf("\n");
//    fto(u, 1, n) printf("%d ", low[u]);
//    printf("\n");
//
    cout << ansP << " " << cntP;

    return 0;
}