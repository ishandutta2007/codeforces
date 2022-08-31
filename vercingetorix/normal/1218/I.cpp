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
vvi a;
vpi op;
void done() {
    forn(i,0,n) forn(j,0,n) {
        if(a[i][j]) return;
    }
    printf("%d\n", op.size());
    forn(i,0,op.size()) {
        if(op[i].first == 0) printf("row");
        else printf("col");
        printf(" %d\n", op[i].second);
    }
    exit(0);
}
void no() {
    cout<<-1;
    exit(0);
}
vi d;

void fliprow(int i) {
    op.pb(mp(0, i));
    forn(j,0,n) a[i][j] ^=d[j];
}

void flipcol(int i) {
    op.pb(mp(1, i));
    forn(j,0,n) a[j][i] ^=d[j];
}

void go(int p) {
    forn(j,0,n) {
        if(a[p][j]) flipcol(j);
    }
    forn(i,0,n) if(i != p && a[i][p]) fliprow(i);
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    a = vvi(n, vi(n, 0));
    char c[2050];
    forn(i,0,n) {
        scanf("%s", c);
        forn(j,0,n) a[i][j] ^= (int)(c[j]-'0');
    }
    forn(i,0,n) {
        scanf("%s", c);
        forn(j,0,n) a[i][j] ^= (int)(c[j]-'0');
    }
    scanf("%s", c);
    forn(i,0,n) d.pb(c[i]-'0');
    done();
    int sum =0;
    forn(i,0,n) sum+=d[i];
    if(sum == 0) no();
    int p = 0;
    while(d[p] == 0) p++;
    go(p);
    done();
    fliprow(p);
    go(p);
    done();
    no();
}