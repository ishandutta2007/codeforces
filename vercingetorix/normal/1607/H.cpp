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
vi q[2000500];
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
        ll ab = 0;
        vpi ans(n, mp(0,0));
        vpi e(n);
        set<int> touch;
        forn(i,0,n) {
            int a,b,m;
            scanf("%d %d %d", &a, &b, &m);
            int s = a+b-m;
            ab += a;
            ab -= b;
            int l = m;
            if(m>b) {
                l -= (m-b);
                ab -= (m-b);
                ans[i].first += m-b;
            }
            if(m>a) {
                l -= m-a;
                ab += m-a;
                ans[i].second += m-a;
            }
            a -= ans[i].first;
            b -= ans[i].second;
            e[i] = mp(a-l, a);
            q[s].pb(i);
            touch.insert(s);
        }
        int num = 0;
        for(auto s : touch) {
            if(q[s].size() == 0) continue;
            vector<pair<pi, int>> r;
            for(auto i : q[s]) {
                r.pb(mp(mp(e[i].second, e[i].first), i));
            }
            srt(r);
            int last = -1;
            int pt = 0;
            while(pt < r.size()) {
                int l = r[pt].first.second;
                int to = r[pt].first.first;
                int i = r[pt].second;
                if(l <= last) {
                    ans[i].first += to-last;
                    ans[i].second += last-l;
                }
                else {
                    num++;
                    ans[i].second += to-l;
                    last = to;
                }
                pt++;
            }
        }
        printf("%d\n", num);
        forn(i,0,n) printf("%d %d\n", ans[i].first, ans[i].second);
        for(auto x : touch) q[x].clear();
    }
    
    
}