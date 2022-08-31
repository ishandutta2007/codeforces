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

int to[20][100500];
int cnt[100500];
vi divs[100500];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int N = 200000;
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

    int n,q;
    scanf("%d %d", &n, &q);
    readv(a,n);
    forn(i,0,n) {
        int cur = a[i];
        while(cur > 1) {
            int p = mindiv[cur];
            divs[i].pb(p);
            cur/=p;
            while(cur % p == 0) cur/=p;
        }
    }
    int r = n;
    for(int l = n-1; l>=0; l--) {
        for(auto x : divs[l]) {
            cnt[x]++;
            while(cnt[x] > 1) {
                r--;
                for(auto y : divs[r]) cnt[y]--;
            }
        }
        to[0][l] = r;
    }
    to[0][n] = n;
    forn(l,1,20) forn(i,0,n+1) to[l][i] = to[l-1][to[l-1][i]];
    while(q--) {
        int s,e;
        scanf("%d %d", &s, &e);
        s--;
        int ans = 0;
        for(int l = 19; l>=0; l--) {
            if(to[l][s] < e) {
                ans |= 1<<l;
                s = to[l][s];
            }
        }
        ans ++;
        printf("%d\n", ans);
    }
    
    
}