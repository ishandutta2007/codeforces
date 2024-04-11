//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,tune=native")
#include<bits/stdc++.h>

using namespace std;

#define all(x) (x).begin(),(x).end()
#define I(x, a) for(auto x : (a))
#define ins insert
#define F(i, l, r) for(auto i = (l); i < (r); i++)
#define DF(i, l, r) for(auto i = (l); i >= (r); i--)
#define E(i, l, r) for(auto i = (l); i <= (r); i++)
#define pb push_back
#define X first
#define Y second
#define mp make_pair
#define ret return
#define brk break
#define cont continue
#define sz(a) ((int)a.size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double dbl;
typedef pair<int, int> pii;

const int N = (int)2e5 + 5;
const int mod = 998244353;

inline int mul(int x, int y){
    return x * 1ll * y % mod;
}

inline int add(int x, int y){
    x += y;
    return x >= mod ? x - mod : x;
}

inline int modpow(ll x, int p){
    ll res = 1;
    while(p){
        if(p&1)
            res = res * x % mod;
        x = x * x % mod;
        p >>= 1;
    }
    return res;
}

int p[N];
int rem[N];
int nrem = 0;
int ninv;
int le[N];
int n;

pair<int, vector<int> > rec(int l, int r){
    if(l == r)
        return make_pair(0, p[l] == -1 ? vector<int>() : vector<int>(1, p[l]));
    int mid = (l + r)/2;
    int ansl, ansr;
    vector<int> L, R;
    tie(ansl, L) = rec(l, mid);
    tie(ansr, R) = rec(mid + 1, r);
    int ans = add(ansl, ansr);
    size_t ptr = 0;
    ll inv = 0;
    for(size_t i = 0; i < L.size(); i++){
        while(ptr < R.size() && L[i] > R[ptr])
            ++ptr;
        inv += ptr;
    }
    ans = add(ans, inv%mod);
    int unk_l = (mid - l + 1) - (int)L.size();
    int unk_r = (r - mid) - (int)R.size();
    for(auto x: L){
        int prob = mul(le[x], ninv);
        ans = add(ans, mul(prob, unk_r));
    }
    for(auto x: R){
        int prob = mul(nrem - le[x], ninv);
        ans = add(ans, mul(prob, unk_l));
    }
    vector<int> known(L.size() + R.size());
    merge(all(L), all(R), known.begin());
    return make_pair(ans, known);
}

void solve(){
    scanf("%d", &n);
    set<int> kek;
    for(int i = 1; i <= n; i++)
        kek.insert(i);
    for(int i = 0; i < n; i++){
        scanf("%d", p + i);
        if(p[i] != -1)
            kek.erase(p[i]);
    }
    for(auto x: kek)
        rem[nrem++] = x;
    for(int i = 1; i <= n; i++){
        le[i] = nrem ? lower_bound(rem, rem + nrem, i) - rem : 0;
    }
    ninv = modpow(nrem, mod - 2);
    int ans;
    tie(ans, ignore) = rec(0, n - 1);
    int extra = mul(nrem * 1ll * (nrem - 1) % mod, modpow(4, mod - 2));
    printf("%d\n", add(ans, extra));
}

signed main(){
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.precision(11);
    int T = 1;
    while(T--)
        solve();
    return 0;
}