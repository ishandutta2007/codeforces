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
const int A = 200500;
//const int A = 20;
vi col[A];
vi row[A];
int n,m;
set<pi> buff;


int imp(int x, int y) {
    auto it = lower_bound(all(row[x]), y);
    if(it!=row[x].end() && *it == y) return 1;
    return 0;
}
const int INF = 1e6;
int gorow(int x, int y) {
    if(x + m < n) return INF;
    if(y==m) return 1;
    int pt = lower_bound(all(row[x]), y) - row[x].begin();
    if(pt != row[x].size())
    while(1) {
        int st = 1e6;
    }
    return 0;
}

//int gocol(int x, int y) {
//
//}

int go(int x, int y) {
    
    int add = imp(x,y);
//    cout<<x<<' '<<y<<' '<<add<<endl;
    if(x == n) {
        if(y==m) return 0;
        return 1+go(x, min(x+y+add,m));
    }
    else if(y==m) {
        return 1+go(min(x+y+add, n), y);
    }
    if(x==y) {
        if(imp(x,y)) return 1+min(go(min(x+y+1, n), y), go(x, min(x+y+1,m)));
        else return 1+min(go(min(x+y, n), y), go(x, min(x+y,m)));
    }
    else {
        int ret;
        if(x>y) ret = 1+ go(x, min(x+y+add,m));
        else ret  = 1+go(min(x+y+add, n), y);
        forn(mask,0,8) {
            int cx = x;
            int cy = y;
            forn(bit,0,3) {
                int add1 = imp(cx,cy);
                if(mask&(1<<bit)) cx = min(cx+cy+add1,n);
                else cy = min(cx+cy+add1,m);
                if(cx==n && cy==m) {
                    ret = min(ret, bit+1);
                    break;
                }
            }
            if(cx == n) ret = min(ret, 3 + go(cx, cy));
            if(cy==m) ret = min(ret, 3 + go(cx, cy));
        }
        return ret;
    }
//    else if(x > y) {
//        int ret = go(x, min(x+y+add,m));
//        if(x+y+add>=n) ret = min(ret, go(n,y));
////        if(x+y+y+add>=max(m,n)) ret = min(ret, 1);
//        return ret+1;
////        if(x+y < m) return go(x, x+y);
//    }
//    else {
//
//        int ret  = go(min(x+y+add, n), y);
//        if(x+y+add>=m) ret = min(ret, go(x,m));
////        if(x+y+x+add>=max(m,n)) ret = min(ret, 1);
//        return ret+1;
////        if(x+y<n) return go(x+y,y);
//    }

//    if(x > y) return min(go(x, min(x+y+add, m)), gorow(min(x+y+add,n), y));
//    else return min(go(min(x+y+add,n), y), gocol(x, min(x+y+add,m)));
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &m);
    int q;
    read(q);
    while(q--) {
        int k,l;
        scanf("%d %d", &k, &l);
        col[l].pb(k);
        row[k].pb(l);
    }
    forn(i,0,A) srt(row[i]);
    cout<<go(1,1);
    
    
}