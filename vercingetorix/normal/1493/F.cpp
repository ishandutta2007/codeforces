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

const long long mod = 1000000007;
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


int llog2(int k) {
    int d2 = 1;
    int ret = 0;
    while(d2*2 <= k) {
        d2*=2;
        ret++;
    }
    return ret;
}
int qnum = 0;
int ask(int w, int h,int i1,int j1, int i2, int j2) {
//    qnum++;
//    return 1;
    printf("? %d %d %d %d %d %d\n", w,h,i1+1,j1+1,i2+1,j2+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}
const int N = 10000;
//int mindiv[N+1];
vi mindiv(N+1, 0);
vector<ll> pr;
vi isp(N+1, 0);

void solve(int n, int m) {
    qnum = 0;
    int l;
    int pn = n;
    int pm = m;
    
    l = n;
    while(l > 1) {
        int p = mindiv[l];
        while(l%p == 0) {
            l/=p;
            int cand = pn/p;
            int ret = (p==2)? ask(p/2*cand, m, 0, 0, p/2*cand, 0) : (ask(p/2*cand, m, 0, 0, p/2*cand, 0) & ask(p/2*cand, m, 0, 0, (1+p/2)*cand, 0));
            if(ret) pn=cand;
        }
    }
    l = m;
    while(l > 1) {
        int p = mindiv[l];
        while(l%p == 0) {
            l/=p;
            int cand = pm/p;
            int ret = (p==2)? ask(n, p/2*cand, 0, 0, 0, p/2*cand) : (ask(n, p/2*cand, 0, 0, 0, p/2*cand) & ask(n, p/2*cand, 0, 0, 0, (1+p/2)*cand));
            if(ret) pm=cand;
        }
    }
//    if(qnum > 3* llog2(m+n)) {
//        cout<<m<<' '<<n<<'\n';
//    }
    int cn = 0, cm = 0;
    forn(i,1,1001) if(i%pm == 0 && m%i==0) cm++;
    forn(i,1,1001) if(i%pn == 0 && n%i==0) cn++;
    printf("! %d\n", cn*cm);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    auto count = [&](int x) {
        int ret = 0;
        int m = x;
        while(m>1) {
            int p = mindiv[m];
            int dp = 1;
            while(m%p==0) {
                dp*=p;
                m/=p;
                ret += 1 + p%2;
            }
        }
        return ret;
    };
//    vi cnt(1,0);
//    forn(i,1,1001) cnt.pb(count(i));
//    forn(n,1,1001) forn(m,1,1001) {
//        solve(n,m);
//        if(cnt[n] + cnt[m] > 3*llog2(m+n)) {
//            cout<<n<<' '<<m<<' '<<"need "<<cnt[n]+cnt[m]<<" have "<< 3*llog2(m+n)<<'\n';
//        }
//    }
    
    int n, m;
    scanf("%d %d", &n, &m);
    solve(n,m);
    
}