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
    
    int n,m;
    cin>>n>>m;
    vvll cnk(n+1, vll(n+1, 0));
    cnk[0][0] = 1;
    forn(i,1,n+1) {
        cnk[i][0] = 1;
    }
    forn(nn,1,n+1) forn(k,1,nn+1) {
        cnk[nn][k] = (cnk[nn-1][k] + cnk[nn-1][k-1])%m;
    }
    vvll d0(n+1, vll(n+1, 0));
    vvll d1(n+1, vll(n+1, 0));
    vvll d2(n+1, vll(n+1, 0));
    d0[0][0] = 1;
    d1[0][0] = 1;
    d2[0][0] = 1;
    d2[1][0] = 1;
    d0[1][1] = 1;
    d1[1][1] = 1;
    vll deg2(1,1);
    forn(i,0,500) deg2.pb(deg2.back()*2%m);
    forn(l,2,n+1) {
        forn(s, 1, l+1) {
            for(int f = 1; f<=min(s, l-2); f++) {
                d0[l][s] = (d0[l][s] + cnk[s][f] * d0[f][f] %m * d0[l-f-1][s-f]) % m;
            }
            if(l == s) d0[l][s] = (d0[l][s] + deg2[l-1])%m;
            for(int f = 0; f<=min(s, l-1); f++) {
                d1[l][s] = (d1[l][s] + cnk[s][f] * d0[l-f-1][s-f]) % m;
            }
            if(s == l) d1[l][s] = (d1[l][s] + 1)%m;
            for(int f = 0; f<=min(s, l-1); f++) {
                d2[l][s] = (d2[l][s] + cnk[s][f] * d1[l-f-1][s-f]) % m;
            }
        }
    }
//    forn(l,1,n+1) {
//        forn(tk,0,l) {
//            forn(sl, 0, tk+1) forn(sr, 0, l-tk) {
//                d0[l][sl+sr+1] = (d0[l][sl+sr+1] + d1[tk][sl]*d1[l-1-tk][sr]%m * cnk[sl+sr][sl])%m;
//                d1[l][sl+sr+1] = (d1[l][sl+sr+1] + d2[tk][sl]*d1[l-1-tk][sr]%m * cnk[sl+sr][sl])%m;
//                if(l>1) d2[l][sl+sr+1] = (d2[l][sl+sr+1] + d2[tk][sl]*d2[l-1-tk][sr]%m * cnk[sl+sr][sl])%m;
//            }
//        }
//    }
    ll ans = 0;
    forn(s,0,n+1) ans += d0[n][s];
    cout<<ans%m;
    
   
    
    
}