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
#define y1 dakjghaog
#define pb push_back
#define mp make_pair

ll da[200102];
ll db[200102];
ll val[531][200101];
int A = 150;
const int N = 75000;
vll x1(N), x2(N), y1(N), y2(N), a(N), b(N);

ll get(int ind, ll pos) {
    if (pos <= x1[ind]) return y1[ind];
    else if(pos <= x2[ind]) return a[ind]*pos+b[ind];
    else return y2[ind];
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    
    int cur = 0;
    int st = 0;
    while(cur < n) {
        st++;
        ll cura = 0;
        ll curb = 0;
        forn(i,cur, min(cur+A, n)) {
//            ll x1,x2,y1,y2,a,b;
            scanf("%lld %lld %lld %lld %lld %lld", &x1[i], &x2[i], &y1[i], &a[i], &b[i], &y2[i]);
            db[0] += y1[i];
            da[x1[i]+1] += a[i];
            db[x1[i]+1] += b[i] - y1[i];
            da[x2[i]+1] -= a[i];
            db[x2[i]+1] += y2[i] - b[i];
        }
        forn(i,0,200002) {
            cura += da[i];
            curb += db[i];
            val[st][i] = cura*i+curb;
        }
        cur += A;
    }
    st++;
    forn(i,0,200002) val[st][i] = val[st-1][i];
    ll last = 0;
    int m;
    scanf("%d", &m);
    forn(i,0,m) {
        int l,r;
        ll x;
        scanf("%d %d %lld", &l, &r, &x);
        l--;
        x = (x+last)%1000000000;
        x = min(x, 200001ll);
        ll ans = 0;
        if(l/A == r/A) {
            forn(j,l,r) ans += get(j, x);
            last = ans;
            printf("%lld\n", ans);
            continue;
        }
        if(r % A > 75) {
            int rto = r+A-r%A;
            while(r < rto) {
                if(r < n) ans -= get(r, x);
                r++;
            }
        }
        else {
            int rto = r-r%A;
            while(r > rto) {
                r--;
                ans += get(r, x);
            }
        }
        ans += val[r/A][x];
        if(l % A > 75) {
            int lto = l+A-l%A;
            while(l < lto) {
                if(l < n) ans += get(l, x);
                l++;
            }
        }
        else {
            int lto = l-l%A;
            while(l > lto) {
                l--;
                ans -= get(l, x);
            }
        }
        ans -= val[l/A][x];
        last = ans;
        printf("%lld\n", ans);
    }

    
    
    
}