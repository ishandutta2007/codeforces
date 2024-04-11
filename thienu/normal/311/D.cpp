#include <bits/stdc++.h>

using namespace std;

#define u_map unordered_map
#define u_set unordered_set
#define u_multiset unordered_multiset

using ll = long long;
using vvi = vector<vector<int>>;
using vi = vector<int>;
using vvll = vector<vector<long long>>;
using vll = vector<long long>;
using vd = vector<double>;
using vvd = vector<vector<double>>;
using pii = pair<int, int>;
using vpii = vector<pair<int, int>>;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef DEBUG
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define debug(x...)
#endif

const ll MOD = 95542721;

ll mul(ll a, ll b){
    return a * b % MOD;
}

ll add(ll a, ll b){
    return (a + b) % MOD;
}

ll sub(ll a, ll b){
    return (a - b + MOD) % MOD;
}

ll normalize(ll x){
    return ((x % MOD) + MOD) % MOD;
}

ll binexp(ll a, ll b){
    ll ans = 1;
    while(b){
        if(b & 1) ans = mul(ans, a);
        a = mul(a, a);
        b >>= 1;
    }
    return ans;
}

ll inv(ll x){
    return binexp(x, MOD - 2);
}

const int C = 48;

template <int N>
struct Vec{
    vll v;

    Vec(){
        v.resize(N);
    }

    Vec(vi _v){
        v = _v;
    }

    Vec<N> operator+(Vec<N> other){
        Vec<N> nv;
        for(int i = 0; i < N; i++){
            nv.v[i] = add(v[i], other.v[i]);
        }
        return nv;
    }
    Vec<N> operator-(Vec<N> other){
        Vec<N> nv;
        for(int i = 0; i < N; i++){
            nv.v[i] = sub(v[i], other.v[i]);
        }
        return nv;
    }
    Vec<N> operator*(int s){
        Vec<N> nv;
        for(int i = 0; i < N; i++){
            nv.v[i] = mul(v[i], s);
        }
        return nv;
    }

    int sum(){
        return accumulate(v.begin(), v.end(), 0LL) % MOD;
    }

    vi nonzero(){
        vi ans;
        for(int i = 0; i < N; i++){
            if(v[i] != 0){
                ans.push_back(i);
            }
        }
        return ans;
    }

    void rotate(){
        v.push_back(v[0]);
        v.erase(v.begin());
    }
};
template <int N>
void __print(Vec<N> x) {_print(x.v);}

struct Node{
    int lo, hi;
    Node* l;
    Node* r;
    Vec<C> v;
    int mrot = 0;

    void recalc(){
        assert(l && r);
        v = l->v + r->v;
    }

    Node(int lo, int hi, vi &x) : lo(lo), hi(hi) {
        if(lo + 1 < hi){
            int mid = lo + (hi - lo) / 2;
            l = new Node(lo, mid, x);
            r = new Node(mid, hi, x);
            recalc();
        }else{
            v.v[0] = normalize(x[lo]);
            for(int j = 1; j < C; j++){
                v.v[j] = binexp(v.v[j-1], 3);
            }
        }
    }

    void rotate(int L, int R, int amt){
        if(hi <= L || R <= lo){
            return;
        }
        if(L <= lo && hi <= R){
            mrot = (mrot + amt) % C;
            while(amt--){
                v.rotate();
            }
            return;
        }
        push();
        l->rotate(L, R, amt);
        r->rotate(L, R, amt);
        recalc();
    }

    ll query(int L, int R){
        if(hi <= L || R <= lo){
            return 0;
        }
        if(L <= lo && hi <= R){
            return v.v[0];
        }
        push();
        return add(l->query(L, R), r->query(L, R));
    }

    void push(){
        if(mrot != 0){
            l->rotate(lo, hi, mrot);
            r->rotate(lo, hi, mrot);
            mrot = 0;
        }
    }
};

void solve(){
    int n;
    cin >> n;
    vi v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    Node* st = new Node(0, n, v);
    debug(st->v);

    int q;
    cin >> q;
    while(q--){
        int t, l, r;
        cin >> t >> l >> r;
        l--;
        if(t == 1){
            cout << st->query(l, r) << endl;
        }else{
            st->rotate(l, r, 1);
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}