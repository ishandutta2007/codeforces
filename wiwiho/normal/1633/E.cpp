#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define eb emplace_back
#define ef emplace_front
#define pob pop_back()
#define pof pop_front()
#define mp make_pair
#define F first
#define S second
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) { \
    for(auto pv : a) b << pv << " "; \
    b << "\n"; \
}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a/ b;
}

vector<int> dsu;

int findDSU(int a){
    if(dsu[a] != a) dsu[a] = findDSU(dsu[a]);
    return dsu[a];
}

void unionDSU(int a, int b){
    a = findDSU(a); b = findDSU(b);
    dsu[b] = dsu[a];
}

void mst(int n, vector<pair<int, pii>> &e, vector<pair<int, pii>> &ans){
    dsu.clear();
    dsu.resize(n + 1);
    for(int i = 1; i <= n; i++) dsu[i] = i;

    for(auto i : e){
        if(findDSU(i.S.F) == findDSU(i.S.S)) continue;
        unionDSU(i.S.F, i.S.S);
        ans.eb(i);
    }
}

int main(){
    StarBurstStream;

    int n, m;
    cin >> n >> m;

    vector<int> pos(m);
    vector<int> rk(m);
    vector<pair<int, pii>> e;
    for(int i = 0; i < m; i++){
        int u, v, w;
        cin >> u >> v >> w;
        e.eb(mp(w, mp(u, v)));
    }
    lsort(e);
    for(int i = 0; i < m; i++){
        rk[i] = pos[i] = i;
    }
    //printv(e, cerr);

    vector<pair<int, pii>> pnt;
    pnt.eb(mp(-1, mp(-1, -1)));
    for(int i = 0; i < m; i++){
        for(int j = i + 1; j < m; j++){
            int a = e[i].F, b = e[j].F;
            pnt.eb(mp(iceil(a + b, 2), mp(i, j)));
        }
    }
    lsort(pnt);
    int sz = pnt.size();

    vector<vector<ll>> qry(sz);

    //printv(pnt, cerr);
    auto addqry = [&](int x){
        auto it = upper_bound(iter(pnt), mp(x, mp(INT_MAX, INT_MAX)));
        it--;
        int id = it - pnt.begin();
        qry[id].eb(x);
        //cerr << "addqry " << x << " " << id << " " << pnt[id].F << "\n";
    };

    {
        ll p, k, a, b, c;
        cin >> p >> k >> a >> b >> c;
        ll lst = 0;
        for(int i = 0; i < p; i++){
            int x; cin >> x;
            addqry(x);
            lst = x;
        }
        for(int i = p; i < k; i++){
            lst = (lst * a + b) % c;
            addqry(lst);
        }
    }

    ll xans = 0;
    for(int i = 0; i < sz; i++){

        if(pnt[i].F != -1){
            int e1 = pnt[i].S.F, e2 = pnt[i].S.S;
            int r1 = pos[e1], r2 = pos[e2];
            swap(rk[r1], rk[r2]);
            swap(pos[e1], pos[e2]);
        }

        if(qry[i].empty()) continue;
        /*cerr << "test " << pnt[i].F << "  ";
        printv(rk, cerr);
        printv(qry[i], cerr);
        for(int j = 0; j < m; j++){
            cerr << abs(e[rk[j]].F - pnt[i].F) << " ";
        }
        cerr << "\n";*/

        vector<pair<int, pii>> te, ans;
        for(int i : rk){
            te.eb(e[i]);
        }
        mst(n, te, ans);
        //printv(ans, cerr);
        
        for(int x : qry[i]){
            ll sum = 0;
            for(auto t : ans) sum += abs(t.F - x);
            //cerr << "qry " << x << " " << sum << "\n";
            xans ^= sum;
        }
    }

    cout << xans << "\n";

    return 0;
}