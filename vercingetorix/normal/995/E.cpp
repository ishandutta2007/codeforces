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
map<int, int> x;
int p;
ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    if(a == 0) return 0;
    ll x, y;
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

void go(int cur, int left) {
    if(left == 0) return;
    for(int i = -left+1; i<=left-1; i++) {
        if(i==0) continue;
        int to = cur + i + p;
        while(to >= p) to-=p;
        while(to < 0) to+=p;
        if(to) to = invmod(to, p);
        if(x.count(to)) continue;
        x[to] = i;
        go(to, left-abs(i)-1);
    }
}

void randgo(int cur, int left) {
    if(left <= 4) return;
    int i = gen()%(2*left-1) - left + 1;
    if(i == 0) return;
    int to = cur + i + p;
    while(to >= p) to -= p;
    while(to < 0) to += p;
    if(to) to = invmod(to, p);
    if(x.count(to)) return;
    x[to] = i;
    randgo(to, left-abs(i)-1);
}

map<int, int> y;

void go2(int cur, int left) {
    if(left == 0) return;
    for(int i = -left+1; i<=left-1; i++) {
        if(i==0) continue;
        int to = cur + i + p;
        while(to >= p) to-=p;
        while(to<0) to+=p;
        if(to) to = invmod(to, p);
        if(y.count(to)) continue;
        y[to] = i;
        go2(to, left-abs(i)-1);
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int u,v;
    scanf("%d %d %d", &u, &v, &p);
    if(p == 2) {
        if(u==v) {
            cout<<0;
        }
        else {
            cout<<1<<endl<<1;
        }
        exit(0);
    }
    go(u,min(p-1, 20));
//    for(auto y : x) printf("%d %d\n", y.first, y.second);
    
    vi was;
    for(auto y : x) was.pb(y.first);
    forn(i,0,100000) {
        int fr = was[gen()%was.size()];
        randgo(fr, 105);
    }
    go2(v,min(p-1, 20));
    vi ans;
    for(auto tu : x) {
        int s = tu.first - 50;
        while(s < 0) s += p;
        forn(i,s,s+101) {
            if(y.count(i%p)) {
                int m = tu.first;
                while(m != u) {
                    ans.pb(3);
                    int op = x[m];
                    while(op < 0) {
                        op++;
                        ans.pb(2);
                    }
                    while(op > 0) {
                        op--;
                        ans.pb(1);
                    }
                    m = ((invmod(m, p) - x[m])%p+p)%p;
                }
                reverse(all(ans));
                int op = i - (s+50);
//                while(op < 0) {
//                    op++;
//                    ans.pb(1);
//                }
                while(op < 0) {
                    op++;
                    ans.pb(2);
                }
                while(op > 0) {
                    op--;
                    ans.pb(1);
                }
                m = i%p;
                while(m != v) {
                    ans.pb(3);
                    int op = y[m];
                    while(op < 0) {
                        op++;
                        ans.pb(1);
                    }
                    while(op > 0) {
                        op--;
                        ans.pb(2);
                    }
                    m = ((invmod(m, p) - y[m])%p+p)%p;
                }
                printf("%d\n", ans.size());
                for(auto k : ans) printf("%d ", k);
                int cur = u;
                for(auto dd : ans) {
                    if(dd == 1) cur = (cur+1)%p;
                    else if(dd==2) cur = (cur+p-1)%p;
                    else cur = invmod(cur, p);
                }
//                printf("\n%d\n", cur);
                exit(0);
            }
        }
    }
    
    
    
    
}