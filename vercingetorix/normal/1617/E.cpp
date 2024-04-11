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

int zeratul(int m, int d10) {
    int ret = 0;
    while(m >= d10) {
        int d2 = 1;
        while(d2 < m) d2*=2;
        m = d2 - m;
        ret++;
    }
    return ret;
}

int who(int x, int bit) {
    int ret = 0;
    if(x&(1<<bit)) ret^=1;
    if(x&(1<<(bit+1))) ret^=1;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(xx,n);
    int z = 0;
    vvi a(30);
    vpi best(30,mp(-1, -1));
    for(auto x : xx) {
        if(x == 0) z++;
        else {
            int bit = 0;
            while((x&(1<<bit))==0) bit++;
            a[bit].pb(x);
            best[bit] = max(best[bit], mp(zeratul(x,1), x));
        }
    }
    int ans = -1;
    pi nums;
    forn(i,0,30) {
        if(best[i].first == -1) continue;
        if(z > 0 && best[i].first > ans) {
            ans = best[i].first;
            nums = mp(0,best[i].second);
        }
        forn(j,i+1,30) {
            if(best[j].first == -1) continue;
            if(best[i].first + best[j].first > ans) {
                ans = best[i].first + best[j].first;
                nums = mp(best[i].second, best[j].second);
            }
        }
    }
    forn(lowbit,0,30) {
        forn(vbit,lowbit+1,30) {
            vpi hard(2,mp(-1,-1));
            for(auto x : a[lowbit]) {
                hard[who(x,vbit)] = max(hard[who(x,vbit)], mp(zeratul(x, 1<<vbit), x));
            }
            if(hard[0].first != -1 && hard[1].first != -1 && ans < hard[0].first + hard[1].first) {
                ans = hard[0].first + hard[1].first;
                nums = mp(hard[0].second, hard[1].second);
            }
        }
    }
    int p1 = 0;
    int p2 = 0;
    while(xx[p1] != nums.first) p1++;
    while(xx[p2] != nums.second) p2++;
    printf("%d %d %d", p1+1,p2+1,ans);
    
    
}