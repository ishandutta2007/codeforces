#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define mp make_pair/////////////////////////////////////////////
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

constexpr ll INF = 1e18;

struct FAU {
    Vi G;
    FAU(int n = 0) { init(n); }
    void init(int n) { G.assign(n, -1); }
    int size(int i) { return -G[find(i)]; }
    int find(int i) { return G[i] < 0 ? i : G[i] = find(G[i]); }
    bool join(int i, int j) {
        i = find(i); j = find(j);
        if (i == j) return false;
        if (G[i] > G[j]) swap(i, j);
        G[i] += G[j]; G[j] = i;
        return true;
    }
};

template<class T>
vector<ll> multiBS(ll begin, ll end, int count, T cmp) {
    vector<pair<ll, ll>> ranges(count, {begin, end});
    vector<pair<ll, int>> queries(count);
    vector<bool> answers(count);

    rep(i,0,count) queries[i]={(begin+end)/2,i};

    for (int k = uplg(end-begin); k > 0; k--) {
        ll last = 0;
        int j = 0;
        cmp(queries, answers);

        rep(i, 0, sz(queries)) {
            auto &q = queries[i];
            auto &r = ranges[q.y];
            if (q.x != last) last = q.x, j = i;
            (answers[i] ? r.x : r.y) = q.x;
            q.x = (r.x+r.y) / 2;
            if (!answers[i]) swap(queries[i], queries[j++]);
        }
    }

    vector<ll> ret;
    each(p, ranges) ret.pb(p.x);
    return ret;
}

void run() {
    int n, s, m, q;
    cin >> n >> m >> s >> q;
    vector<vector<Pii>> G(n);
    Vi stations(s);
    iota(all(stations), 0);

    rep(i, 0, m) {
        int a, b, d; cin >> a >> b >> d;
        a--; b--;
        G[a].pb({b, d});
        G[b].pb({a, d});
    }

    vector<Pii> queries(q);

    each(query, queries) {
        cin >> query.x >> query.y;
        query.x--; query.y--;
    }

    vector<ll> dists(n, INF);
    Vi close(n, -1);
    priority_queue<pair<ll, int>> que;

    each(st, stations) {
        dists[st] = 0;
        close[st] = st;
        que.push({0, st});
    }

    while (!que.empty()) {
        ll d = -que.top().x;
        int v = que.top().y;
        que.pop();
        if (d != dists[v]) continue;

        each(e, G[v]) {
            ll alt = d + e.y;
            if (alt < dists[e.x]) {
                dists[e.x] = alt;
                close[e.x] = close[v];
                que.push({-alt, e.x});
            }
        }
    }

    vector<pair<ll, Pii>> edges;

    rep(v, 0, n) {
        each(e, G[v]) {
            if (v < e.x && close[v] != close[e.x]) {
                edges.pb({ dists[v] + dists[e.x] + e.y, {close[v], close[e.x]} });
            }
        }
    }

    sort(all(edges));

    auto ans = multiBS(0, edges.back().x+5, q, [&](vector<pair<ll, int>>& qSorted, vector<bool>& out) {
        FAU fau(n);
        int i = 0;
        rep(j, 0, sz(qSorted)) {
            auto &kek = qSorted[j];
            while (i < sz(edges) && edges[i].x <= kek.x) {
                fau.join(edges[i].y.x, edges[i].y.y);
                i++;
            }
            out[j] = (fau.find(queries[kek.y].x) != fau.find(queries[kek.y].y));
        }
    });

    each(a, ans) {
        cout << a+1 << '\n';
    }
}