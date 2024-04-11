#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <iterator>
// #pragma GCC optimize("OFast") // optimizes doubles + vectors
using namespace __gnu_pbds;
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
const int MAXN = 1e6, M = 1e9+7;
#define runcase LOL
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<ull> vul;
typedef pair<int, int> pi;
typedef vector<pi> vpi;
typedef vector<array<int, 2>> var2;
typedef vector<array<int, 3>> var3;
typedef pair<ll, ll> pl;
typedef vector<pl> vpl;

#define FOR(j, V) for(int j = 0; j < V; j++)
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
int n, q;
#define int long long
const int inf = 1e18;
struct Node {
	Node *l = 0, *r = 0;
	int lo, hi, mset = inf, madd = 0, val = -inf;
	Node(int lo,int hi):lo(lo),hi(hi){} // Large interval of -inf
	Node(vi& v, int lo, int hi) : lo(lo), hi(hi) {
		if (lo + 1 < hi) {
			int mid = lo + (hi - lo)/2;
			l = new Node(v, lo, mid); r = new Node(v, mid, hi);
			val = max(l->val, r->val);
		}
		else val = v[lo];
	}
	int query(int L, int R) {
		if (R <= lo || hi <= L) return -inf;
		if (L <= lo && hi <= R) return val;
		push();
		return max(l->query(L, R), r->query(L, R));
	}
	void set(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) mset = val = x, madd = 0;
		else {
			push(), l->set(L, R, x), r->set(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void add(int L, int R, int x) {
		if (R <= lo || hi <= L) return;
		if (L <= lo && hi <= R) {
			if (mset != inf) mset += x;
			else madd += x;
			val += x;
		}
		else {
			push(), l->add(L, R, x), r->add(L, R, x);
			val = max(l->val, r->val);
		}
	}
	void push() {
		if (!l) {
			int mid = lo + (hi - lo)/2;
			l = new Node(lo, mid); r = new Node(mid, hi);
		}
		if (mset != inf)
			l->set(lo,hi,mset), r->set(lo,hi,mset), mset = inf;
		else if (madd)
			l->add(lo,hi,madd), r->add(lo,hi,madd), madd = 0;
	}
};
#undef int

int check(const string &s) {
    int count = 0;
    const string t = "abacaba";
    
    for (int i = 0; i < n; ++i)
    {
        // ce<< "HELLO";
        
        count += t == s.substr(i, 7);
    }
    return count;
}
void solve(int test_case = 0)
{  
    // int n; cin >> n;
    cerr << "Test Case #" << test_case + 1 << "\n";
    cin >> n;
    string s; cin >> s;
    int count = check(s);
    // cerr << s << "\n";
    // cerr << count << "\n";
    // return;
    // return;
    const string t = "abacaba";

   

    if(count >= 2) {
        cout << "NO\n";
        return;
    } else if(count == 1) {
        cout << "YES\n";
        for(char ch : s)
            cout << (ch == '?' ? 'z' : ch);
        cout << "\n";
        return;
    } else {
        for(int i = 0; i < n; ++i) {
            if(i + 6 >= n)
                break;
            bool works = true;
            for(int j = 0; j<7;++j) {
                assert(i + j < n);
                works &= (s[i+j] == t[j] || s[i+j] == '?');
            }
            if(works) {
                string temp=s.substr(i, 7);
                for(int j = 0; i+j<n&&j<7;++j)
                    s[i+j]=t[j];
                if(check(s) == 1) {
                    cout << "YES\n";
                    for (char ch : s)
                        cout << (ch == '?' ? 'z' : ch);
                    cout << "\n";
                    return;
                } else {
                    for(int j = 0; i+j<n&&j<7;++j)
                        s[i+j]=temp[j];
                }
                
            }
        }
    }

    cout << "NO\n";
}

int main() {
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