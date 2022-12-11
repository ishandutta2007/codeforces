#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> ii;

const int N = 14;
int n;
int adj[N];
int line[1 << N][N];
int w[1 << N];
int lastBit[1 << N];


int f[1 << N];

vector<ii> ans;
int trace(int mask, int st, int en, int type) {
    assert(mask & (1 << st));
    assert(mask & (1 << en));

    if (type == 0) {
        if (st == en) {
            if (w[mask] <= 2) return 0;
            return adj[st] & line[mask][st];
        } 
        return line[mask][st] & (1 << en); 
    }
    //cout << bitset<N>(mask) << " " << st << " " << en << " " << '\n';


    if (st == en) {
        int cur = adj[st] & line[mask][st]; 
        int realEn = lastBit[cur];
        ans.push_back(ii(st, realEn));
        trace(mask, st, realEn, 1); 
        return 0;
    }
    while (en != st) {
        int newMask = mask ^ (1 << en);
        int com = adj[en] & line[newMask][st];
        int newEn = lastBit[com];
        ans.push_back(ii(newEn, en));
        mask = newMask;
        en = newEn;
    }
    return 0;
}
int DP(int state, int type) {
    if (state == 1) {
        return 0;
    }

    if (type == 0) {
        int &res = f[state];
        if (res != -1) return res;
        res = n * n + 1;


        for(int ns = state; ; ) {
            ns = state & (ns - 1);
            if (ns == 0) break;

            int needCir = state ^ ns;
            for(int st = 0; st < n; st++) if ((ns >> st) & 1) 
                for(int en = 0; en < n; en++) if ((ns >> en) & 1){
                    int effCir = needCir | (1 << st) | (1 << en);
                    if (trace(effCir, st, en, 0)) {
                        res = min(res, DP(ns, 0) + w[needCir] + 1);
                    }
                }
        }
        return res;
    }

    int res = DP(state, 0);
    for(int ns = state; ; ) {
        ns = state & (ns - 1);
        if (ns == 0) break;
        int needCir = state ^ ns;
        for(int st = 0; st < n; st++) if ((ns >> st) & 1) 
            for(int en = 0; en < n; en++) if ((ns >> en) & 1){
                int effCir = needCir | (1 << st) | (1 << en);
                if (trace(effCir, st, en, 0)) {
                    int best = DP(ns, 0) + w[needCir] + 1;

                    if (best == res) {
                        trace(effCir, st, en, 1);
                        DP(ns, 1);
                        return 0;
                    }
                }
            }

    }
    return -1;
}
int main() {
    for(int i = 1; i < (1 << N); i++) w[i] = w[i / 2] + i % 2;
    for(int i = 1; i < (1 << N); i++) 
        lastBit[i] = i % 2 ? 0 : lastBit[i / 2] + 1;
    int m;
    cin >> n >> m;
    while (m--) {
        int u, v;
        cin >> u >> v; u--, v--;
        adj[u] |= 1 << v;
        adj[v] |= 1 << u;
    }

    for(int st = 0; st < n; st++) 
        line[1 << st][st] = 1 << st;
    for(int mask = 1; mask < (1 << n); mask++) 
        for(int st = 0; st < n; st++) if (line[mask][st]) {
            //cout << bitset<N>(mask) << " " << st << " " << bitset<N>(line[mask][st]) << '\n';
            for(int u = 0; u < n; u++) if (!((mask >> u) & 1)) {
                if (adj[u] & line[mask][st]) {
                    line[mask | (1 << u)][st] |= 1 << u;
                }
            }
        }


    memset(f, -1, sizeof(f));
    //cout << "Should " << DP((1 << n) - 1, 0) << '\n';
    DP((1 << n) - 1, 1);
    cout << ans.size() << '\n';
    for(auto i : ans) cout << i.first + 1 << " " << i.second + 1 << '\n';
}