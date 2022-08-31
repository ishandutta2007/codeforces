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

vs a;
int n,m;
int crow(int i, string & b) {
    int ret = 0;
    forn(j,0,m) if(a[i][j] != b[j]) ret++;
    return ret;
}

int ccol(int j, string & b) {
    int ret = 0;
    forn(i,0,n) if(a[i][j] != b[i]) ret++;
    return ret;
}

void setcol(int j, vs & a, string & b) {
    forn(i,0,n) a[i][j] = b[i];
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &m);
    
    char c[300500];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string (c));
    }
    string agct = "AGCT";
    int best = n*m+1;
    vs ans;
    forn(it,0,4) forn(jt,it+1,4) {
        string z01,z02,z11,z12;
        int p = 0;
        while(p==it || p==jt) p++;
        int q = p+1;
        while(q==it || q==jt) q++;
        forn(i,0,m) {
            if(i%2 == 0) {
                z01.pb(agct[it]);
                z02.pb(agct[jt]);
                z11.pb(agct[p]);
                z12.pb(agct[q]);
            }
            else {
                z01.pb(agct[jt]);
                z02.pb(agct[it]);
                z11.pb(agct[q]);
                z12.pb(agct[p]);
            }
        }
        int ncand = 0;
        vs cand;
        forn(i,0,n) {
            if(i%2==0) {
                if(crow(i, z01) < crow(i, z02)) {
                    ncand += crow(i,z01);
                    cand.pb(z01);
                }
                else {
                    ncand+=crow(i, z02);
                    cand.pb(z02);
                }
            }
            else {
                if(crow(i, z11) < crow(i, z12)) {
                    ncand += crow(i,z11);
                    cand.pb(z11);
                }
                else {
                    ncand+=crow(i, z12);
                    cand.pb(z12);
                }
            }
        }
        if(ncand < best) {
            best = ncand;
            ans = cand;
        }
    }
    forn(it,0,4) forn(jt,it+1,4) {
        string z01,z02,z11,z12;
        int p = 0;
        while(p==it || p==jt) p++;
        int q = p+1;
        while(q==it || q==jt) q++;
        forn(i,0,n) {
            if(i%2 == 0) {
                z01.pb(agct[it]);
                z02.pb(agct[jt]);
                z11.pb(agct[p]);
                z12.pb(agct[q]);
            }
            else {
                z01.pb(agct[jt]);
                z02.pb(agct[it]);
                z11.pb(agct[q]);
                z12.pb(agct[p]);
            }
        }
        int ncand = 0;
        vs cand(n, string(m, '.'));
        forn(i,0,m) {
            if(i%2==0) {
                if(ccol(i, z01) < ccol(i, z02)) {
                    ncand += ccol(i,z01);
                    setcol(i, cand, z01);
                }
                else {
                    ncand+=ccol(i, z02);
                    setcol(i, cand, z02);
                }
            }
            else {
                if(ccol(i, z11) < ccol(i, z12)) {
                    ncand += ccol(i,z11);
                    setcol(i, cand, z11);
                }
                else {
                    ncand+=ccol(i, z12);
                    setcol(i, cand, z12);
                }
            }
        }
        if(ncand < best) {
            best = ncand;
            ans = cand;
        }
    }
//    cout<<best<<endl;
    for(auto x : ans) printf("%s\n", x.c_str());
    
    
}