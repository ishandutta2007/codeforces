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
typedef std::vector<ld> vd;
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
int need = 0;
vd mul(vd & a, vd & b) {
    vd c(min(need+1, int(a.size() + b.size()) - 1), 0);
    forn(i,0,a.size()) forn(j,0,b.size()) if(i + j <= need) c[i+j]+=a[i]*b[j];
    return c;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi full;
    vvi a;
    forn(i,0,m) {
        int k;
        scanf("%d", &k);
        readv(xx, k);
        a.pb(xx);
        for(auto x : xx) full.pb(x);
    }
    srtrev(full);
    int bad = full[n-1];
    
    forn(i,0,n) if(full[i] == bad) need++;
    vector<vd> poly;
    vector<vd> w;
    forn(i,0,m) {
        int big = 0;
        int mid = 0;
        int k = a[i].size();
        for(auto x : a[i]) {
            if(x == bad) mid++;
            else if(x>bad) big++;
        }
        int sm = k-big-mid;
        vd cur;
        vd curw;
        ld p = 1;
        forn(i,0,big) {
            p *= ld(big-i)/(k-i);
        }
        forn(tk,0,mid+1) {
            curw.pb(1);
            cur.pb(p);
            if(tk == mid) break;
            p *= ld(big+tk+1)/(tk+1);
            p *= ld(mid - tk)/(mid-tk+sm);
        }
        poly.pb(cur);
        w.pb(curw);
    }
    while(poly.size() > 1) {
        poly[0] = mul(poly[0], poly.back());
        poly.pop_back();
    }
    while(w.size() > 1) {
        w[0] = mul(w[0], w.back());
        w.pop_back();
    }
//    cout<<poly[need+1];
    printf("%.12lf", (double)(poly[0][need]/w[0][need]));
    
}