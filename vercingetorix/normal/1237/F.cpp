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

const long long mod = 998244353;
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair


const int A = 3601;
vll nfac(A, 0);
vvll cnk(A, vll(A, 0));
vvll s2(A, vll(A, 0));
ll d[A][A];
vvll go(vi & lens) {
    vvll res(A, vll(A, 0));
    vll res2(A,0);
    res2[0] = 1;
    res[0][0] = 1;
    int num = 0;
    int m2 = 0;
    for(auto x : lens) {
        int dm2 = x/2;
        for(int un2 = m2 + dm2; un2>=0; un2--) {
            forn(n2,max(1, un2-m2),min(dm2+1, un2 + 1)) {
                res2[un2] = (res2[un2] + s2[x][n2] * res2[un2-n2]) % mod;
            }
        }
        num += x;
        m2 += dm2;
    }
    res[0] = res2;
    forn(c2,0,A) forn(c1,1,A) {
        if(c2*2 + c1 <= num) {
            res[c1][c2] = res[0][c2] * cnk[num-2*c2][c1] %mod;
        }
    }
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    nfac[0] = 1;
    forn(i,1,A) {
        nfac[i] = nfac[i-1]*i%mod;
    }
    cnk[0][0] = 1;
    forn(n,1,A) {
        cnk[n][0] = 1;
        forn(k,1,n+1) {
            cnk[n][k] = (cnk[n-1][k] + cnk[n-1][k-1])%mod;
        }
    }
    
    forn(n,0,A) {
        s2[n][0] = 1;
        if(n<2) continue;
        forn(k,1,A) {
            s2[n][k] = (s2[n-1][k] + s2[n-2][k-1])%mod;
        }
    }
    forn(i,0,A) forn(j,0,A) d[i][j] = 0;
    int n,w,h;
    scanf("%d %d %d", &h, &w, &n);
    vi br(h,0);
    vi bc(w,0);
    forn(i,0,n) {
        int r1,c1,r2,c2;
        scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
        r1--; r2--; c1--; c2--;
        br[r1] = 1;
        br[r2] = 1;
        bc[c1] = 1;
        bc[c2] = 1;
    }
    vi rn, cn;
    int pt = 0;
    while(pt < h) {
        while(pt < h && br[pt]) pt++;
        if(pt==h) break;
        int pr = pt+1;
        while(pr < h && br[pr] == 0) pr++;
        rn.pb(pr-pt);
        pt = pr;
    }
    pt = 0;
    while(pt < w) {
        while(pt < w && bc[pt]) pt++;
        if(pt==w) break;
        int pr = pt+1;
        while(pr < w && bc[pr] == 0) pr++;
        cn.pb(pr-pt);
        pt = pr;
    }
    sort(all(rn));
    sort(all(cn));
    reverse(all(rn));
    reverse(all(cn));
    vvll dr = go(rn);
    vvll dc = go(cn);
    ll ans = 0;
    forn(c1,0,A) {
        forn(c2,0,A) {
            ans = (ans + dr[c1][c2]*dc[c2][c1] %mod * nfac[c1] %mod * nfac[c2]%mod)% mod;
        }
    }
    cout<<ans;
}