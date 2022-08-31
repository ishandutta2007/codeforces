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
vi dig[10];
vi skip;
ll best;
int r = 1;
int n,d;
void go(vi & sk) {
    if(sk.size() >= 5) return;
    ll mul = 1;
    for(auto x : sk) {
        mul *= x;
    }
    if(mul%5*d%5 == r) {
        if(best > mul) {
            skip = sk;
            best = mul;
        }
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    const ll INF = 1e18;
    scanf("%d %d", &n, &d);
    readv(a,n);
    int d2 = 0;
    int d5 = 0;
    forn(i,0,n) {
        dig[a[i]%10].pb(a[i]);
        if(a[i]%2 == 0) d2=1;
        if(a[i]%5 == 0) d5=1;
    }
    forn(i,0,10) srt(dig[i]);
    if(d == 0) {
        if(d2 > 0 && d5 > 0) {
            printf("%d\n",n);
            for(auto x : a) printf("%d ", x);
        }
        else printf("-1");
        exit(0);
    }
    else if(d == 5) {
        if(dig[5].size() > 0) {
            vi ans;
            forn(i,0,n) if(a[i]%2==1) ans.pb(a[i]);
            printf("%d\n", ans.size());
            for(auto  x : ans) printf("%d ", x);
        }
        else printf("-1");
        exit(0);
    }
    else if((d%2==1)) {
        r = 1;
        skip.clear();
        best = INF;
        forn(i,1,10) {
            if(i==5 || i % 2 == 0) continue;
            forn(j,0,dig[i].size()) r = r*i%5;
        }
        int tot = dig[3].size() + dig[7].size() + dig[9].size() + dig[1].size();
        forn(t3,0,min(4,(int)dig[3].size()+1)) {
            forn(t7,0,min(4,(int)dig[7].size()+1)) {
                forn(t9, 0, min(2, (int)dig[9].size() + 1)) {
                    if(t3 + t7 + t9 >= 5) continue;
                    vi sk;
                    forn(i,0,t3) {
                        sk.pb(dig[3][i]);
                    }
                    forn(i,0,t7) {
                        sk.pb(dig[7][i]);
                    }
                    forn(i,0,t9) {
                        sk.pb(dig[9][i]);
                    }
                    if(sk.size() < tot) go(sk);
                }
            }
        }
        if(best == INF) {
            printf("-1");
        }
        else {
            vi ans;
            forn(i,0,n) {
                if(a[i] % 2 == 0 || a[i] % 5 == 0) continue;
                int bad = 0;
                forn(j,0,skip.size()) {
                    if(a[i] == skip[j]) {
                        bad = 1;
                        swap(skip[j], skip.back());
                        skip.pop_back();
                        break;
                    }
                }
                if(bad == 0) ans.pb(a[i]);
            }
            printf("%d\n", ans.size());
            for(auto  x : ans) printf("%d ", x);
        }
    }
    else {
        int cnt = 0;
        r = 1;
        skip.clear();
        best = INF;
        int tot = n - dig[0].size() - dig[5].size();
        forn(i,1,10) {
            if(i%5 == 0) continue;
            forn(j,0,dig[i].size()) r = r*i%5;
        }
        for(int i = 2; i<=8; i+=2) {
            cnt+=dig[i].size();
            int j = i+5;
            if(j>=10) j-=10;
            for(auto x:dig[i]) dig[j].pb(x);
        }
        forn(i,0,10) srt(dig[i]);
        
        forn(t3,0,min(5,(int)dig[3].size()+1)) {
            forn(t7,0,min(5,(int)dig[7].size()+1)) {
                forn(t9, 0, min(3, (int)dig[9].size() + 1)) {
                    if(t3 + t7 + t9 >= 6) continue;
                    vi sk;
                    forn(i,0,t3) {
                        sk.pb(dig[3][i]);
                    }
                    forn(i,0,t7) {
                        sk.pb(dig[7][i]);
                    }
                    forn(i,0,t9) {
                        sk.pb(dig[9][i]);
                    }
                    int curcnt = 0;
                    for(auto x : sk) if(x % 2 == 0) curcnt++;
                    if(curcnt < cnt && sk.size() < tot) go(sk);
                    else {
                        forn(i,0,sk.size()) {
                            if(sk[i] % 2 == 0) {
                                swap(sk[i], sk.back());
                                int mem = sk.back();
                                sk.pop_back();
                                if(sk.size() < tot) go(sk);
                                sk.pb(mem);
                                swap(sk[i], sk.back());
                            }
                        }
                    }
                }
            }
        }
        if(best == INF) {
            printf("-1");
        }
        else {
            vi ans;
            forn(i,0,n) {
                if(a[i] % 5 == 0) continue;
                int bad = 0;
                forn(j,0,skip.size()) {
                    if(a[i] == skip[j]) {
                        bad = 1;
                        swap(skip[j], skip.back());
                        skip.pop_back();
                        break;
                    }
                }
                if(bad == 0) ans.pb(a[i]);
            }
            printf("%d\n", ans.size());
            for(auto  x : ans) printf("%d ", x);
        }
    }
    
    
}