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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[100];
    vll d2(1,1);
    forn(i,0,62) d2.pb(d2.back()*2);
    vll nbits;
    forn(i,0,d2[15]) {
        int m = i;
        nbits.pb(0);
        while(m>0) {
            nbits.back()+=m%2;
            m/=2;
        }
    }
    vvi pl(d2[15]);
    vvi mn(d2[15]);
//    int x = 0;
    forn(i,0,d2[15]) forn(j,i+1,d2[15]) {
        if((j&i) == i) {
            if(nbits[i] % 2 == nbits[j] % 2) mn[i].pb(j);
            else pl[i].pb(j);
        }
    }
//    cout<<x;
//    exit(0);
    
    int n,m,p;
    scanf("%d %d %d\n", &n, &m, &p);
    vll s(n, 0);
    forn(i,0,n) {
        scanf("%s", c);
        forn(j,0,m) if(c[j] == '1') s[i] |= d2[j];
    }
    
    pll res(0,0);
    forn(tr,0,33) {
        ll k = s[gen()%n];
        vi bits;
        forn(i,0,m) if(k&d2[i]) bits.pb(i);
        vi cnt(d2[15], 0);
        forn(i,0,n) {
            int cur = 0;
            forn(j,0,bits.size()) if(s[i]&d2[bits[j]]) cur |= d2[j];
            cnt[cur] ++;
        }
        pll ans(0,0);
        for(int i = d2[15] - 1; i >=0; i--) {
            for(auto j : pl[i]) cnt[i] += cnt[j];
            for(auto j : mn[i]) cnt[i] -= cnt[j];
            if(cnt[i] >= (n+1)/2) ans = max(ans, mp(nbits[i], ll(i)));
        }
        ll rl = 0;
        forn(i,0,bits.size()) if(ans.second&d2[i]) rl|=d2[bits[i]];
        res = max(res, mp(ans.first, rl));
    }
    forn(i,0,m) printf("%d", (res.second&d2[i]) / d2[i]);
    
}