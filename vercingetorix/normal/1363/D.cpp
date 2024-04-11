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
vi fr;
vvi a;
int n,k;
int ask(int l, int r) {
    vi cur;
    forn(i,l,r+1) for(auto ind : a[i]) cur.pb(ind);
    for(auto ind : fr) cur.pb(ind);
    if(cur.empty()) return 0;
    printf("? %d", (int)cur.size());
    for(auto ind : cur) printf(" %d", ind+1);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int askp(int p) {
    vi cur;
    forn(i,0,k) if(i!=p) for(auto ind : a[i]) cur.pb(ind);
    for(auto ind : fr) cur.pb(ind);
    if(cur.empty()) return 0;
    printf("? %d", (int)cur.size());
    for(auto ind : cur) printf(" %d", ind+1);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main()
{
//#ifdef LOCAL
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        
        scanf("%d %d", &n, &k);
        a = vvi(k);
        vi taken(n,0);
        forn(i,0,k) {
            int l;
            scanf("%d", &l);
            a[i].resize(l);
            forn(j,0,l) scanf("%d", &a[i][j]);
            forn(j,0,l) taken[--a[i][j]] = 1;
        }
        fr.clear();
        forn(i,0,n) if(taken[i] == 0) fr.pb(i);
        int l = 0;
        int r = k;
        int mx =ask(l, r-1);
        while(r-l>1) {
            int m = (r+l)/2;
            if(ask(l,m-1) == mx) r = m;
            else l = m;
        }
        
        int al = askp(l);
        printf("!");
        forn(i,0,k) {
            if(i==l) printf(" %d", al);
            else printf(" %d", mx);
        }
        printf("\n");
        fflush(stdout);
        char c[20];
        string s;
        cin>>s;
    }
    
    
}