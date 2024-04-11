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

bool ask(int x) {
    printf("? %d\n", x+1);
    fflush(stdout);
    char c;
    scanf("\n%c", &c);
    if(c=='Y') return true;
    else return false;
}

void forget() {
    printf("R\n");
    fflush(stdout);
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vi g(n,1);
    if(k == 1) {
        forn(i,0,n) {
            forn(j,i+1,n) {
                if(g[i] + g[j] == 2) {
                    if(ask(i)) {
                        g[i] = 0;
                        forget();
                        continue;
                    }
                    if(ask(j)) {
                        g[j] = 0;
                        forget();
                    }
                }
            }
        }
        int ans = 0;
        forn(i,0,n) ans += g[i];
        printf("! %d\n", ans);
        exit(0);
    }
    vvi a(k, vi(n/k));
    forn(i,0,n) a[i%k][i/k] = i;
    forn(j,0,n/k) {
        forget();
        forn(i,0,k) {
            if(ask(a[i][j])) {
                g[a[i][j]] = 0;
            }
        }
    }
    forn(j1,0,n/k) {
        forn(j2,j1+1,n/k) {
            vi xa,xb,xc,xd;
            forn(i,0,k/2) if(g[a[i][j1]]) xa.pb(a[i][j1]);
            forn(i,k/2,k) if(g[a[i][j1]]) xb.pb(a[i][j1]);
            forn(i,0,k/2) if(g[a[i][j2]]) xc.pb(a[i][j2]);
            forn(i,k/2,k) if(g[a[i][j2]]) xd.pb(a[i][j2]);
            if(xa.size() + xb.size() == 0 || xc.size() + xd.size() == 0) continue;
            if(xb.size() > xa.size()) swap(xa, xb);
            if(xd.size() > xc.size()) swap(xc, xd);
            if(xd.size() == 0) {
                swap(xd,xb);
                swap(xa,xc);
            }
            forn(i,0,k) ask(xa[i%(xa.size())]);
//            int ca = 0;
//            for(auto x : xa) {
//                ask(x);
//                ca++;
//            }
//            while(ca < k) {
//                ca++;
//                ask(xa[0]);
//            }
            for(auto x : xc) {
                if(ask(x)) {
                    g[x] = 0;
                }
            }
            for(auto x : xb) {
                if(ask(x)) {
                    g[x] = 0;
                }
            }
            forn(i,0,k) ask(xa[i%(xa.size())]);
//            ca = 0;
//            for(auto x : xa) {
//                ask(x);
//                ca++;
//            }
//            while(ca < k) {
//                ca++;
//                ask(xa[0]);
//            }
            for(auto x : xd) {
                if(ask(x)) {
                    g[x] = 0;
                }
            }
            for(auto x : xb) {
                if(ask(x)) {
                    g[x] = 0;
                }
            }
//            if(xb.size() == 0) {
//
//            }
//            else {
//                int cb = 0;
//                for(auto x : xb) {
//                    ask(x);
//                    cb++;
//                }
//                while(cb < k) {
//                    ask(xb[0]);
//                    cb++;
//                }
//                int ca = 0;
//                int ad = 0;
//                for(auto x : xc) {
//                    if(ask(x)) {
//                        g[x] = 0;
//                    }
//                    ca++;
//                }
//                for(auto x : xa) {
//                    if(ask(x)) {
//                        g[x] = 0;
//                    }
//                    ca++;
//                    ad++;
//                }
//                while(ca < k || ad+xd.size() < k) {
//                    ask(xa[0]);
//                    ca++;
//                    ad++;
//                }
//                for(auto x : xd) {
//                    if(ask(x)) {
//                        g[x] = 0;
//                    }
//                }
//                for(auto x : xb) {
//                    if(ask(x)) {
//                        g[x] = 0;
//                    }
//                }
//            }
        }
    }
    int ans = 0;
    forn(i,0,n) ans += g[i];
    printf("! %d\n", ans);
    exit(0);
    
}