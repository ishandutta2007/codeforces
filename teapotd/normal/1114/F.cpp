#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
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

constexpr int MAX_N = 301;
constexpr ll MOD = 1e9+7;

constexpr int PRIMES[] = { 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293 };
constexpr int N_PRIMES = sizeof(PRIMES) / sizeof(int);

ll masks[MAX_N];

struct Zp {
    ll x;
    Zp(ll a = 0) {
        if (a < 0) a = a%MOD + MOD;
        else if (a >= MOD*2) a %= MOD;
        else if (a >= MOD) a -= MOD;
        x = a;
    }

    Zp operator+(Zp r) const{ return x+r.x; }
    Zp operator-(Zp r) const{ return x-r.x+MOD; }
    Zp operator*(Zp r) const{ return x*r.x; }
    Zp operator/(Zp r) const{return x*r.inv().x;}
    Zp operator-()     const{ return MOD-x; }
    Zp inv() const { return pow(MOD-2); }

    Zp pow(ll e) const {
        Zp t = 1, m = *this;
        while (e) {
            if (e & 1) t = t*m;
            e >>= 1; m = m*m;
        }
        return t;
    }

    #define OP(c) Zp& operator c##=(Zp r){ return *this=*this c r; }
    OP(+)OP(-)OP(*)OP(/)
    void print() { cerr << x; }
};

struct SegmentTree {
    struct T {
        Zp elem;
        ll mask;
    };

    struct Node {
        T extra{1, 0};
        T agg{1, 0};

        void init(T x, int size) {
            extra = agg = x;
            agg.elem = x.elem.pow(size);
        }

        void merge(const Node& R) {
            agg.elem *= R.agg.elem;
            agg.mask |= R.agg.mask;
        }

        T apply(T x, int size) {
            extra.elem *= x.elem;
            extra.mask |= x.mask;
            agg.elem *= x.elem.pow(size);
            agg.mask |= x.mask;
            return x;
        }
    };

    vector<Node> V;
    int len;

    SegmentTree(int n=0, T def={1,0}) {init(n,def);}

    void init(int n, T def) {
        for (len = 1; len < n; len *= 2);
        V.assign(len*2, {});
        rep(i, len, len+n) V[i].init(def, 1);
        for (int i = len-1; i > 0; i--) update(i);
    }

    int getChild(int i, int j) { return i*2+j; }
    int L(int i) { return getChild(i, 0); }
    int R(int i) { return getChild(i, 1); }

    void update(int i) {
        int a = L(i), b = R(i);
        V[i] = {};
        V[i].merge(V[a]);
        V[i].merge(V[b]);
    }

    void push(int i, int size) {
        auto e = V[i].extra;
        if (e.elem.x != 1) {
            e = V[L(i)].apply(e, size/2);
            V[R(i)].apply(e, size/2);
            V[i].extra = {1,0};
        }
    }

    T modify(int vBegin, int vEnd, T x, int i = 1, int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (vEnd <= begin || end <= vBegin) return x;

        if (vBegin <= begin && end <= vEnd) {
            return V[i].apply(x, end-begin);
        }

        int mid = (begin + end) / 2;
        push(i, end-begin);
        x = modify(vBegin,vEnd,x,L(i),begin,mid);
        x = modify(vBegin,vEnd,x,R(i),mid,end);
        update(i);
        return x;
    }

    Node query(int vBegin, int vEnd, int i = 1, int begin = 0, int end = -1) {
        if (end < 0) end = len;
        if (vEnd <= begin || end <= vBegin) return {};
        if (vBegin <= begin && end <= vEnd) return V[i];

        int mid = (begin + end) / 2;
        push(i, end-begin);
        Node x = query(vBegin,vEnd,L(i),begin,mid);
        x.merge(query(vBegin,vEnd,R(i),mid,end));
        return x;
    }
};

void run() {
    vector<Zp> mults;

    rep(i, 0, N_PRIMES) {
        int p = PRIMES[i];
        for (int j = p; j < MAX_N; j += p) masks[j] |= 1LL << i;
        mults.pb(Zp(p-1) / Zp(p));
    }

    int n, m; cin >> n >> m;
    SegmentTree tree(n);

    rep(i, 0, n) {
        int x; cin >> x;
        tree.modify(i, i+1, {x, masks[x]});
    }

    while (m--) {
        string type; cin >> type;
        int l, r; cin >> l >> r;
        l--;

        if (type[0] == 'M') {
            int x; cin >> x;
            tree.modify(l, r, {x, masks[x]});
        } else {
            auto q = tree.query(l, r);
            Zp ret = q.agg.elem;

            rep(i, 0, N_PRIMES) if ((q.agg.mask >> i) & 1) {
                ret *= mults[i];
            }

            cout << ret.x << '\n';
        }
    }
}