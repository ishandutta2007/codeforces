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
const int A = 500;
vpi w[A*A];
int l[A*A];
int r[A*A];
int u[A*A];
int d[A*A];
int pt = 0;
int c[A+1][A+1];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vvi a(n, vi(n));
    forn(i,0,n) forn(j,0,n) {
        scanf("%d", &a[i][j]);
        a[i][j]--;
        w[a[i][j]].pb(mp(i,j));
    }
    int cur = 0;
    forn(i,0,n*n) {
        if(!w[i].empty()) {
            cur++;
            l[pt] = A;
            r[pt] = 0;
            u[pt] = A;
            d[pt] = 0;
            for(auto x : w[i]) {
                l[pt] = min(l[pt], x.second);
                r[pt] = max(r[pt], x.second);
                u[pt] = min(u[pt], x.first);
                d[pt] = max(d[pt], x.first);
            }
            pt++;
        }
    }
    if(cur <= k) {
        cout<<k-cur;
        exit(0);
    }
    forn(len,1,n+1) {
        forn(i,0,n) forn(j,0,n) c[i][j] = 0;
//        cout<<len<<'\n';
        forn(i,0,pt) {
            int u2 = max(d[i]-len+1, 0);
            int d2 = min(n-len,u[i]);
            int l2 = max(r[i]-len+1, 0);
            int r2 = min(n-len,l[i]);
//            cout<<u2<<' '<<d2<<' '<<l2<<' '<<r2<<'\n';
            if(r2>=l2 && d2>=u2) {
                c[u2][l2]++;
                c[d2+1][l2]--;
                c[u2][r2+1]--;
                c[d2+1][r2+1]++;
            }
        }
        int win = 0;
        forn(i,0,n-len+1) {
            forn(j,1,n-len+1) c[i][j]+=c[i][j-1];
            forn(j,0,n-len+1) {
                if(i>0) c[i][j] += c[i-1][j];
                if(c[i][j] == cur-k || (c[i][j] == cur-k+1)) win=1;
            }
        }
        
        if(win) {
            cout<<1;
            exit(0);
        }
    }
    cout<<2;
    
}