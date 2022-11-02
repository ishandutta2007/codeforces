#define _USE_MATH_DEFINES
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

ll modAdd(ll x, ll y, ll m) {
    x += y;
    return (x < m ? x : x-m);
}

ll modSub(ll x, ll y, ll m) {
    x -= y;
    return (x >= 0 ? x : x+m);
}

ll modMul(ll a, ll b, ll m) {
    ll c = ll((long double)a * b / m);
    ll r = (a*b - c*m) % m;
    return r < 0 ? r+m : r;
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

ll gcd(ll a, ll b) {
    if (a < b) swap(a, b);
    while (b) {
        ll x = a % b;
        a = b;
        b = x;
    }
    return a;
}

// ---

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

// ---

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

// ---

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

vector<Factor> factors;
Vi B, C;

int getMask(ll n) {
    int mask = 0;
    rep(i, 0, sz(factors)) {
        if (n%factors[i].x == 0) {
            mask |= 1 << i;
        }
    }
    return mask;
}

Vi getCounts(int begin, int end, int bit) {
    Vi ret;
    if (bit < 0) {
        ret.pb(end-begin);
        return ret;
    }

    int mid = begin;
    while (mid < end && ((C[mid] >> bit) & 1) == 0) mid++;

    Vi zero = getCounts(begin, mid, bit-1);
    ret = getCounts(mid, end, bit-1);
    assert(sz(zero) == sz(ret));

    rep(i, 0, sz(zero)) {
        ret[i] += zero[i];
        ret.pb(zero[i]);
    }
    return ret;
}

void run() {
    ll n, X, Y;
    cin >> n >> X >> Y;

    if (Y % X) {
        cout << 0 << endl;
        return;
    }

    sieve();
    factors = factorize(Y / X);

    rep(i, 0, n) {
        ll a; cin >> a;
        if (a%X == 0) B.pb(getMask(a/X));
        if (Y%a == 0) C.pb(getMask(Y/a));
    }

    sort(all(C));
    Vi counts = getCounts(0, sz(C), sz(factors)-1);
    ll ans = 0;

    each(b, B) ans += counts[b];
    cout << ans << endl;
}