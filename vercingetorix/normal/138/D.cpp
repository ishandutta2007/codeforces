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
int d[42][42][42][42];

int gg[10000];
vi tk;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    cin>>n>>m;
    vs a(n);
    forn(i,0,n) cin>>a[i];
    forn(odd,0,2) {
        for(int sr = odd; sr <= 40; sr += 2) {
            for(int dr = odd; dr <= 40; dr += 2) {
                for(int sl = sr; sl>=0; sl-=2) {
                    for(int dl = dr; dl>=0; dl-=2) {
                        for(int sm = sl; sm<=sr; sm+=2) {
                            for(int dm = max(dl, 20-sm); dm <= dr; dm+=2) {
                                int i = (sm + dm - 20)/2;
                                int j = (sm - dm + 20)/2;
                                if(i >= n) break;
                                if(i >= 0 && j>=0 && j < m) {
                                    vi bs,bd;
                                    bs.pb(sl-2);
                                    if(a[i][j] != 'R') bs.pb(sm);
                                    bs.pb(sr+2);
                                    bd.pb(dl-2);
                                    if(a[i][j] != 'L') bd.pb(dm);
                                    bd.pb(dr+2);
                                    int cur = 0;
                                    forn(b1,1,bs.size()) forn(d1,1,bd.size()) {
                                        if(bs[b1] > bs[b1-1]+2 && bd[d1] > bd[d1-1] + 2) {
                                            cur ^= d[bs[b1-1]+2][bs[b1]-2][bd[d1-1]+2][bd[d1]-2];
                                        }
                                    }
                                    tk.pb(cur);
                                    gg[cur] = 1;
                                 }
                            }
                        }
                        int pt = 0;
                        while(gg[pt]) pt++;
                        if(pt != 0) {
                            d[sl][sr][dl][dr] = pt;
                        }
                        for(auto x : tk) gg[x] = 0;
                        tk.clear();
                    }
                }
            }
        }
    }
    int gr = d[0][40][0][40] ^ d[1][39][1][39];
    if(gr == 0) printf("LOSE\n");
    else printf("WIN\n");
    
    
    
}