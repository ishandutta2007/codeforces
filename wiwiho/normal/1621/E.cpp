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

ll ifloor(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a < 0) return (a - b + 1) / b;
    else return a / b;
}

ll iceil(ll a, ll b){
    if(b < 0) a *= -1, b *= -1;
    if(a > 0) return (a + b - 1) / b;
    else return a / b;
}

struct Node{
    int mn = 0, tag = 0;
    int rv(){
        return mn + tag;
    }
};

int n, m;
vector<Node> st;

void push(int id){
    st[2 * id + 1].tag += st[id].tag;
    st[2 * id + 2].tag += st[id].tag;
    st[id].mn = st[id].rv();
    st[id].tag = 0;
}

void modify(int l, int r, int v, int L = 0, int R = n, int id = 0){
    if(l <= L && R <= r){
        st[id].tag += v;
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, 2 * id + 1);
    else if(l > M) modify(l, r, v, M + 1, R, 2 * id + 2);
    else{
        modify(l, r, v, L, M, 2 * id + 1);
        modify(l, r, v, M + 1, R, 2 * id + 2);
    }
    st[id].mn = min(st[2 * id + 1].rv(), st[2 * id + 2].rv());
}

int query(int x, int L = 0, int R = n, int id = 0){
    if(L == R) return st[id].rv();
    int M = (L + R) / 2;
    push(id);
    if(x <= M) return query(x, L, M, 2 * id + 1);
    else return query(x, M + 1, R, 2 * id + 2);
}

void solve(){

    cin >> n >> m;
    st.clear();
    st.resize(4 * (n + 1));

    vector<ll> a(n + 1);
    a[0] = MAX;
    for(int i = 1; i <= n; i++) cin >> a[i];
    gsort(a);

    vector<vector<ll>> b(m);
    vector<ll> sum(m), sz(m);
    for(int i = 0; i < m; i++){
        int k;
        cin >> k;
        b[i].resize(k);
        sz[i] = k;
        for(int j = 0; j < k; j++){
            cin >> b[i][j];
            sum[i] += b[i][j];
        }
    }

    auto getpos = [&](int id){
        int l = 0, r = n;
        while(l < r){
            int mid = (l + r + 1) / 2;
            if(a[mid] * sz[id] >= sum[id]) l = mid;
            else r = mid - 1;
        }
        return l;
    };

    for(int i = 1; i <= n; i++) modify(i, i, i);

    /*cerr << "a ";
    printv(a, cerr);

    cerr << "OAO\n";
    for(int k = 0; k <= n; k++) cerr << query(k) << " ";
    cerr << "\n";*/
    for(int i = 0; i < m; i++){
        int pos = getpos(i);
        modify(pos, n, -1);
        //cerr << "test " << i << " " << sum[i] << " " << sz[i] << "  " << pos << "\n";
    }
    /*cerr << "OAO\n";
    for(int k = 0; k <= n; k++) cerr << query(k) << " ";
    cerr << "\n";*/

    string ans;
    for(int i = 0; i < m; i++){
        int pos = getpos(i);
        for(int j = 0; j < sz[i]; j++){
            sum[i] -= b[i][j];
            sz[i]--;
            int pos2 = getpos(i);
            
            //cerr << "pos2 " << i << " " << j << " " << sum[i] << " " << sz[i] << "  " << pos2 << "\n";

            sum[i] += b[i][j];
            sz[i]++;

            modify(pos, n, 1);
            modify(pos2, n, -1);
            //for(int k = 0; k <= n; k++) cerr << query(k) << " ";
            //cerr << "\n";
            if(st[0].rv() >= 0) ans += '1';
            else ans += '0';
            modify(pos2, n, 1);
            modify(pos, n, -1);
        }
    }

    cout << ans << "\n";
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        solve();
    }

    return 0;
}