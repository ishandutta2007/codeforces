#include <bits/stdc++.h>
#define FOR(i, n) for(int i = 0; i < (n); ++i)
#define REP(i, a, b) for(int i = (a); i < (b); ++i)
#define TRAV(i, n) for(auto &i : n)
#define SZ(x) (int)(x).size()
#define PR std::pair
#define MP std::make_pair
#define X first
#define Y second
typedef long long ll;
typedef std::pair<int, int> PII;
typedef std::vector<int> VI;

struct MaxTree{
        std::vector<ll> t, u;
        int BOTTOM;
        void build(const std::vector<ll> &vec){
                BOTTOM = 1;
                while(BOTTOM < SZ(vec)) BOTTOM *= 2;
                t.resize(BOTTOM*2);
                u.resize(BOTTOM*2);
                FOR(i, SZ(vec)) t[BOTTOM+i] = vec[i];
                for(int i = BOTTOM-1; i >= 1; --i) t[i] = std::max(t[i<<1], t[(i<<1)|1]);
        }
        void upd(int v){
                if(u[v] != 0){
                        t[v] += u[v];
                        if(v < BOTTOM){
                                u[v<<1] += u[v];
                                u[(v<<1)|1] += u[v];
                        }
                        u[v] = 0;
                }
        }
        void add(int a, int b, ll w, int v=1, int lo=0, int hi=-2){
                if(hi == -2) hi = BOTTOM-1;
                upd(v);
                if(a > b) return;
                if(a == lo && b == hi){
                        u[v] += w;
                        upd(v);
                        return;
                }
                int mid = (lo+hi)/2;
                add(a, std::min(b, mid), w, v<<1, lo, mid);
                add(std::max(a, mid+1), b, w, (v<<1)|1, mid+1, hi);
                t[v] = std::max(t[v<<1],t[(v<<1)|1]);
        }
        ll query(int a, int b, int v=1, int lo=0, int hi=-2){
                if(hi == -2) hi = BOTTOM-1;
                upd(v);
                if(a > b) return 0;
                if(a == lo && b == hi) return t[v];
                int mid = (lo+hi)/2;
                return std::max(query(a, std::min(b, mid), v<<1, lo, mid),
                                                query(std::max(a, mid+1), b, (v<<1)|1, mid+1, hi));
        }
};

struct Tree;

struct Edge{
        int a, b;
        ll w;
        int id;
        std::vector<PR<Tree*, PII> > trees;
        Edge(int _a, int _b, ll _w, int _id) : a(_a), b(_b), w(_w), id(_id) {}
};

int n, q;
ll w;
std::vector<VI> g;
std::vector<Edge> edges;


ll last;
std::multiset<ll> all_ans;

std::vector<bool> blocked;
struct Tree{
        int root;
        MaxTree mt;
        std::multiset<ll> ans;
        std::vector<ll> dist;
        std::unordered_map<int, int> roz, pre, post;

        Tree(int r, int sz){
                root = r;
                tick = 0;
                dfs(root);
                mt.build(dist);
                blocked[root] = true;
                TRAV(ch, g[root]){
                        auto &ed = edges[ch];
                        int to = (ed.a == root ? ed.b : ed.a);
                        if(blocked[to]) continue;
                        ans.insert(mt.query(pre[to], post[to]));
                        N = roz[to];
                        int cent = centroid(to);
                        new Tree(cent, N);
                }
                if(sz > 1){
                        ll best = *std::next(ans.end(), -1);
                        if(SZ(ans) > 1) best += *std::next(ans.end(), -2);
                        all_ans.insert(best);
                }
        }

        int N;

        int centroid(int v, int par=-1){
                bool cent = 2*roz[v] >= N;
                TRAV(ch, g[v]){
                        auto &ed = edges[ch];
                        int to = (ed.a == v ? ed.b : ed.a);
                        if(to == par || blocked[to]) continue;
                        int xd = centroid(to, v);
                        if(xd != -1) return xd;
                        if(2*roz[to] > N) cent = false;
                }
                if(cent) return v;
                return -1;
        }

        int tick, kto;
        void dfs(int v, int par=-1, ll dst=0){
                roz[v] = 1;
                pre[v] = tick++;
                dist.push_back(dst);
                TRAV(ch, g[v]){
                        auto &ed = edges[ch];
                        int to = (ed.a == v ? ed.b : ed.a);
                        if(to == par || blocked[to]) continue;
                        if(v == root) kto = to;
                        ed.trees.push_back(MP(this, MP(to, kto)));
                        dfs(to, v, dst+ed.w);
                        roz[v] += roz[to];
                }
                post[v] = tick++;
                dist.push_back(dst);
        }
};


void answer(int d, ll e){
        auto &ed = edges[d];
        ll delta = e - ed.w;
        TRAV(pr, ed.trees){
                Tree *tree = pr.X;
                int v = pr.Y.X;
                int kto = pr.Y.Y;
                ll old_ans = *std::next(tree->ans.end(), -1);
                if(SZ(tree->ans) > 1) old_ans += *std::next(tree->ans.end(), -2);
                all_ans.erase(all_ans.find(old_ans));
                ll old = tree->mt.query(tree->pre[kto], tree->post[kto]);
                tree->ans.erase(tree->ans.find(old));
                tree->mt.add(tree->pre[v], tree->post[v], delta);
                tree->ans.insert(tree->mt.query(tree->pre[kto], tree->post[kto]));
                ll nw = *std::next(tree->ans.end(), -1);
                if(SZ(tree->ans) > 1) nw += *std::next(tree->ans.end(), -2);
                all_ans.insert(nw);
        }
        ed.w = e;
        last = *std::next(all_ans.end(), -1);
}

int main(){
        std::ios_base::sync_with_stdio(false);
        std::cin.tie(0);
        std::cin >> n >> q >> w;
        g.resize(n);
        FOR(i, n-1){
                int a, b;
                ll c;
                std::cin >> a >> b >> c;
                a--;b--;
                edges.push_back(Edge(a, b, c, i));
                g[a].push_back(i);
                g[b].push_back(i);
        }

        blocked.resize(n);
        new Tree(0, n);

        while(q--){
                int d;
                ll e;
                std::cin >> d >> e;
                d = (d+last)%(n-1);
                e = (e+last)%w;
                answer(d, e);
                std::cout << last << "\n";
        }
        return 0;
}