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
int n;
vpi x[3];
const int INF = 2e9;
bool try3(int k) {
    
    forn(col1,0,3) {
        int st = x[col1][k-1].first + 1;
        forn(col2,0,3) {
            if(col2 == col1) continue;
            int pt2 = lower_bound(all(x[col2]), mp(st,-INF)) - x[col2].begin() + k - 1;
            if(pt2 >= n) continue;
            int st2 = x[col2][pt2].first + 1;
            int col3 = 3- col1-col2;
            int pt3 = lower_bound(all(x[col3]), mp(st2,-INF)) - x[col3].begin() + k - 1;
            if(pt3 <n) return true;
        }
    }
    return false;
}

bool try12(int k) {
    forn(col1,0,3) {
        int st = x[col1][k-1].first + 1;
        int col2 = (col1+1)%3;
        int col3 = (col2+1)%3;
        vi y2, y3;
        forn(i,0,n) if(x[col2][i].first >= st) y2.pb(x[col2][i].second);
        forn(i,0,n) if(x[col3][i].first >= st) y3.pb(x[col3][i].second);
        srt(y2);
        srt(y3);
        if(y2.size() < k || y3.size() < k) continue;
        int k2 = y2.size();
        int k3 = y3.size();
        if(y2[k-1] < y3[k3-k] || y3[k-1] < y2[k2-k]) return true;
    }
    return false;
}

void swx() {
    forn(col,0,3) forn(i,0,n) x[col][i].first = -x[col][i].first;
    forn(col,0,3) srt(x[col]);
}

void sw() {
    forn(col,0,3) forn(i,0,n) swap(x[col][i].first, x[col][i].second);
    forn(col,0,3) srt(x[col]);
}

bool can(int k) {
    if(try3(k)) return true;
    if(try12(k)) return true;
    swx();
    if(try12(k)) return true;
    sw();
    if(try3(k)) return true;
    if(try12(k)) return true;
    swx();
    if(try12(k)) return true;
    return false;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    forn(i,0,n) {
        int cx,cy,cc;
        scanf("%d %d %d", &cx, &cy, &cc);
        x[cc-1].pb(mp(cx,cy));
    }
    forn(i,0,3) srt(x[i]);
    n/=3;
    int l = 0;
    int r = n + 1;
    while(r-l>1) {
        int m = (r+l)/2;
        if(can(m)) {
            l = m;
        }
        else r = m;
    }
    cout<<3*l;
    
    
}