//#define NDEBUG

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
#define pob pop_back()
#define pof pop_front()
#define mp(a, b) make_pair(a, b)
#define F first
#define S second
#define mt make_tuple
#define gt(t, i) get<i>(t)
#define iceil(a, b) ((a + b - 1) / b)
#define tomax(a, b) (a = max(a, b))
#define printv(a, b) {bool pvaspace=false; \
for(auto pva : a){ \
    if(pvaspace) b << " "; pvaspace=true;\
    b << pva;\
}\
b << "\n";}

//#define TEST

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

vector<int> BIT;

int lowbit(int x){
    return x & -x;
}

void modify(int x, int v){
    for(; x < BIT.size(); x += lowbit(x)){
        BIT[x] += v;
    }
}

int query(int x){
    int ans = 0;
    for(; x > 0; x -= lowbit(x)){
        ans += BIT[x];
    }
    return ans;
}

int main(){
    StarBurstStream

    int n, q;
    cin >> n >> q;

    vector<vector<int>> pos(n + 1);
    for(int i = 1; i <= n; i++){
        int p;
        cin >> p;
        pos[p].eb(i);
    }

    BIT.resize(n + 1);

    vector<vector<pair<pii, int>>> qry(n + 1);
    for(int i = 0; i < q; i++){
        int l, d, r, u;
        cin >> l >> d >> r >> u;

        qry[d - 1].eb(mp(mp(0, l - 1), 9 * i));
        qry[d - 1].eb(mp(mp(l, r), 9 * i + 1));
        qry[d - 1].eb(mp(mp(r + 1, n), 9 * i + 2));
        qry[u].eb(mp(mp(0, l - 1), 9 * i + 3));
        qry[u].eb(mp(mp(l, r), 9 * i + 4));
        qry[u].eb(mp(mp(r + 1, n), 9 * i + 5));
        qry[n].eb(mp(mp(0, l - 1), 9 * i + 6));
        qry[n].eb(mp(mp(l, r), 9 * i + 7));
        qry[n].eb(mp(mp(r + 1, n), 9 * i + 8));
    }

    vector<int> qans(9 * q);
    for(int i = 0; i <= n; i++){
        for(int j : pos[i]) modify(j, 1);
//        cerr << i << "  ";
//        for(int j = 1; j <= n; j++) cerr << query(j) - query(j - 1) << " ";
//        cerr << "\n";
        for(auto j : qry[i]){
            qans[j.S] = query(j.F.S) - query(j.F.F - 1);
        }
    }

    for(int i = 0; i < q; i++){
        vector<ll> a(9);
        for(int j = 0; j < 9; j++) a[j] = qans[i * 9 + j] - (j >= 3 ? qans[i * 9 + j - 3] : 0);
//        cerr << i << "  ";
//        printv(a, cerr);
        ll ans = a[8] * (a[0] + a[1] + a[3] + a[4]) + a[7] * (a[3] + a[4] + a[0] + a[1] + a[5] + a[2])
                + a[6] * (a[4] + a[5] + a[1] + a[2]) + a[5] * (a[4] + a[3] + a[0] + a[1])
                + a[4] * (a[3] + a[0] + a[1] + a[2]) + a[3] * (a[1] + a[2])
                + a[4] * (a[4] - 1) / 2;
        cout << ans << "\n";
    }

    return 0;
}