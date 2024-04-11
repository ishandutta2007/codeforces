//#define NDEBUG

#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define mp(a, b) make_pair(a, b)
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define pob pop_back()
#define pof pop_front()
#define F first
#define S second
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}
#define pii pair<int, int>
#define pll pair<ll, ll>
#define tiii tuple<int, int, int>
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a) / (b) + !!((a) % (b)))

//#define TEST

typedef long long ll;
typedef unsigned long long ull;

using namespace std;
using namespace __gnu_pbds;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

struct Node{
    int l = -1, r = -1;
};

vector<Node> st;
int n;
int cnt = 1;

vector<vector<pll>> g;

int build(int l, int r, int id, bool t){
    if(id == -1) id = cnt++, g.eb();
//    cerr << l << " " << r << " " << id << " " << t << " " << g.size() << "\n";
    if(l == r){
        if(t) g[id + n].eb(mp(l, 0));
        else g[l].eb(mp(id + n, 0));
        return id;
    }
    int m = (l + r) / 2;
    st[id].l = build(l, m, -1, t);
    st[id].r = build(m + 1, r, -1, t);
    if(t) g[id + n].eb(mp(st[id].l + n, 0)), g[id + n].eb(mp(st[id].r + n, 0));
    else g[st[id].l + n].eb(mp(id + n, 0)), g[st[id].r + n].eb(mp(id + n, 0));
    return id;
}

vector<int> vn;
void query(int l, int r, int L, int R, int id){
    if(l == L && r == R){
        vn.eb(id + n);
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) query(l, r, L, M, st[id].l);
    else if(l > M) query(l, r, M + 1, R, st[id].r);
    else{
        query(l, M, L, M, st[id].l);
        query(M + 1, r, M + 1, R, st[id].r);
    }
}

int main(){
    StarBurstStream

    int q, s;
    cin >> n >> q >> s;

    st.resize(8 * n);
    g.resize(n + 1);
    int r1 = build(1, n, -1, true);
    int r2 = build(1, n, -1, false);


    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int v, u, w;
            cin >> v >> u >> w;
            g[v].eb(mp(u, w));
        }
        else if(t == 2){
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            vn.clear();
            query(l, r, 1, n, r1);
            for(int i : vn) g[v].eb(mp(i, w));
        }
        else{
            int v, l, r, w;
            cin >> v >> l >> r >> w;
            vn.clear();
            query(l, r, 1, n, r2);
            for(int i : vn) g[i].eb(mp(v, w));
        }
    }

//    for(int i = 1; i < g.size(); i++){
//        cerr << i << "  ";
//        printv(g[i], cerr);
//    }

    std::priority_queue<pll, vector<pll>, greater<>> pq;
    vector<ll> dis(g.size(), -1);
    dis[s] = 0;
    pq.push(mp(0, s));
    while(!pq.empty()){
        pll now = pq.top();
        pq.pop();
        if(now.F > dis[now.S]) continue;
        for(pll i : g[now.S]){
            if(now.F + i.S >= dis[i.F] && dis[i.F] != -1) continue;
            dis[i.F] = now.F + i.S;
            pq.push(mp(dis[i.F], i.F));
        }
    }

    for(int i = 1; i <= n; i++) cout << dis[i] << " ";
    cout << "\n";

    return 0;
}