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
vector<int> pr;
ll sum = 0;
int ans = 0;
int divs[40];
int dnum;
int num;
int bad = 0;
int good[101];

int fdivs[2000];
int getdiv(int r) {
    if(r == dnum) {
        return 1;
    }
    int nr = r+1;
    while(nr < dnum && divs[nr] == divs[r]) nr++;
    int deg = nr-r;
    int k = getdiv(nr);
    int p = divs[r];
    int dp = p;
    int cur = k;
    forn(it,0,deg) {
        forn(i,0,k) fdivs[cur++] = fdivs[i]*dp;
        dp*=p;
    }
    return cur;
}

int dist[2000];
int taken[40];

const int A = 10000000;
int fm[A];
unordered_map<int, int> bm;

class fastmap {
public:
    void set(int i, int val) {
        if(i<A) fm[i] = val;
        else bm[i] = val;
    }
    int get(int i) {
        if(i<A) return fm[i];
        else return bm[i];
    }
};

int check(int n) {
    int m = n;
    dnum = 0;
    for(auto x : pr) while(n%x == 0) {
        n/=x;
        divs[dnum++] = x;
    }
    if(divs[0]+dnum <= num) return 1;
    int fr = num - divs[0];
//    if(fr>=8) return 1;
    int wf = fr;
    ll mx = 1;
    forn(i,0,fr) mx *= divs[0];
    forn(add,1,10) {
        if(fr > add) {
            ll cand = 1;
            forn(i,0,fr-add) cand*=divs[0]+add;
            mx = max(cand,mx);
        }
    }
    if(mx < m) return 0;
    forn(add,0,3) {
        forn(i,0,dnum) taken[i] = 0;
        int need = 0;
        forn(i,0,dnum) {
            if(taken[i] == 0) {
                need++;
                int cur = divs[i];
                taken[i] = 1;
                forn(j,i+1,dnum) {
                    if(taken[j] == 0 && cur * divs[j] <= divs[0]+add) {
                        taken[j] = 1;
                        cur *= divs[j];
                    }
                }
            }
        }
        if(need<=fr-add) return 1;
    }
    
    
    int l = getdiv(0);
    sort(fdivs, fdivs+l);
//    unordered_map<int, int> to;
    fastmap to;
    bm.clear();
//    forn(i,0,l) to[fdivs[i]] = i;
    forn(i,0,l) to.set(fdivs[i], i);
    forn(i,0,l) dist[i] = fr+1;
    dist[0] = 0;
    int ptr = 1;
    int lim = divs[0];
    while(1) {
        while(ptr < l && fdivs[ptr] <= lim) ptr++;
        int ptb = 0;
        while(ptb < l && fdivs[ptb]*fdivs[ptb] > lim) ptb++;
        if(ptb <= fr) {
            forn(i,0,l-1) {
                int lef = m / fdivs[i];
                forn(j,1,ptr) if(lef%fdivs[j] == 0) {
                    int k = to.get(fdivs[i]*fdivs[j]);
                    dist[k] = min(dist[k], dist[i]+1);
                }
            }
            if(dist[l-1] <= fr) return 1;
        }
        fr--;
        lim++;
        if(fr==0) break;
        mx = 1;
        forn(i,0,fr) mx *= lim;
        if(divs[0] > 5 && mx < m) return 0;
    }
    return 0;
}
int l,r;
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    cin>>l>>r>>num;
    fdivs[0] = 1;
    const int N = 100;
    //int mindiv[N+1];
    vi mindiv(N+1, 0);
    
    vi isp(N+1, 0);
    
    for (int i=2; i<=N; ++i) {
        if (mindiv[i] == 0) {
            mindiv[i] = i;
            pr.push_back (i);
            isp[i] = 1;
        }
        for (int j=0; j<(int)pr.size() && pr[j]<=mindiv[i] && i*pr[j]<=N; ++j)
            mindiv[i * pr[j]] = pr[j];
    }
    
    
    vi can(1,1);
    while(!pr.empty() && pr.back() >= num) pr.pop_back();
    reverse(all(pr));
    for(auto p : pr) if(p<=num-1) {
        int k = can.size();
        forn(i,0,k) {
            int cur = can[i];
            while((r+1)/p >= cur && cur*p<=r) {
                cur*=p;
                can.pb(cur);
            }
        }
    }
    for(auto x : can) if(x>=l && x<=r) ans += check(x);
    cout<<ans;
//    cout<<bad;
//    cout<<sum;
//    cout<<can.size();
    
    
}