#define _USE_MATH_DEFINES////////////////////////////////////////
#include<bits/stdc++.h>//////////////////////////////////////////
#define deb(...)/////////////////////////////////////////////////
#define DBP(...)/////////////////////////////////////////////////
#ifdef LOC///////////////////////////////////////////////////////
#include"debuglib.h"/////////////////////////////////////////////
#endif///////////////////////////////////////////////////////////
#define x first//////////////////////////////////////////////////
#define y second/////////////////////////////////////////////////
#define pb push_back/////////////////////////////////////////////
#define mp make_pair/////////////////////////////////////////////
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

ll modPow(ll a, ll e, ll m) {
    ll t = 1 % m;
    while (e) {
        if (e % 2) t = t*a % m;
        e /= 2; a = a*a % m;
    }
    return t;
}

template<ll M, ll R, bool dit>
void ntt(vector<ll>& a) {
    static vector<ll> w(2, 1);
    int n = sz(a);

    for (int k = sz(w); k < n; k *= 2) {
        w.resize(n, 1);
        ll c = modPow(R, M/2/k, M);
        if (dit) c = modPow(c, M-2, M);
        rep(i, k+1, k*2) w[i] = w[i-1]*c % M;
    }

    for (int t=1, s=n/2; t < n; t *= 2, s /= 2) {
        int k = (dit ? t : s);
        for (int i=0; i < n; i += k*2) rep(j,0,k) {
            ll &c = a[i+j], &d = a[i+j+k];
            ll e = w[j+k], f = d;
            d = (dit ? c - (f=f*e%M) : (c-f)*e % M);
            if (d < 0) d += M;
            if ((c += f) >= M) c -= M;
        }
    }
}

template<ll M = (119<<23)+1, ll R = 62>
void convolve(vector<ll>& a, vector<ll> b) {
    int len = sz(a) + sz(b) - 1;
    int n = 1 << (32 - __builtin_clz(len));
    ll t = modPow(n, M-2, M);
    a.resize(n); b.resize(n);
    ntt<M,R,0>(a); ntt<M,R,0>(b);
    rep(i, 0, n) a[i] = a[i]*b[i] % M * t % M;
    ntt<M,R,1>(a);
    a.resize(len);
}

constexpr int MAX_V = 3e6+5;

int cnt[MAX_V], wanted;
vector<vector<ll>> polys;

void solve(int begin, int end) {
    if (end-begin <= 1) return;
    int mid = (begin+end) / 2;
    solve(begin, mid);
    solve(mid, end);
    convolve(polys[begin], polys[mid]);

    if (sz(polys[begin]) >= wanted+1) {
        polys[begin].resize(wanted+1);
    }
}

void run() {
    int n; cin >> n;

    rep(i, 0, n) {
        int k; cin >> k;
        cnt[k]++;
    }

    rep(i, 0, MAX_V) {
        if (cnt[i]) {
            polys.emplace_back(cnt[i]+1, 1);
        }
    }

    wanted = n/2;
    solve(0, sz(polys));
    cout << polys[0][wanted] << endl;
}