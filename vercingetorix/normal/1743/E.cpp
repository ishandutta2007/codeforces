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
const int A  = 5001;
ll d[2][A];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const ll INF = 1e18;
    forn(i,0,2) forn(j,0,A) d[i][j]  = INF;
    vll p(2), t(2);
    forn(i,0,2) cin>>p[i]>>t[i];
    int h,s;
    cin>>h>>s;
    ll ans = INF;
    vll shot2(h+1, INF);
    forn(k1,1,A) forn(k2,1,A) {
        int dmg = p[0] + p[1] - s + (k1-1)*(p[0] - s) + (k2-1)*(p[1] - s);
        ll tm = max(k1*t[0], k2*t[1]);
        dmg = min(dmg, h);
        shot2[dmg] = min(shot2[dmg], tm);
    }
    shot2[0] = 0;
    vll shot(h+1, INF);
    forn(k1,1,A) forn(k2,1,A) {
        int dmg = (k1-1)*(p[0] - s) + (k2-1)*(p[1] - s);
        ll tm = max(k1*t[0], k2*t[1]);
        dmg = min(dmg, h);
        shot[dmg] = min(shot[dmg], tm);
    }
    forn(k1,0,A) forn(k2,0,A) {
        int dmg = (k1)*(p[0] - s) + (k2)*(p[1] - s);
        ll tm = max(k1*t[0], k2*t[1]);
        if(dmg>=h)
        
        ans = min(ans, tm);
    }
    
    forn(k,1,h+1) {
        forn(was,0,h+1)  {
            int to = min(k+was, h);
            shot[to] = min(shot[to], shot2[k] + shot[was]);
        }
    }
    forn(last,0,h+1) {
        int tot = last + p[0] + p[1] - s;
        vll ch(2, shot[last]);
        ch[0] += t[0];
        ch[1] += t[1];
        ll cand = shot[last];
        while(tot < h) {
            if(ch[0] < ch[1]) {
                cand = ch[0];
                ch[0] += t[0];
                tot += p[0] - s;
            }
            else {
                cand = ch[1];
                ch[1] += t[1];
                tot += p[1] - s;
            }
        }
        ans = min(ans, cand);
    }
    cout<<ans;
    
}