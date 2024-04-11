
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
    int v = 0, tag = 0;
    int rv(){
        return v + tag;
    }
};

vector<Node> st;

void push(int id){
    st[2 * id + 1].tag += st[id].tag;
    st[2 * id + 2].tag += st[id].tag;
    st[id].v = st[id].rv();
    st[id].tag = 0;
}

void modify(int l, int r, int v, int L, int R, int id){
    if(l == L && r == R){
//        cerr << "modify " << l << " " << r << " " << L << " " << R << "\n";
        st[id].tag += v;
        return;
    }
    int M = (L + R) / 2;
    if(r <= M) modify(l, r, v, L, M, 2 * id + 1);
    else if(l > M) modify(l, r, v, M + 1, R, 2 * id + 2);
    else{
        modify(l, M, v, L, M, 2 * id + 1);
        modify(M + 1, r, v, M + 1, R, 2 * id + 2);
    }
    st[id].v = min(st[2 * id + 1].rv(), st[2 * id + 2].rv());
}

void print(int L, int R, int id){
    if(L == R){
        cerr << st[id].rv() << " ";
        return;
    }
    push(id);
    int M = (L + R) / 2;
    print(L, M, 2 * id + 1);
    print(M + 1, R, 2 * id + 2);
}

int main(){
    StarBurstStream

    int n, m;
    cin >> n >> m;
    m = m * 2 - 1;
    st.resize(4 * m);

    vector<vector<pii>> seg(1000001);
    for(int i = 0; i < n; i++){
        int l, r, w;
        cin >> l >> r >> w;
        l = l * 2 - 1;
        r = r * 2 - 1;
        seg[w].eb(mp(l, r));
    }

    int ans = 1000000;
    int rp = 0;
    for(int i = 1; i <= 1000000; i++){
        rp = max(rp, i - 1);
        while(rp < 1000000 && st[0].rv() == 0){
            rp++;
            for(pii p : seg[rp]){
                modify(p.F, p.S, 1, 1, m, 0);
//                cerr << "add " << rp  << " " << p << "\n";
//                print(1, m, 0);
//                cerr << "\n";
            }
        }
        if(st[0].rv() > 0) ans = min(ans, rp - i);
//        cerr << "test " << i << " " << rp << " " << st[0].rv() << "\n";
//        print(1, m, 0);
//        cerr << "\n";
        for(pii p : seg[i]){
            modify(p.F, p.S, -1, 1, m, 0);
//            cerr << "remove " << i << " " << p << "\n";
//            print(1, m, 0);
//            cerr << "\n";
        }
    }
    cout << ans << "\n";

    return 0;
}