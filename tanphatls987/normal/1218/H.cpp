#include <bits/stdc++.h>

using namespace std;

const int N = 2e5 + 10;

typedef long long ll;

vector<int> tree[N];
int d[N];
int root[N];
vector<int> heiV[N];
vector<int> impV[N];

vector<int> cir[N];

int n, test;
int deg[N];
int gr[N];
int pos[N];
int a[N];
ll qu[N][2];

int quP[N];


int lab[N][2];

void initTree(int u, int st) {
    static int n1 = 0;
    lab[u][0] = ++n1;
    
    root[u] = st;
    for(auto v : tree[u]) {
        d[v] = d[u] + 1;
        initTree(v, st);
    }

    lab[u][1] = n1;
}
void BFS(int root) {
    gr[root] = root;
    cir[root].push_back(root);
    pos[root] = 0;
    while (1) {
        int u = a[cir[root].back()];
        if (u == root) break;
        gr[u] = root;
        pos[u] = cir[root].size();
        cir[root].push_back(u);
    }
}
int f[N];


int solveTree(ll x, int u) {
    if (x + d[u] > N) return 0;
    int layer = x + d[u];

    auto iteR = upper_bound(heiV[layer].begin(), heiV[layer].end(), lab[u][1]); 


    auto iteL = lower_bound(heiV[layer].begin(), heiV[layer].end(), lab[u][0]);
    return iteR - iteL;
}
int solveCir(ll x, int u) {
    int grU = gr[u];
    int n1 = cir[grU].size();
    int pU = (pos[u] - x % n1 + n1) % n1;
    return f[cir[grU][pU]];
}
int ans[N];
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++) cin >> a[i];

    cin >> test;
    for(int i = 1; i <= test; i++) {
        cin >> qu[i][0] >> qu[i][1];
    }

    for(int i = 1; i <= test; i++) quP[i] = i;
    sort(quP + 1, quP + test + 1, [&](int x, int y) {
        return qu[x][0] < qu[y][0];
    });

    for(int i = 1; i <= n; i++) deg[a[i]]++;

    queue<int> q;
    for(int i = 1; i <= n; i++) if (deg[i] == 0) {
        q.push(i);
    }
    while (!q.empty()) {
        int u = q.front(); q.pop();
        tree[a[u]].push_back(u);
        deg[a[u]]--;
        if (!deg[a[u]]) q.push(a[u]);
    }


    for(int i = 1; i <= n; i++) if (deg[i] > 0) {
        initTree(i, i);
    }


    /*
    for(int i = 1; i <= n; i++) cout << d[i] << " "; cout << '\n';
    for(int i = 1; i <= n; i++) cout << root[i] << " "; cout << '\n';
    for(int i = 1; i <= n; i++) cout << lab[i][0] << " "; cout << '\n';
    for(int i = 1; i <= n; i++) cout << lab[i][1] << " "; cout << '\n';
    */
    for(int i = 1; i <= n; i++) {
        heiV[d[i]].push_back(lab[i][0]);
        impV[d[i]].push_back(i);
    }
    for(int i = 0; i < N; i++) {
        sort(heiV[i].begin(), heiV[i].end());
    }

    memset(gr, -1, sizeof(gr));
    memset(pos, -1, sizeof(pos));
    for(int i = 1; i <= n; i++) if (deg[i] > 0 && gr[i] == -1) {
        BFS(i);
    }

    //for(int i = 1; i <= n; i++) cout << gr[i] << " "; cout << '\n';
    //for(int i = 1; i <= n; i++) cout << pos[i] << " "; cout << '\n';

    int depth = 0;
    for(int i = 1; i <= test; i++) {
        int curQ = quP[i];  
        while (depth <= min(1LL * N - 1, qu[curQ][0])) {
            for(auto u : impV[depth]) {
                int tarU = root[u];
                int grU = gr[tarU];
                int pU = pos[tarU];



                ll n1 = cir[grU].size();
                int upgrX = cir[grU][(pU - depth % n1 + n1) % n1]; 
                f[upgrX]++;
            }
            depth++;
            /*
            cout << depth - 1 << '\n';
            for(int i = 1; i <= n; i++) cout << f[i] << " ";
            cout << '\n';*/
        }
        if (deg[qu[curQ][1]] == 0) {
            ans[curQ] = solveTree(qu[curQ][0], qu[curQ][1]);
        } else {
            ans[curQ] = solveCir(qu[curQ][0], qu[curQ][1]);
        }
    }
    for(int i = 1; i <= test; i++) cout << ans[i] << '\n';
}