#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
#pragma GCC optimize("Ofast") // optimizes doubles + vectors
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e6, M = 1e9+7;
//#define runcase LOL
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<array<int, 2>> var2;
typedef vector<array<int, 3>> var3;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

#define FOR(j, V) for(int j = 0; j < V; j++)
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define DOR(tt, X) for(int tt = X; tt >= 0; --tt)
#define pb push_back
#define all(X) X.begin(),X.end()
#define vt vector
#define sz(X) int(X.size())
#define ub upper_bound
#define lb lower_bound
// template insertion spaces
template<class Fun>
class y_combinator_result {
    Fun fun_;
    public:
    template<class T>
        explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

    template<class ...Args>
        decltype(auto) operator()(Args &&...args) {
            return fun_(std::ref(*this), std::forward<Args>(args)...);
        }
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
    return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}


template <typename T> using oset = tree<T, null_type, std::less_equal<T>, rb_tree_tag, tree_order_statistics_node_update>;
template<typename T>
struct polynomial_hash {
    int n;
    string s;
    T m, b; // prime mod, base
    vector<T> hash, inverse; // hash[i] : hash value of s[0, i - 1]

    polynomial_hash() {}

    polynomial_hash(const string &_s, T _m, T _b) {
        init(_s, _m, _b);
    }
    
    void init(const string &_s, T _m, T _b) {
        s = _s;
        n = (int) (s.size());
        m = _m;
        b = _b;
        hash.resize(n + 1);
        inverse.resize(n + 1);
        precompute();
    }

    T binpow(T x, T y) {
        T res = 1;
        while (y > 0) {
            if (y % 2 != 0) res = (res * x) % m;
            x = (x * x) % m;
            y /= 2;
        }

        return res;
    }

    // Builds the hash and inverse array
    void precompute() {
        T power = b;
        hash[0] = 0;
        for (int i = 1; i <= n; i++) {
            hash[i] = (hash[i - 1] + (s[i - 1] - 'a' + 1) * power) % m;
            power = (power * b) % m;
        }

        inverse[n] = binpow(binpow(b, n), m - 2);
        for (int i = n - 1; i > 0; i--)
            inverse[i] = (inverse[i + 1] * b) % m;
    }

    // Returns the hash value of substring s[l, r]
    T get_hash(int l, int r) {
        l++, r++;
        if (l == 1) return hash[r];
        return ((((hash[r] - hash[l - 1]) % m) + m) * inverse[l - 1]) % m;
    }
};
// int n, q;

const int MAX_LOG = 20, N = 1e5+5, MAX = 100;
ll n, x, y, a, b, k, m;
ll modpow(ll x, ll y, const ll M) {
    ll res = 1;
    while(y) {
        if(y&1)
            res=res*x%M;
        x=x*x%M;
        y >>= 1;
    }
    return res;
}
void solve(int test_case = 0)
{
    string x, y;
    cin >> x >> y;
    polynomial_hash<ll> hs(x, int(1e9)+7, 31);
    polynomial_hash<ll> hs1(y, int(1e9)+7, 31);
    if(false) {
    } else {
        vi ans;
        for(int i = 0; i < int(x.size()); i++) {
            if(i == 0) {
                if(hs.get_hash(i + 1, sz(x)-1) == hs1.get_hash(0, sz(y) - 1))
                    ans.pb(i + 1);        
            } else if(i == int(x.size()) - 1) {
                if(hs.get_hash(0, i - 1) == hs1.get_hash(0, sz(y) - 1))
                    ans.pb(i + 1);
            } else {
                ll res = (hs.get_hash(0, i - 1) + modpow(31, i, int(1e9)+7) * hs.get_hash(i + 1, sz(x) - 1) % int(1e9+7)) % int(1e9+7);
                if(res==hs1.get_hash(0, sz(y) - 1))
                    ans.pb(i + 1);
            }
        }
        cout << sz(ans) << "\n";
        for(int i : ans)
            cout << i << " ";
    }


}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    // precalc();
    int T = 1;
#ifdef runcase
    cin >> T;
#endif

    for(int nt = 0, i; nt < T; nt++) {
        solve(nt);
        ++i;
    }
}