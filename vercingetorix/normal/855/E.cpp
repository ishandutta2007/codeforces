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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

vi getcnt(ll x, int b) {
    vi cnt(b,0);
    while(x > 0) {
        cnt[x%b]++;
        x/=b;
    }
    return cnt;
}

ll opt[61][61][61];
ll opt0[11][61];

ll proc(vi & cnt, int b, int bits) {
    vi c(2,0);
    forn(i,0,b) c[cnt[i]&1]++;
    return opt[c[0]][c[1]][bits];
}

ll proc0(int b, int bits) {
    return opt0[b][bits];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(c0,0,61) forn(c1,0,61) {
        if(c1==0) opt[c0][c1][0] = 1;
        else opt[c0][c1][0] = 0;
    }
    forn(n,1,61) {
        forn(a,0,61) forn(b,0,61) {
            if(a>0) opt[a][b][n] += a*opt[a-1][b+1][n-1];
            if(b>0) opt[a][b][n] += b*opt[a+1][b-1][n-1];
        }
    }
    forn(b,2,11) forn(bits,0,61) {
        forn(z,0,bits) opt0[b][bits] += (b-1)*opt[b-1][1][z];
    }
    int q;
    scanf("%d", &q);
    forn(agag,0,q) {
        int b;
        ll l,r;
        scanf("%d %lld %lld", &b, &l, &r);
        r++;
        int bits = 0;
        vi curl = getcnt(l,b);
        vi curr = getcnt(r,b);
        ll ans = 0;
        while(r>l) {
            while((l%b)!=0) {
                int lb = l%b;
                curl[lb--]--;
                curl[lb]++;
                l--;
                if(l==0) ans-=proc0(b,bits);
                else ans -= proc(curl, b, bits);
            }
            while((r%b)!=0) {
                int rb = r%b;
                curr[rb--]--;
                curr[rb]++;
                r--;
                if(r==0) ans += proc0(b, bits);
                else ans += proc(curr, b, bits);
                
            }
            l/=b;
            r/=b;
            bits++;
            curl[0]--;
            curr[0]--;
        }
        printf("%lld\n", ans);
    }
    
}