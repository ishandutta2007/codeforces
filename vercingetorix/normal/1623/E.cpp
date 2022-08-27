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

int n,k;
const int A = 200500;
char c[A];
int cl[A];
int cr[A];
int loc[A];
int dup[A];
int inc[A];
string def;

int cnext[A];

void dfss(int v) {
    if(v == -1) return;
    dfss(cl[v]);
    loc[v] = def.size();
    if(dup[v]) def.pb(c[v]);
    def.pb(c[v]);
    dfss(cr[v]);
}

bool dfs(int v, int to) {
    if(v == -1) return false;
    bool ret = false;
    to++;
    ret |= dfs(cl[v], to);
    if(ret) {
        dup[v] = 1;
        to = 0;
        dfs(cr[v], to);
    }
    else {
        if(inc[loc[v]] && to <= k) {
            k-=to;
            to = 0;
            dup[v] = 1;
            ret = true;
            dfs(cr[v], to);
        }
    }
    
    return ret;
}
       

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d\n", &n, &k);
    scanf("%s", c);
    forn(i,0,n) {
        scanf("%d %d", &cl[i], &cr[i]);
        cl[i]--;
        cr[i]--;
    }
    dfss(0);
    int last = -1;
    int r = n-1;
    while(r>=0) {
        int pr = r-1;
        while(pr >= 0 && def[pr] == def[r]) pr--;
        forn(i,pr+1,r+1) cnext[i] = last;
        forn(i,pr+1,r+1) {
            if(def[r]-'a' < cnext[i]) inc[i] = 1;
        }
        last = def[r]-'a';
        r = pr;
    }
    dfs(0, 0);
    def.clear();
    dfss(0);
    printf("%s", def.c_str());
}