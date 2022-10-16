#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector,fast-math,inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2")

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

template<typename C> struct rge{C l, r;};
template<typename C> rge<C> range(C i, C j) { return rge<C>{i, j}; }
template<typename C> ostream& operator<<(ostream &os, rge<C> &r) { os << '{'; for(auto it = r.l; it != r.r; it++) os << "," + (it == r.l) << *it; os << '}'; return os; }
template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '{' << p.first << "," << p.second << '}'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ","; return os << '}'; }
void dbg_out() { cerr << ']' << endl; }
template<typename A> void dbg_out(A H) { cerr << H; dbg_out(); }
template<typename A, typename B, typename... C> void dbg_out(A H, B G, C... T) { cerr << H << ","; dbg_out(G, T...); }
#ifdef DEBUG
#define debug(...) cerr << "[" << #__VA_ARGS__ << "] = [", dbg_out(__VA_ARGS__)
#else
#define debug(...)
#endif

mt19937_64 rng(chrono::steady_clock::now().time_since_epoch().count());

uint64_t splitmix64(uint64_t x) {
    // http://xorshift.di.unimi.it/splitmix64.c
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
}

// kactl
struct Tree {
	typedef ll T;
	static constexpr T unit = 0;
	T f(T a, T b) { return a + b; }
	vector<T> s; int n;
	Tree(int n = 0, T def = unit) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
        T out = unit;
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) out = f(out, s[b++]);
			if (e % 2) out = f(out, s[--e]);
		}
		return out;
	}
};

const int NS = 30;

int chash(int x, ll seed){
    return splitmix64(seed + x) % 1000000000;
}

void solve(){
    int n, q;
    cin >> n >> q;
    vi v(n);
    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vll seeds(NS);
    for(int i = 0; i < NS; i++) seeds[i] = rng();

    vector<Tree*> trees(NS);
    for(int i = 0; i < NS; i++){
        trees[i] = new Tree(n);
    }
    for(int i = 0; i < NS; i++){
        for(int j = 0; j < n; j++){
            trees[i]->update(j, chash(v[j], seeds[i]));
        }
    }

    while(q--){
        int t;
        cin >> t;
        if(t == 1){
            int pos, val;
            cin >> pos >> val;
            pos--;
            for(int i = 0; i < NS; i++){
                trees[i]->update(pos, chash(val, seeds[i]));
            }
        }else if(t == 2){
            int l, r, k;
            cin >> l >> r >> k;
            l--;
            if(k == 1){
                cout << "YES" << endl;
            }else{
                bool ok = true;
                for(int i = 0; i < NS; i++){
                    ll res = trees[i]->query(l, r);
                    if(res % k != 0){
                        ok = false;
                        break;
                    }
                }
                if(ok){
                    cout << "YES" << endl;
                }else{
                    cout << "NO" << endl;
                }
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}