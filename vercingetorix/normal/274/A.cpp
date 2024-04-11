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
    readv(a,n);
    map<int, vi> q;
    for(auto x : a) {
        int m = x;
        if(k==1) q[m].pb(x);
        else {
            while(m%k == 0) {
                m/=k;
            }
            q[m].pb(x);
        }
    }
    if(k==1) cout<<q.size();
    else {
        int ans = 0;
        for(auto x : q) {
            vi b = x.second;
            srt(b);
            vpi c;
            int r = 0;
            while(r < b.size()) {
                int r2 = r+1;
                while(r2 < b.size() && b[r2] == b[r]) r2++;
                c.pb(mp(b[r], r2-r));
                r = r2;
            }
            vi d(2,0);
            d[1] = c[0].second;
            forn(i,1,c.size()) {
                vi nd(2,0);
                nd[0] = max(d[0], d[1]);
                nd[1] = d[0] + c[i].second;
                if(c[i].first / c[i-1].first != k) nd[1] = max(nd[1], d[1]+c[i].second);
                d = nd;
            }
            ans += max(d[0], d[1]);
        }
        cout<<ans;
    }
    
}