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

int ask(int a, int b) {
    printf("1 %d %d\n", a, b);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int ask(int a, vi b) {
    if(b.empty()) return 0;
    printf("2 %d %d", a, (int)b.size());
    for(auto x : b) printf(" %d", x);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

vi goline(int n) {
    vi ord;
    int ret = ask(0,1);
    if(ret) ord = {0,1};
    else ord = {1,0};
    forn(v, 2, n) {
        if(ask(ord[v-1], v)) ord.pb(v);
        else if(ask(v, ord[0])) {
            vi nord;
            nord.pb(v);
            for(auto x : ord) nord.pb(x);
            swap(ord, nord);
        }
        else {
            int l = 0;
            int r = v-1;
            while(r-l > 1) {
                int m = (r+l)/2;
                if(ask(ord[m], v)) l = m;
                else r = m;
            }
            vi nord;
            forn(i,0,l+1) nord.pb(ord[i]);
            nord.pb(v);
            forn(i,r,v) nord.pb(ord[i]);
            swap(ord, nord);
        }
    }
    return ord;
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        vi ord = goline(n);
        vi lm(n);
        forn(i,0,n) lm[i] = i;
        int r = n - 1;
        while(r >= 0) {
            int l = r;
            int pt = r;
            while(pt >= l) {
                vi left;
                forn(j,0,l) left.pb(ord[j]);
                if(ask(ord[pt], left)) {
                    for(int j = l-1; j>=0; j--) if(ask(ord[pt], ord[j])) {
                        l = j;
                        break;
                    }
                }
                else pt--;
            }
            forn(i,l,r+1) lm[i] = l;
            r = l-1;
        }
        vs ans(n, string(n,'0'));
        forn(i,0,n) forn(j,lm[i],n) ans[ord[i]][ord[j]] = '1';
        printf("3\n");
        forn(i,0,n) printf("%s\n", ans[i].c_str());
        fflush(stdout);
        int ret;
        scanf("%d", &ret);
    }
    
    
}