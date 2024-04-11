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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    vvi a(4, vi(n));
    forn(i,0,4) forn(j,0,n) scanf("%d", &a[i][j]);
    vector<pair<int, pi>> ans;
    forn(j,0,n) {
        if(a[1][j] != 0 && a[0][j] == a[1][j]) {
            ans.pb(mp(a[0][j], mp(1, j+1)));
            a[1][j] = 0;
        }
        if(a[2][j] != 0 && a[2][j] == a[3][j]) {
            ans.pb(mp(a[2][j], mp(4, j+1)));
            a[2][j] = 0;
        }
    }
    vpi ord;
    forn(j,0,n) ord.pb(mp(1, j));
    for(int j = n-1; j>=0; j--) ord.pb(mp(2, j));
    int e = -1;
    forn(i,0,ord.size()) if(a[ord[i].first][ord[i].second] == 0) e = i;
    if(e!=-1) {
        forn(it,0,102) {
            forn(ig,0,ord.size()-1) {
                int i = (e+ig)%ord.size();
                int i1 = (i+1)%ord.size();
                if(a[ord[i].first][ord[i].second] == 0 && a[ord[i1].first][ord[i1].second]) {
                    ans.pb(mp(a[ord[i1].first][ord[i1].second], mp(ord[i].first+1, ord[i].second+1)));
                    swap(a[ord[i].first][ord[i].second], a[ord[i1].first][ord[i1].second]);
                }
            }
            e = (e + ord.size() - 1)%ord.size();
            forn(j,0,n) {
                if(a[1][j] != 0 && a[0][j] == a[1][j]) {
                    ans.pb(mp(a[0][j], mp(1, j+1)));
                    a[1][j] = 0;
                }
                if(a[2][j] != 0 && a[2][j] == a[3][j]) {
                    ans.pb(mp(a[2][j], mp(4, j+1)));
                    a[2][j] = 0;
                }
            }
        }
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d %d %d\n", x.first, x.second.first, x.second.second);
    }
    else {
        cout<<-1;
    }
    
    
}