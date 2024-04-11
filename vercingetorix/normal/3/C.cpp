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
vvpi win;

int won(vs a) {
    int w1 = 0;
    int w2 = 0;
    for(auto x : win) {
        int c1 = 0;
        int c2 = 0;
        for(auto f : x) {
            if(a[f.first][f.second] == 'X') c1++;
            if(a[f.first][f.second] == '0') c2++;
        }
        if(c1 == 3) w1++;
        if(c2 == 3) w2++;
    }
    if(w1*w2 > 0) return -1;
    if(w1 > 0) return 1;
    if(w2 > 0) return 2;
    return 0;
}

void bad() {
    printf("illegal");
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[4];
    vs a;
    int c1 = 0;
    int c2 = 0;
    forn(i,0,3) {
        scanf("%s", c);
        a.pb(string(c));
        forn(j,0,3) if(a[i][j] == 'X') c1++;
        forn(j,0,3) if(a[i][j] == '0') c2++;
    }
    forn(i,0,3) {
        vpi x;
        forn(j,0,3) x.pb(mp(i,j));
        win.pb(x);
        x.clear();
        forn(j,0,3) x.pb(mp(j,i));
        win.pb(x);
    }
    vpi x;
    forn(i,0,3) {
        x.pb(mp(i,i));
    }
    win.pb(x);
    x.clear();
    forn(i,0,3) {
        x.pb(mp(i,2-i));
    }
    win.pb(x);
    if(c1 == c2) {
        int w = won(a);
        if(w == -1 || w == 1) bad();
        else if(w == 0) {
            printf("first");
        }
        else {
            forn(i,0,3) forn(j,0,3) if(a[i][j] == '0') {
                a[i][j] = '.';
                if(won(a) == 0) {
                    printf("the second player won");
                    exit(0);
                }
                a[i][j] = '0';
            }
            bad();
        }
    }
    else if(c1 == c2+1) {
        int w = won(a);
        if(w == -1 || w == 2) bad();
        else if(w == 0) {
            if(c1+c2==9) printf("draw");
            else printf("second");
        }
        else {
            forn(i,0,3) forn(j,0,3) if(a[i][j] == 'X') {
                a[i][j] = '.';
                if(won(a) == 0) {
                    printf("the first player won");
                    exit(0);
                }
                a[i][j] = 'X';
            }
            bad();
        }
    }
    else {
        bad();
    }
    
    
}