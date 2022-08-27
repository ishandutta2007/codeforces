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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 100500;
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
    vi sq(N);
    sq[1] = 1;
    forn(i,2,N) {
        if(i/mindiv[i] % mindiv[i] == 0) sq[i] = sq[i/mindiv[i]];
        else sq[i] = sq[i/mindiv[i]] * mindiv[i];
    }
    int n,m;
    scanf("%d %d\n", &n, &m);
    vvi a(N);
    vi on(N,0);
    forn(i,0,m) {
        char c;
        int k;
        scanf("%c %d\n", &c, &k);
        if(c == '-') {
            if(on[k] == 0) printf("Already off\n");
            else {
                on[k] = 0;
                printf("Success\n");
            }
        }
        else {
            if(on[k] == 1) printf("Already on\n");
            else {
                int m = sq[k];
                int bad = 0;
                while(m!=1) {
                    int p = mindiv[m];
                    m/=p;
                    while(!a[p].empty() && on[a[p].back()] == 0) a[p].pop_back();
                    if(!a[p].empty()) {
                        printf("Conflict with %d\n", a[p].back());
                        bad = 1;
                        break;
                    }
                }
                if(bad == 0) {
                    printf("Success\n");
                    on[k] = 1;
                    m = sq[k];
                    while(m!=1) {
                        int p = mindiv[m];
                        m/=p;
                        a[p].pb(k);
                    }
                }
            }
        }
    }
    
    
    
}