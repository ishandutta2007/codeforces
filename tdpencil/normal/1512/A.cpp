#include "bits/stdc++.h"
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

using namespace std;
template<class T>
using indexed_set =  tree<T,null_type,less<T>,rb_tree_tag,tree_order_statistics_node_update>;
typedef long long ll;
#define all(x) x.begin(), x.end()
#define trav(i, x) for(auto &i : x)
#define lb lower_bound
#define ub upper_bound
#define pb push_back
#define eb emplace_back
#define FOR(i, N) for(int i = 0; i < (N); i++)
const ll mod = 1e9 + 7;

template<int _S>
struct modint {
    using ll = long long;
    ll v;
    static constexpr int MOD = _S;
    static_assert(MOD > 0, "MOD HAS TO BE G than 0");
    modint() : v(0) {}
    modint(ll V) : v(V) {}
    
    ll gcd(ll x, ll y) {
        return y ? gcd(y, x % y) : x;
    }
    ll minv() {
        int m = MOD;
        ll x = v;
        if(gcd(MOD, v) == 1) {
            return x=((x%m+m)%m);
        } else return v;
    }
    explicit operator int() const {return v;}
    friend ostream& operator << (ostream& os, const modint&m) {
        return os << int(m);
    }
    friend istream& operator >> (istream &os, const modint&m) {
        ll V; os >> V; 
        m = modint(V);
        return os;
    }
    friend bool operator != (const modint<MOD>&a, const modint &b) {return a.v != b.v;}
    friend bool operator == (const modint<MOD> &a, const modint<MOD>&b) {return a.v == b.v;};
    modint &operator =(ll a) {
        v=a;
        return *this;
    }
    modint &operator -=(const modint<MOD>&a) {
        v -= a.v;
        if(v < 0) v += MOD;
        return *this;
    }
    modint &operator +=(const modint<MOD>&a) {
        v += a.v;
        v %= MOD;
        return *this;
    }
    modint &operator *=(const modint<MOD>&a) {
        v = ((v%MOD)*(a.v%MOD)) % MOD;
        return *this;
    }
    modint &operator /=(const modint<MOD> &a) {
        v = ((v%MOD)*(a.minv()%MOD))%MOD;
    }
    template<class T>
    modint &operator -=(T a) {
        v -= a;
        if(v < 0) v += MOD;
        return *this;
    }
    template<class T>
    modint &operator +=(T a) {
        v += a;
        v %= MOD;
        return *this;
    }
    template<class T>
    modint &operator *=(T a) {
        v = ((v%MOD)*(a%MOD)) % MOD;
        return *this;
    }
    template<class T>
    modint &operator /=(T a) {
        v = ((v%MOD)/(a%MOD))%MOD;
    }
    friend modint operator+(const modint<MOD> &a, ll b) {
        modint<MOD> res;
        res.v=a.v;
        res += b;
        return res;
    }
    friend modint operator-(const modint<MOD> &a, ll b) {
        modint<MOD> res;
        res.v=a.v;
        res-=b;
        return res;
    }
    friend modint operator*(const modint<MOD> &a, ll b) {
        modint<MOD> res;
        res.v=a.v;
        res*=b;
        return res;
    }
    friend modint operator+(const modint<MOD> &a, const modint<MOD> &b) {
        modint<MOD> res;
        res.v=a.v;
        res+=b;
        return res;
    }
    friend modint operator-(const modint<MOD> &a, const modint<MOD> &b) {
        modint<MOD> res;
        res.v=a.v;
        res-=b;
        return res;
    }
    friend modint operator*(const modint<MOD> &a, const modint<MOD> &b) {
        modint<MOD> res;
        res.v=a.v;
        res*=b;
        return res;
    }
    
    
};

using num = modint<int(1e9+7)>;
void solve() 
{
	int n; scanf("%d", &n);
	vector<int> a(n);
	trav(i, a) {
		scanf("%d", &i);
	}
	
	for(int i = 0; i < n; i++) {
		if(count(a.begin(), a.end(), a[i]) == 1) {
			printf("%d\n", i+1);
			return;
		}
	}
}
int main() {

    int t = 1, i = 1;
    scanf("%d", &t);
    while(t--) {
        // printf("Case #%d: ", i)
        solve();
        i++;
    }
}