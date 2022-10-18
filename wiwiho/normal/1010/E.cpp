#include <bits/stdc++.h>
#include <bits/extc++.h>

#define StarBurstStream ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
#define iter(a) a.begin(), a.end()
#define riter(a) a.rbegin(), a.rend()
#define lsort(a) sort(iter(a))
#define gsort(a) sort(riter(a))
#define pb(a) push_back(a)
#define eb(a) emplace_back(a)
#define pf(a) push_front(a)
#define ef(a) emplace_front(a)
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) (((a) + (b) - 1) / (b))
#define tomax(a, b) ((a) = max((a), (b)))
#define tomin(a, b) ((a) = min((a), (b)))
#define topos(a) ((a) = (((a) % MOD + MOD) % MOD))
#define uni(a) a.resize(unique(iter(a)) - a.begin())
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

using namespace std;
using namespace __gnu_pbds;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

using pii = pair<int, int>;
using pll = pair<ll, ll>;
using pdd = pair<ld, ld>;
using tiii = tuple<int, int, int>;

const ll MOD = 1000000007;
const ll MAX = 2147483647;

template<typename A, typename B>
ostream& operator<<(ostream& o, pair<A, B> p){
    return o << '(' << p.F << ',' << p.S << ')';
}

int lowbit(int x){
    return x & -x;
}

int xmx, ymx, zmx, n, m, k;


struct BIT{
    gp_hash_table<int, int> bit;
    BIT() = default;

    void modify(int x, int v){
        for(; x <= zmx; x += lowbit(x)){
            bit[x] += v;
        }
    }

    int query(int x){
        int ans = 0;
        for(; x > 0; x -= lowbit(x)){
            if(bit.find(x) != bit.end()) ans += bit[x];
        }
        return ans;
    }
};

struct BIT2D{
    gp_hash_table<int, BIT> bit;
    BIT2D() = default;

    void modify(int x, int y, int v){
        for(; x <= ymx; x += lowbit(x)){
            bit[x].modify(y, v);
        }
    }

    int query(int x, int y){
        int ans = 0;
        for(; x > 0; x -= lowbit(x)){
            if(bit.find(x) != bit.end()) ans += bit[x].query(y);
        }
        return ans;
    }
};

int query(BIT2D& bit, int xl, int xr, int yl, int yr){
    return bit.query(xr, yr) - bit.query(xr, yl - 1) - bit.query(xl - 1, yr) + bit.query(xl - 1, yl - 1);
}

int main(){
    StarBurstStream

    cin >> xmx >> ymx >> zmx >> n >> m >> k;

    int xl = MAX, xr = 0, yl = MAX, yr = 0, zl = MAX, zr = 0;
    for(int i = 0; i < n; i++){
        int x, y, z;
        cin >> x >> y >> z;
        xl = min(xl, x);
        xr = max(xr, x);
        yl = min(yl, y);
        yr = max(yr, y);
        zl = min(zl, z);
        zr = max(zr, z);
    }

    vector<vector<pii>> no(xmx + 1);
    for(int i = 0; i < m; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if((xl <= x && x <= xr) && (yl <= y && y <= yr) && (zl <= z && z <= zr)){
            cout << "INCORRECT\n";
            return 0;
        }
        no[x].eb(mp(y, z));
    }

    vector<vector<pair<pii, int>>> qry(xmx + 1);
    vector<int> ans(k);
    for(int i = 0; i < k; i++){
        int x, y, z;
        cin >> x >> y >> z;
        if((xl <= x && x <= xr) && (yl <= y && y <= yr) && (zl <= z && z <= zr)){
            ans[i] = 1;
            continue;
        }
        qry[x].eb(mp(mp(y, z), i));
    }

    {
        BIT2D bit;
        for(int i = xl; i <= xmx; i++){
            for(pii j : no[i]){
                bit.modify(j.F, j.S, 1);
//                cerr << j.F << ' ' << j.S << "\n";
            }
            for(auto j : qry[i]){
                int tyl = min(yl, j.F.F);
                int tyr = max(yr, j.F.F);
                int tzl = min(zl, j.F.S);
                int tzr = max(zr, j.F.S);
//                cerr << j << " " << tyl << " " << tyr << ' ' << tzl << " " << tzr << "\n";
                if(query(bit, tyl, tyr, tzl, tzr)) ans[j.S] = 2;
            }
        }
    }
    {
        BIT2D bit;
        for(int i = xr; i > 0; i--){
            for(pii j : no[i]){
                bit.modify(j.F, j.S, 1);
//                cerr << j.F << ' ' << j.S << "\n";
            }
            for(auto j : qry[i]){
                int tyl = min(yl, j.F.F);
                int tyr = max(yr, j.F.F);
                int tzl = min(zl, j.F.S);
                int tzr = max(zr, j.F.S);
//                cerr << j << " " << tyl << " " << tyr << ' ' << tzl << " " << tzr << "\n";
                if(query(bit, tyl, tyr, tzl, tzr)) ans[j.S] = 2;
            }
        }
    }

    cout << "CORRECT\n";
    for(int i = 0; i < k; i++){
        if(ans[i] == 0) cout << "UNKNOWN\n";
        else if(ans[i] == 1) cout << "OPEN\n";
        else if(ans[i] == 2) cout << "CLOSED\n";
    }

    return 0;
}