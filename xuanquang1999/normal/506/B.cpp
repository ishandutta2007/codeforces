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
// initial graph
int n, m, low[maxN], num[maxN], SCC[maxN], DFScount;
vector<int> ke[maxN];
// SCC graph
int SCCcount, nodeCount[maxN], WCCnodeCount, ans;
vector<int> SCCke[maxN];
bool onenode;
// other element
bool avail[maxN];
stack<int> s;

void DFS(int u) {
    ++DFScount;
    s.push(u);
    num[u] = DFScount; low[u] = maxN+1;
    forit(it, vector<int>, ke[u]) {
        int v = *it;
        if (avail[v]) {
            if (num[v]) low[u] = min(low[u], num[v]);
            else {
                DFS(v);
                low[u] = min(low[u], low[v]);
            }
        }
    }
    if (low[u] >= num[u]) {
        ++SCCcount;
        int v, cnt = 0;
        do {
            ++cnt;
            v = s.top();
            s.pop();
            avail[v] = false;
            SCC[v] = SCCcount;
        }
        while (u != v);
        nodeCount[SCCcount] = cnt;
    }
}

void DFS2(int u) {
    if (nodeCount[u] != 1) onenode = false;
    WCCnodeCount+=nodeCount[u];
    avail[u] = false;
    forit(it, vector<int>, SCCke[u]) if (avail[*it]) DFS2(*it);
}


int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, m) {
        int u, v;
        scanf("%d%d", &u, &v);
        ke[u].pb(v);
    }

    memset(avail, true, sizeof(avail));
    fto(u, 1, n)
        if (avail[u]) DFS(u);

    fto(u, 1, n)
        forit(it, vector<int>, ke[u]) {
            SCCke[SCC[u]].pb(SCC[*it]);
            SCCke[SCC[*it]].pb(SCC[u]);
        }

    ans = 0;
    memset(avail, true, sizeof(avail));
    fto(u, 1, SCCcount)
        if (avail[u]) {
            onenode = true;
            WCCnodeCount = 0;
            DFS2(u);
            if (onenode) --WCCnodeCount;
            ans+=WCCnodeCount;
        }

    //printf("%d %d %d %d\n", n, onenode, SCCcount, WCCcount);

    printf("%d", ans);

    return 0;
}