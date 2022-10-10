// iostream is too mainstream
#include <cstdio>
// bitch please
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <list>
#include <chrono>
#include <random>
#include <iomanip>
#define dibs reserve
#define OVER9000 1234567890123456789LL
#define tisic 47
#define soclose 1e-8
#define patkan 9
#define ff first
#define ss second
using uint = unsigned int;
using cat = long long;
using dbl = long double;
constexpr dbl pi = 3.14159265358979323846;
using namespace std;

#ifdef DONLINE_JUDGE
	// palindromic tree is better than splay tree!
	#define lld I64d
#endif

template <typename T>
T abs(T x) { return (x < 0) ? (-x) : x; }

cat pw(cat a, cat e, cat mod) {
	if(e <= 0) return 1;
	cat x = pw(a, e/2, mod);
	x = x * x % mod;
	return (e&1) ? x * a % mod : x;
}

template <typename T>
class fin {
	vector<T> node_val;

	int lastone(int x) { return x & (x ^ (x-1)); }

public:
	fin(int N, T init_val) {
		node_val.resize(N+10, init_val);
	}

	void put(int pos, T val) {
		for(int i = pos+1; i < (int)node_val.size(); i += lastone(i))
			node_val[i] += val;
	}

	T get(int pos) {
		T ret = 0;
		for(int i = pos+1; i > 0; i -= lastone(i))
			ret += node_val[i];
		return ret;
	}
};

// base and base_digits must be consistent
const int base = 1000000000;
const int base_digits = 9;

struct vec {
	static constexpr int MX_SZ = 16;
	int a[MX_SZ];
	int sz;

	vec() : sz{0} {}

	int size() const { return sz; }
	bool empty() const { return (sz == 0); }
	void push_back(int val) { a[sz++] = val; }
	void pop_back() { sz--; }
	int & back() { return a[sz-1]; }
	int & operator[](int pos) { return a[pos]; }
	int back() const { return a[sz-1]; }
	int operator[](int pos) const { return a[pos]; }
	void clear() { sz = 0; }
	void resize(int sz_) {
		sz = sz_;
		for(int i = 0; i < sz; i++) a[i] = 0;
	}
};

struct bigint {
    vec a;
 
    bigint() = default;
 
    bigint(long long v) {
        *this = v;
    }
 
    bigint(const string &s) {
        read(s);
    }

    bigint(const bigint &v) {
        a = v.a;
    }
 
    void operator=(const bigint &v) {
        a = v.a;
    }
 
    void operator=(long long v) {
        for (; v > 0; v = v / base) {
            a.push_back(v % base);
        }
    }
 
    bigint operator+(const bigint &v) const {
        bigint res = v;

        for (int i = 0, carry = 0; i < (int) max(a.size(), v.a.size()) || carry; ++i) {
            if (i == (int) res.a.size()) res.a.push_back(0);
            res.a[i] += carry + (i < (int) a.size() ? a[i] : 0);
            carry = res.a[i] >= base;
            if (carry)
                res.a[i] -= base;
        }
        return res;
    }
 
    bigint operator-(const bigint &v) const {
        bigint res = *this;
        for (int i = 0, carry = 0; i < (int) v.a.size() || carry; ++i) {
            res.a[i] -= carry + (i < (int) v.a.size() ? v.a[i] : 0);
            carry = res.a[i] < 0;
            if (carry)
                res.a[i] += base;
        }
        res.trim();
        return res;
    }
 
    void operator*=(int v) {
        for (int i = 0, carry = 0; i < (int) a.size() || carry; ++i) {
            if (i == (int) a.size()) {
                a.push_back(0);
            }
            long long cur = a[i] * (long long) v + carry;
            carry = (int) (cur / base);
            a[i] = (int) (cur % base);
            //asm("divl %%ecx" : "=a"(carry), "=d"(a[i]) : "A"(cur), "c"(base));
        }
        trim();
    }
 
    bigint operator*(int v) const {
        bigint res = *this;
        res *= v;
        return res;
    }
 
    friend pair<bigint, bigint> divmod(const bigint &a1, const bigint &b1) {
        int norm = base / (b1.a.back() + 1);
        bigint a = a1 * norm;
        bigint b = b1 * norm;
        bigint q, r;
        q.a.resize(a.a.size());
 
        for (int i = a.a.size() - 1; i >= 0; i--) {
            r *= base;
            r += a.a[i];
            int s1 = r.a.size() <= b.a.size() ? 0 : r.a[b.a.size()];
            int s2 = r.a.size() <= b.a.size() - 1 ? 0 : r.a[b.a.size() - 1];
            int d = ((long long) base * s1 + s2) / b.a.back();
            auto c = b * d;
            while(c > r) d--, c -= b;
            r -= c;
            q.a[i] = d;
        }
 
        q.trim();
        r.trim();
        return make_pair(q, r / norm);
    }
 
    bigint operator/(const bigint &v) const {
        return divmod(*this, v).first;
    }
 
    bigint operator%(const bigint &v) const {
        return divmod(*this, v).second;
    }
 
    void operator/=(int v) {
        for (int i = (int) a.size() - 1, rem = 0; i >= 0; --i) {
            long long cur = a[i] + rem * (long long) base;
            a[i] = (int) (cur / v);
            rem = (int) (cur % v);
        }
        trim();
    }
 
    bigint operator/(int v) const {
        bigint res = *this;
        res /= v;
        return res;
    }
 
    int operator%(int v) const {
        int m = 0;
        for (int i = a.size() - 1; i >= 0; --i)
            m = (a[i] + m * (long long) base) % v;
        return m;
    }
 
    void operator+=(const bigint &v) {
        *this = *this + v;
    }
    void operator-=(const bigint &v) {
        *this = *this - v;
    }
 
    bool operator<(const bigint &v) const {
        if (a.size() != v.a.size())
            return a.size() < v.a.size();
        for (int i = a.size() - 1; i >= 0; i--)
            if (a[i] != v.a[i])
                return a[i] < v.a[i];
        return false;
    }
 
    bool operator>(const bigint &v) const {
        return v < *this;
    }
    bool operator<=(const bigint &v) const {
        return !(v < *this);
    }
    bool operator>=(const bigint &v) const {
        return !(*this < v);
    }
    bool operator==(const bigint &v) const {
        return !(*this < v) && !(v < *this);
    }
    bool operator!=(const bigint &v) const {
        return *this < v || v < *this;
    }
 
    void trim() {
        while (!a.empty() && !a.back())
            a.pop_back();
    }
 
    bool isZero() const {
        return a.empty() || (a.size() == 1 && !a[0]);
    }
 
    long long longValue() const {
        long long res = 0;
        for (int i = a.size() - 1; i >= 0; i--)
            res = res * base + a[i];
        return res;
    }
 
    friend bigint gcd(const bigint &a, const bigint &b) {
    	if(b.a.size() <= 2 && a.a.size() <= 2) {
    		cat la = a.longValue(), lb = b.longValue();
    		if(la > lb) swap(la, lb);
    		while(la) {
    			lb %= la;
    			swap(la, lb);
    		}
    		return lb;
    	}
        return b.isZero() ? a : gcd(b, a % b);
    }
 
    void read(const string &s) {
        a.clear();
        for (int i = s.size() - 1; i >= 0; i -= base_digits) {
            int x = 0;
            for (int j = max(0, i - base_digits + 1); j <= i; j++)
                x = x * 10 + s[j] - '0';
            a.push_back(x);
        }
        trim();
    }
 
    friend istream& operator>>(istream &stream, bigint &v) {
        string s;
        stream >> s;
        v.read(s);
        return stream;
    }
 
    friend ostream& operator<<(ostream &stream, const bigint &v) {
        stream << (v.a.empty() ? 0 : v.a.back());
        for (int i = (int) v.a.size() - 2; i >= 0; --i)
            stream << setw(base_digits) << setfill('0') << v.a[i];
        return stream;
    }
};

int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout << fixed << setprecision(12);
	int T;
	cin >> T;
	vector<int> pr;
	int MX_P = 12000;
	for(int i = 2; i <= MX_P; i++) {
		bool ok = true;
		for(auto p : pr) if(i%p == 0) {
			ok = false;
			break;
		}
		if(ok) pr.push_back(i);
	}
	while(T--) {
		int N, M;
		cin >> N >> M;
		N += M;
		vector<bigint> A(N);
		vector<string> A_init(N);
		for(int i = 0; i < N; i++) {
			string S;
			// for(int j = 0; j < 6; j++) S += ('1'+rand()%9);
			// for(int j = 0; j < 30; j++) S += ('0'+rand()%10);
			cin >> S;
			A[i] = bigint(S);
			A_init[i] = S;
		}
		map<bigint, vector< pair<int,int> > > P;
		for(auto p : pr) {
			vector< pair<int,int> > ids;
			for(int i = 0; i < N; i++) if(A[i]%p == 0) {
				int e = 0;
				while(A[i]%p == 0) A[i] /= p, e++;
				ids.emplace_back(i, e);
			}
			if(!ids.empty()) P[p] = ids;
		}
		vector< pair<bigint, int> > V;
		for(int i = 0; i < N; i++) if(A[i] != 1) V.emplace_back(A[i], i);
		while(!V.empty()) {
			auto pa = V.back();
			V.pop_back();
			bool split = false;
			for(int i = 0; i < (int)V.size(); i++) {
				while(pa.ff != V[i].ff) {
					auto pb = V[i];
					auto g = gcd(pa.ff, pb.ff);
					if(g == 1) break;
					if(g != pb.ff) V.emplace_back(pb.ff/g, pb.ss);
					V[i].ff = g;
					if(g != pa.ff) {
						V.emplace_back(pa.ff/g, pa.ss);
						V.emplace_back(g, pa.ss);
						split = true;
						break;
					}
				}
				if(split) break;
			}
			if(!split) {
				map<int,int> MM;
				MM[pa.ss]++;
				for(int i = 0; i < (int)V.size(); i++) if(V[i].ff == pa.ff) {
					MM[V[i].ss]++;
					swap(V[i], V.back());
					V.pop_back();
					i--;
				}
				for(auto p : MM) P[pa.ff].push_back(p);
			}
		}
		vector<char> live(N, 1);
		while(true) {
			bool fail = false;
			for(auto & [p, v] : P) {
				int ea = 0, eb = 0;
				for(int i = 0; i < (int)v.size(); i++) {
					if(!live[v[i].ff]) {
						swap(v[i], v.back());
						v.pop_back();
						i--;
						continue;
					}
					if(v[i].ff < N-M) ea = max(ea, v[i].ss);
					else eb = max(eb, v[i].ss);
				}
				if(ea == eb) continue;
				fail = true;
				int mx_e = max(ea, eb);
				for(int i = 0; i < (int)v.size(); i++)
					if(v[i].ss == mx_e) live[v[i].ff] = false;
				break;
			}
			if(!fail) break;
		}
		vector<string> ans_a, ans_b;
		for(int i = 0; i < N-M; i++) if(live[i]) ans_a.push_back(A_init[i]);
		for(int i = N-M; i < N; i++) if(live[i]) ans_b.push_back(A_init[i]);
		if(ans_a.empty() || ans_b.empty()) {
			cout << "NO\n";
			continue;
		}
		cout << "YES\n" << ans_a.size() << " " << ans_b.size() << "\n";
		for(int i = 0; i < (int)ans_a.size(); i++) cout << ans_a[i] << ((i+1 == (int)ans_a.size()) ? "\n" : " ");
		for(int i = 0; i < (int)ans_b.size(); i++) cout << ans_b[i] << ((i+1 == (int)ans_b.size()) ? "\n" : " ");
	}
}

// look at my code
// my code is amazing