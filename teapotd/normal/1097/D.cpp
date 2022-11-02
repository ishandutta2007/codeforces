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

constexpr int MAX_P = 1e6;
bitset<MAX_P+1> primes;
Vi primesList;

void sieve() {
    primes.set();
    primes.reset(0);
    primes.reset(1);

    for (int i = 2; i*i <= MAX_P; i++)
        if (primes[i])
            for (int j = i*i; j <= MAX_P; j += i)
                primes.reset(j);

    rep(i, 0, MAX_P+1) if (primes[i])
        primesList.pb(i);
}

ll modAdd(ll x, ll y, ll m) {
    x += y;
    return (x < m ? x : x-m);
}

ll modSub(ll x, ll y, ll m) {
    x -= y;
    return (x >= 0 ? x : x+m);
}

ll modMul(ll x, ll y, ll m) {
    ll t = 0;
    while (y) {
        if (y & 1) t = modAdd(t, x, m);
        y >>= 1;
        x = modAdd(x, x, m);
    }
    return t;
}

ll modPow(ll x, ll e, ll m) {
    ll t = 1;
    while (e) {
        if (e & 1) t = modMul(t, x, m);
        e >>= 1;
        x = modMul(x, x, m);
    }
    return t;
}

constexpr ll BASES[] = {
    2,325,9375,28178,450775,9780504,1795265022
};

bool isPrime(ll p) {
    if (p == 2) return true;
    if (p <= 1 || p%2 == 0) return false;

    ll d = p-1, times = 0;
    while (d%2 == 0) d /= 2, times++;

    each(a, BASES) if (a%p) {
        ll b = modPow(a%p, d, p);
        if (b == 1 || b == p-1) continue;

        rep(i, 1, times) {
            b = modMul(b, b, p);
            if (b == p-1) break;
        }

        if (b != p-1) return false;
    }

    return true;
}

using Factor = pair<ll, int>;

vector<Factor> factorize(ll n) {
    vector<Factor> ret;
    each(p, primesList) if (n%p == 0) {
        ret.pb({ p, 0 });
        while (n%p == 0) {
            n /= p;
            ret.back().y++;
        }
    }

    if (n <= 1) return ret;
    if (isPrime(n)) {
        ret.pb({ n, 1 });
        return ret;
    }

    for (ll a = 1;; a++) {
        ll x = 2, y = 2, d = 1;

        while (d == 1) {
            x = modAdd(modMul(x, x, n), a, n);
            y = modAdd(modMul(y, y, n), a, n);
            y = modAdd(modMul(y, y, n), a, n);
            d = __gcd(abs(x-y), n);
        }

        if (d != n) {
            n /= d;
            if (d > n) swap(d, n);
            ret.pb({ d, 1 });
            if (d == n) ret.back().y++;
            else ret.pb({ n, 1 });
            return ret;
        }
    }
}

// ---

constexpr ll MOD = 1e9+7;

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

    #define OP(c) Zp& operator c##=(Zp r){ \
        return *this=*this c r; }
    OP(+)OP(-)OP(*)OP(/)
    void print() { cerr << x; }
};

vector<Zp> getProbs(int n, int k) {
    vector<Zp> cur(n+1), prev(n+1);
    cur.back() = 1;

    rep(i, 0, k) {
        prev.swap(cur);
        cur.assign(n+1, 0);

        Zp add = 0;

        for (int j = n; j >= 0; j--) {
            add += prev[j] / (j+1);
            cur[j] = add;
        }
    }
    return cur;
}

vector<vector<Zp>> probs;
vector<Factor> factors;
Zp ans = 0;

void solve(ll mult, Zp prob, int f) {
    if (f >= sz(factors)) {
        ans += prob*mult;
        return;
    }

    rep(i, 0, factors[f].y+1) {
        solve(mult, prob*probs[f][i], f+1);
        mult *= factors[f].x;
    }
}

void run() {
    ll n;
    int k;
    cin >> n >> k;

    sieve();
    factors = factorize(n);

    each(f, factors) probs.pb(getProbs(f.y, k));

    solve(1, 1, 0);
    cout << ans.x << endl;
}