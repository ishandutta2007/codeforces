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
int d2[20];
int last[20][20];
int nx[20][300500];
int a[300500];
int bx[19];
int taken[19];

void kach(int i) {
    forn(bit,0,19) {
        bx[bit] = min(bx[bit], nx[bit][i]);
        if(a[i]&d2[bit]) taken[bit] = 1;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d2[0] = 1;
    forn(i,1,20) d2[i] = d2[i-1]*2;
    int n,q;
    scanf("%d %d", &n, &q);
    forn(i,0,n) scanf("%d", &a[i]);
    forn(i,0,20) forn(j,0,20) last[i][j] = n;
    forn(i,0,20) forn(j,0,300500) nx[i][j] = n;
    for(int i = n-1; i >= 0; i--) {
        forn(bit,0,19) if(a[i]&d2[bit]) {
            nx[bit][i] = i;
            forn(bit2,0,19) {
                if(a[i]&d2[bit2]) last[bit][bit2] = i;
                else nx[bit2][i] = min(nx[bit2][i], last[bit][bit2]);
            }
        }
    }
    while(q--) {
        int l, r;
        scanf("%d %d", &l, &r);
        l--;
        r--;
        forn(i,0,19) taken[i] = 0;
        forn(i,0,19) bx[i] = n;
        kach(l);
        forn(it,0,20) {
            int cur = n;
            forn(bit,0,19) if(taken[bit] == 0) cur = min(cur, bx[bit]);
            if(cur > r) break;
            kach(cur);
        }
        int can = 0;
        forn(bit,0,19) if((d2[bit]&a[r])&&taken[bit]) can = 1;
        if(can) printf("Shi\n");
        else printf("Fou\n");
    }
    
    
}