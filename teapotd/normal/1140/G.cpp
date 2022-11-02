#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define sz(x)int((x).size())/////////////////////////////////////
#define each(a,x)for(auto&a:(x))/////////////////////////////////
#define all(x)(x).begin(),(x).end()//////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)///////////////////////
using namespace std;using ll=long long;using Pii=pair<int,int>;//
using Vi=vector<int>;void run();int main(){cin.sync_with_stdio///
(0);cin.tie(0);cout<<fixed<<setprecision(18);run();return 0;}////
//-------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }

struct Query {
    int u, v;
    ll ans{INT64_MAX};
};

struct Vert {
    vector<pair<int, ll>> E;
    int seen{-1}, size, mark;
    ll dist;
};

vector<Vert> G;
vector<Query> Q;
int cnt = 0;

void dfsSize(int v) {
    G[v].seen = cnt;
    G[v].size = 1;
    each(e, G[v].E) if (e.x%2 == 0 && G[e.x].seen < cnt) {
        dfsSize(e.x);
        G[v].size += G[e.x].size;
    }
}

void dfsMark(int v, int m) {
    if (G[v].seen >= cnt) return;
    G[v].seen = cnt;
    G[v].mark = m;
    each(e, G[v].E) dfsMark(e.x, m);
}

void dijkstra(const Vi& inside, int root) {
    priority_queue<pair<ll, int>> que;
    que.push({0, root});
    G[root].dist = 0;
    G[root].seen = cnt;

    while (!que.empty()) {
        int v = que.top().y;
        ll d = -que.top().x;
        que.pop();
        if (d != G[v].dist) continue;

        each(e, G[v].E) {
            if (G[e.x].seen < cnt) {
                G[e.x].seen = cnt;
                G[e.x].dist = INT64_MAX;
            }
            ll alt = d + e.y;
            if (alt < G[e.x].dist) {
                G[e.x].dist = alt;
                que.push({-alt, e.x});
            }
        }
    }

    each(i, inside) {
        Q[i].ans = min(Q[i].ans, G[Q[i].u].dist + G[Q[i].v].dist);
    }
}

void solve(const Vi& inside, int v) {
    cnt++;
    dfsSize(v);

    int p = -1, s = G[v].size;
    bool cont = 1;

    while (cont) {
        cont = 0;
        each(e, G[v].E) {
            if (e.x % 2 || e.x == p || G[e.x].seen != cnt) continue;
            if (G[e.x].size > s/2) {
                p = v;
                v = e.x;
                cont = 1;
                break;
            }
        }
    }

    cnt++;
    dijkstra(inside, v);
    cnt++;
    dijkstra(inside, v+1);
    cnt++;

    G[v].seen = INT_MAX;
    G[v+1].seen = INT_MAX;
    G[v].mark = -1;
    G[v+1].mark = -2;
    rep(i, 0, sz(G[v].E)) dfsMark(G[v].E[i].x, i);

    vector<Vi> partition(sz(G[v].E));

    each(i, inside) {
        if (G[Q[i].u].mark == G[Q[i].v].mark) {
            partition[G[Q[i].u].mark].pb(i);
        }
    }

    rep(i, 0, sz(G[v].E)) {
        int e = G[v].E[i].x;
        if (!partition[i].empty()) solve(partition[i], e);
    }
}

void addEdge(int i, int j, ll w) {
    G[i].E.pb({j, w});
    G[j].E.pb({i, w});
}

void run() {
    int n; cin >> n;
    G.resize(n*2);

    rep(i, 0, n) {
        ll w; cin >> w;
        addEdge(i*2, i*2+1, w);
    }

    rep(i, 1, n) {
        int a, b;
        ll w1, w2;
        cin >> a >> b >> w1 >> w2;
        a--; b--;
        addEdge(a*2, b*2, w1);
        addEdge(a*2+1, b*2+1, w2);
    }

    int q; cin >> q;
    Q.resize(q);
    each(e, Q) {
        cin >> e.u >> e.v;
        e.u--; e.v--;
    }

    Vi tmp(q);
    iota(all(tmp), 0);
    solve(tmp, 0);

    each(e, Q) cout << e.ans << '\n';
}