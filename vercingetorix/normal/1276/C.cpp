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
    int n;
    read(n);
    readv(a,n);
    map<int, int> cnt;
    for(auto x : a) cnt[x]++;
    int p = 0, q = 0;
    vi s;
    for(auto x : cnt) s.pb(x.second);
    srt(s);
    int l = 0;
    while(l*l <= n) l++;
    l--;
    int r = s.size() - 1;
    int cbad = 0;
    int m = n;
    while(r >= 0 && s[r] > l) {
        m -= s[r] - l;
        cbad++;
        r--;
    }
    while(l>0) {
        if(m >= l*l) {
            int l2 = m/l;
            if(l2*l > p*q) {
                p = l;
                q = l2;
            }
        }
        l--;
        m-=cbad;
        while(r>=0 && s[r] > l) {
            m -= s[r] - l;
            cbad++;
            r--;
        }
    }
    vpi tkh;
    vi tk;
    for(auto x : cnt) {
        tkh.pb(mp(min(x.second, p), x.first));
//        forn(i,0,min(x.second, p)) tk.pb(x.first);
    }
    srtrev(tkh);
    for(auto x : tkh) {
        forn(i,0,x.first) tk.pb(x.second);
    }
    while(tk.size() > p*q) tk.pop_back();
//    srt(tk);
    printf("%d\n", p*q);
    printf("%d %d\n", p, q);
    vvi ans(p, vi(q, 0));
    forn(i,0,p*q) {
        int d = i%p;
        int add = i/p;
        ans[d][(d+add)%q] = tk[i];
    }
    forn(i,0,p) {
        forn(j,0,q) printf("%d ", ans[i][j]);
        printf("\n");
    }
    
    
}