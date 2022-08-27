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
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vvi pos(5);
        forn(i,0,n) pos[2+a[i]].pb(i);
        forn(i,0,5) pos[i].pb(n);
        int best = 0;
        int al = n;
        int ar = 0;
        auto upd = [&](int l, int r) {
            int cand = 0;
            for(auto i : {0, 4}) cand += lower_bound(all(pos[i]), r) - lower_bound(all(pos[i]), l);
            if(cand > best) {
                best = cand;
                al = l;
                ar = n-r;
            }
        };
        forn(l,0,n) {
            int r = *lower_bound(all(pos[2]), l);
            if(r == l) continue;
            vi num(5,0);
            forn(i,0,5) num[i] = lower_bound(all(pos[i]), r) - lower_bound(all(pos[i]), l);
            if((num[0] + num[1])%2 == 0) {
                if(num[0] + num[4] > best) {
                    best = num[0] + num[4];
                    al = l;
                    ar = n-r;
                }
            }
            else {
                auto it1 = lower_bound(all(pos[0]), l);
                auto it2 = lower_bound(all(pos[1]), l);
                int nx = min(*it1, *it2);
                upd(nx+1,r);
                nx = -1;
                it1 = lower_bound(all(pos[0]), r);
                if(it1 != pos[0].begin()) {
                    it1--;
                    nx = max(nx, *it1);
                }
                it1 = lower_bound(all(pos[1]), r);
                if(it1 != pos[1].begin()) {
                    it1--;
                    nx = max(nx, *it1);
                }
                upd(l, nx);
            }
        }
        printf("%d %d\n", al, ar);
    }
    
    
}