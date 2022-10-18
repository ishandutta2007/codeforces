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

struct Node{
    int l = -1, r = -1;
    ll mxo = -MAX, mxe = 0, mno = MAX, mne = 0;
};

vector<Node> st;
int ts =0 ;
vector<int> a;

int pull(int id){
    int lc = st[id].l, rc = st[id].r;
    st[id].mxo = max(st[lc].mxo - st[rc].mne, st[lc].mxe + st[rc].mxo);
    st[id].mxe = max(st[lc].mxo - st[rc].mno, st[lc].mxe + st[rc].mxe);
    st[id].mno = min(st[lc].mno - st[rc].mxe, st[lc].mne + st[rc].mno);
    st[id].mne = min(st[lc].mno - st[rc].mxo, st[lc].mne + st[rc].mne);
}

int build(int l, int r){
    int id = ts++;
    if(l == r){
        st[id].mxo = st[id].mno = a[l];
        return id;
    }
    int m = (l + r) / 2;
    st[id].l = build(l, m);
    st[id].r = build(m + 1, r);
    pull(id);
//    cerr << "build " << l << " " << r << " " << st[id].mxe << " " << st[id].mxo << "\n";
    return id;
}

void modify(int x, ll v, int L, int R, int id){
    if(L == R){
        st[id].mxo = st[id].mno = v;
        return;
    }
    int M = (L + R) / 2;
    if(x <= M) modify(x, v, L, M, st[id].l);
    else modify(x, v, M + 1, R, st[id].r);
    pull(id);
//    cerr << "modify " << x << " " << v << " " << L << ' ' << R << " " << id << " ";
//    cerr << st[id].mxe << " " << st[id].mxo << "\n";
}

int main(){
    StarBurstStream

    int T;
    cin >> T;
    while(T--){
        int n, q;
        cin >> n >> q;
//        cerr << n << " " << q << "\n";

        a.clear();
        a.resize(n + 1);
        for(int i = 1; i <= n; i++) cin >> a[i];

        st.clear();
        st.resize(2 * n);
        ts = 0;
        build(1, n);

        cout << max(st[0].mxe, st[0].mxo) << "\n";

        while(q--){
            int l, r;
            cin >> l >> r;
            int al = a[l], ar = a[r];
            modify(l, ar, 1, n, 0);
            modify(r, al, 1, n, 0);
            swap(a[l], a[r]);
//            cerr << st[0].mxe << " " << st[0].mxo << "\n";
            cout << max(st[0].mxe, st[0].mxo) << "\n";
        }

//        cerr << "test\n";
    }

    return 0;
}