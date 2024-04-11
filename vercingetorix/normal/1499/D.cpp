#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 20000000;

    vi mindiv(N+1, 0);
    vector<ll> pr;
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
    vi nump(N+1, 0);
    nump[1] = 1;
    forn(i,2,N+1) {
        int m = i;
        int p = mindiv[m];
        m/=p;
        if(m%p == 0) nump[i] = nump[m];
        else nump[i] = nump[m]*2;
    }
    int t;
    scanf("%d\n", &t);
    forn(ifa,0,t) {
        int p,q,x;
        scanf("%d %d %d", &p, &q, &x);
        ll ans = 0;
        for(int l = 1; l*l <= x; l++) {
            if(x%l == 0) {
                int ab = x/l + q;
                if(ab%p==0) {
                    ab/=p;
                    ans += nump[ab];
                }
                if(l*l!= x) {
                    ab = l + q;
                    if(ab%p==0) {
                        ab/=p;
                        ans += nump[ab];
                    }
                }
            }
        }
        printf("%lld\n" ,ans);
        
    }
    
    
}