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
ll get_rand_prime() {
    ll ret;
    while (true) {
        ret = ll(5e8) + gen() % (ll)5e8;
        bool good = true;
        for (int i = 2; i * i <= ret; i++) {
            if (ret % i == 0) {
                good = false;
                break;
            }
        }
        if (good) return ret;
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    int num = 2;
    vll p;
    forn(i,0,num) p.pb(get_rand_prime());
    vi cnt(n+1,0);
    vvll d31(num, vll(1,1));
    forn(j,0,num) {
        forn(i,0,n+1) d31[j].pb(d31[j].back()*31%p[j]);
    }
    vll hs(num,0);
    map<ll, int> hv;
    hv[0] = 1;
    ll ans = 0;
    vll hwas(1,0);
    vvll pos(n+1);
    int l = -1;
    forn(i,0,n) {
        int v = a[i];
        forn(j,0,num) {
            hs[j] = (hs[j] + 2 * p[j] - cnt[v]*d31[j][v]);
            while(hs[j] >= p[j]) hs[j] -= p[j];
        }
        cnt[v] = cnt[v] + 1;
        if(cnt[v] == 3) cnt[v] = 0;
        forn(j,0,num) {
            hs[j] = (hs[j] + cnt[v]*d31[j][v]);
            while(hs[j] >= p[j]) hs[j] -= p[j];
        }
        ll h = hs[0] * p[1] + hs[1];
        hwas.pb(h);
        if(pos[v].size() >= 3) {
            int to = pos[v][pos[v].size() - 3];
            while(l<to) {
                l++;
                hv[hwas[l]]--;
            }
        }
        pos[v].pb(i);
        ans += hv[h];
        hv[h]++;
        
    }
    cout<<ans;
    
    
    
}