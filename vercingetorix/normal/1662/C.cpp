#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
#include <random>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 998244353;
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
const int N = 100;
int n;
int g[N][N];
int deg[N];

vvll mul(const vvll & a, const vvll & b) {
    vvll ret(n, vll(n,0));
    forn(i,0,n) forn(j,0,n) forn(k,0,n) ret[i][j] = (ret[i][j] + a[i][k]*b[k][j])%mod;
    return ret;
}

void add(vvll & a, const vvll & b) {
    forn(i,0,n) forn(j,0,n) {
        a[i][j] += b[i][j];
        if(a[i][j]>=mod) a[i][j] -= mod;
    }
}

vll mul(const vvll & b, const vll & a) {
    vll ret(n,0);
    forn(i,0,n) forn(j,0,n) {
        ret[i] = (ret[i] + a[j]*b[i][j])%mod;
    }
    return ret;
}


vll mul(const vll & a) {
    vll ret(n,0);
    forn(i,0,n) forn(j,0,n) {
        ret[i] = (ret[i] + a[j]*g[i][j])%mod;
    }
    return ret;
}

vll sum(const vll & a, const vll & b) {
    vll ret;
    forn(i,0,n) ret.pb((a[i]+b[i])%mod);
    return ret;
}
vvll A[20];
vvll B[20];
vvll C[20];
vvll D[20];
void pr(const vvll & a) {
    forn(i,0,n) {
        forn(j,0,n) cout<<a[i][j] <<' ';
        cout<<'\n';
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int m,k;
    cin>>n>>m>>k;
    forn(i,0,m) {
        int u, v;
        cin>>u>>v;
        --u; --v;
        g[u][v] = 1;
        g[v][u] = 1;
        deg[u]++;
        deg[v]++;
    }
    if(k<=2) {
        cout<<0;
        exit(0);
    }
    A[0] = vvll(n,vll(n,0));
    forn(i,0,n) forn(j,0,n) A[0][i][j] = g[i][j];
    B[0] = vvll(n,vll(n,0));
    forn(i,0,n) B[0][i][i] = (mod - deg[i]+1)%mod;
    C[0] = vvll(n,vll(n,0));
    forn(i,0,n) C[0][i][i] = 1;
    D[0] = vvll(n,vll(n,0));
    forn(l,1,15) {
        A[l] = mul(A[l-1], A[l-1]);
        add(A[l], mul(B[l-1], C[l-1]));
        B[l] = mul(A[l-1], B[l-1]);
        add(B[l], mul(B[l-1], D[l-1]));

        C[l] = mul(C[l-1], A[l-1]);
        add(C[l], mul(D[l-1], C[l-1]));
        D[l] = mul(C[l-1], B[l-1]);
        add(D[l], mul(D[l-1], D[l-1]));
    }
    vvll AA = C[0];
    vvll BB = D[0];
    vvll CC = D[0];
    vvll DD = C[0];
    int left = k-2;
    for(int bit = 14; bit>=0; bit--) {
        if(left >= (1<<bit)) {
            left -= (1<<bit);
            auto NA = mul(AA, A[bit]);
            add(NA, mul(BB, C[bit]));
            auto NB = mul(AA, B[bit]);
            add(NB, mul(BB, D[bit]));
            
            auto NC = mul(CC, A[bit]);
            add(NC, mul(DD, C[bit]));
            auto ND = mul(CC, B[bit]);
            add(ND, mul(DD, D[bit]));
            swap(AA,NA);
            swap(BB,NB);
            swap(CC,NC);
            swap(DD,ND);
        }
    }
//    pr(AA);
//    pr(BB);
//    pr(CC);
//    pr(DD);
    ll res = 0;
    forn(s,0,n) {
        vvll ans;
        ans.pb(vll(n,0));
        ans.back()[s] = 1;
        forn(i,1,3) {
            ans.pb(mul(ans.back()));
            if(i > 1) forn(j,0,n) ans.back()[j] = (ans.back()[j] + mod - ans[i-2][j]*(deg[j]-1)%mod)%mod;
            if(i == 2) ans.back()[s] = (ans.back()[s] + mod - 1)%mod;
        }
//        forn(i,0,n) cout<<ans[1][i]<<' '; cout<<'\n';
//        forn(i,0,n) cout<<ans[2][i]<<' '; cout<<'\n';
        res+=sum(mul(AA, ans[2]), mul(BB, ans[1]))[s];
//        res+=ans.back()[s];
    }
//    forn(i,0,n) forn(j,0,n) forn(k,0,n) forn(p,0,n) if(g[i][j] && g[j][k]&&g[k][p] && g[p][i] && j!=p && i!=k) res--;
    cout<<res%mod;
    
}