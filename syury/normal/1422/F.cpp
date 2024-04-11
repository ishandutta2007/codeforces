
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

const int A = (int)2e5 + 5;
const int N = (int)1e5 + 5;
const int mod = (int)1e9 + 7;

vector<int> primes, small_primes;
int n;
int lp[A];
int a[N], big[N];
int pid[A];
int nxt[N];
vector<pii> t[4*N];
vector<int> suff[4*N];
vector<vector<array<int, N> > > pref;
vector<vector<int> > pwr;

void sieve(){
    for(int i = 2; i < A; i++){
        if(!lp[i]){
            pid[i] = primes.size();
            lp[i] = i;
            primes.push_back(i);
            if(i*1ll*i < A)
                small_primes.push_back(i);
        }
        for(size_t j = 0; j < primes.size() && primes[j] <= lp[i] && i * 1ll * primes[j] < A; j++){
            lp[i * primes[j]] = primes[j];
        }
    }
}

void build(int v, int l, int r){
    if(l == r){
        if(big[l] != 1){
            t[v] = vector<pii>(1, make_pair(nxt[l], big[l]));
            suff[v] = vector<int>(1, big[l]);
        }
        return;
    }
    int mid = (l + r)/2;
    build(2*v, l, mid);
    build(2*v + 1, mid + 1, r);
    t[v].resize(t[2*v].size() + t[2*v+1].size());
    merge(all(t[2*v]), all(t[2*v+1]), t[v].begin());
    suff[v].resize(t[v].size());
    for(int j = (int)suff[v].size() - 1; j >= 0; j--){
        suff[v][j] = t[v][j].second;
        if(j + 1 < (int)suff[v].size())
            suff[v][j] = suff[v][j + 1] * 1ll * suff[v][j] % mod;
    }
}

int get(int v, int l, int r, int ul, int ur, int x){
    if(ul > ur)
        return 1;
    if(l == ul && r == ur){
        size_t pos = lower_bound(all(t[v]), make_pair(x, -228)) - t[v].begin();
        return pos == t[v].size() ? 1 : suff[v][pos];
    }
    int mid = (l + r)/2;
    return get(2*v, l, mid, ul, min(ur, mid), x) * 1ll * get(2*v + 1, mid + 1, r, max(ul, mid + 1), ur, x) % mod;
}

void solve(){
    sieve();
    pref.resize(small_primes.size());
    for(size_t i = 0; i < small_primes.size(); i++){
        int maxpow = 0;
        int avtor_zadachi_pidor = 1;
        while(avtor_zadachi_pidor < A){
            avtor_zadachi_pidor *= small_primes[i];
            ++maxpow;
        }
        pref[i].resize(maxpow + 1);
    }
    pwr.resize(small_primes.size());
    for(size_t j = 0; j < small_primes.size(); j++){
        pwr[j] = {1};
        int p = small_primes[j];
        while(pwr[j].size() < (size_t)100){
            pwr[j].push_back(pwr[j].back() * 1ll * p % mod);
        }
    }
#ifdef TEST
    n = (int)1e5;
    for(int i = 0; i < n; i++)
        a[i] = rand()%(int)2e5 + 1;
#else
    scanf("%d", &n);
    for(int i = 0; i < n; i++)
        scanf("%d", a + i);
#endif
    map<int, int> lap;
    for(int i = 0; i < n; i++){
        for(size_t j = 0; j < small_primes.size(); j++){
            for(size_t k = 0; k < pref[j].size(); k++){
                pref[j][k][i] = i ? pref[j][k][i - 1] : 0;
            }
        }
        big[i] = 1;
        int kek = a[i];
        while(kek > 1){
            int p = lp[kek];
            int cu = 0;
            while(lp[kek] == p){
                kek /= p;
                ++cu;
            }
            if(p * 1ll * p < A){
                auto j = pid[p];
                for(size_t k = 0; k <= cu; k++)
                    ++pref[j][k][i];
            }
            else
                big[i] = p;
        }
    }
    for(int i = n - 1; i >= 0; i--){
        if(big[i] != 1){
            nxt[i] = lap.count(big[i]) ? lap[big[i]] : n;
            lap[big[i]] = i;
        }
    }
    build(1, 0, n - 1);
    int q;
#ifdef TEST
    q = (int)1e5;
#else
    scanf("%d", &q);
#endif
    int la = 0;
    for(int qu = 0; qu < q; qu++){
        int l, r;
#ifdef TEST
        l = rand()%n + 1;
        r = rand()%n + 1;
#else
        scanf("%d%d", &l, &r);
        l = (l + la)%n + 1;
        r = (r + la)%n + 1;
#endif
        if(l > r)swap(l, r);
        --l; --r;
        la = 1;
        for(size_t j = 0; j < small_primes.size(); j++){
            int L = 0, R = (int)pref[j].size() - 1;
            while(R - L > 1){
                int mid = (L + R)/2;
                if(pref[j][mid][r] == (l ? pref[j][mid][l - 1] : 0))
                    R = mid;
                else
                    L = mid;
            }
            if(L)
                la = la * 1ll * pwr[j][L] % mod;
        }
        la = la * 1ll * get(1, 0, n - 1, l, r, r + 1) % mod;
        printf("%d\n", la);
    }
}

signed main(){
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    solve();
    return 0;
}