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
const ll MAX = 1000000000;
template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int main(){
    StarBurstStream

    int n, m, k;
    cin >> n >> m >> k;

    vector<int> a(k);
    for(int i = 0; i < k; i++) cin >> a[i];

    vector<vector<int>> g(n + 1);

    for(int i = 0; i < m; i++){
        int u, v;
        cin >> u >> v;
        g[u].eb(v);
        g[v].eb(u);
    }

    vector<int> dis1(n + 1, -1), disn(n + 1, -1);

    deque<int> q;
    q.eb(1);
    dis1[1] = 0;
    while(!q.empty()){
        int v = q.front();
//        cerr << v << "\n";
        q.pof;
        for(int i : g[v]){
            if(dis1[i] != -1) continue;
//            cerr << i << " " << v << "\n";
            dis1[i] = dis1[v] + 1;
            //cerr << i << ' ' << v << " " << dis1[i] << "\n";
            q.eb(i);
        }
    }
    //printv(dis1, cerr);

    q.clear();
    q.eb(n);
    disn[n] = 0;
    while(!q.empty()){
        int v = q.front();
        q.pof;
        for(int i : g[v]){
            if(disn[i] != -1) continue;
            disn[i] = disn[v] + 1;
            q.eb(i);
        }
    }

    vector<pii> dis;
    for(int i = 0; i < k; i++){
        dis.eb(mp(dis1[a[i]], disn[a[i]]));
    }
    lsort(dis);

    vector<int> diff(k);
    for(int i = 0; i < k; i++) diff[i] = dis[i].F - dis[i].S;
    vector<int> r(k);
    deque<int> dq;
    for(int i = 0; i < k; i++){
        while(!dq.empty() && diff[dq.back()] > diff[i]) dq.pob;
        if(dq.empty()) r[i] = -1;
        else r[i] = dq.back();
        dq.eb(i);
    }

    vector<vector<int>> st(k, vector<int>(20));
    for(int i = 0; i < k; i++) st[i][0] = dis[i].S;
    for(int i = 1; i < 20; i++){
        for(int j = 0; j + (1 << i) - 1 < k; j++){
            st[j][i] = max(st[j][i - 1], st[j + (1 << (i - 1))][i - 1]);
        }
    }

    int mx = 0;
    for(int i = 1; i < k; i++){
        int tmp = r[i];
        int ll = tmp + 1, rr = i - 1;
        int len = rr - ll + 1;
        int mmm = ll <= rr ? max(st[ll][__lg(len)], st[rr - (1 << __lg(len)) + 1][__lg(len)]) + dis[i].F : MAX;
        int ttt = tmp == -1 ? MAX : dis[i].S + dis[tmp].F;
        mx = max(mx, min(mmm, ttt));
    }

//    cerr << mx + 1 << " " << dis1[n] << "\n";
    cout << min(mx + 1, dis1[n]) << "\n";

    return 0;
}