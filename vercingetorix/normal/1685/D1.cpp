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
vi col, done, q, p;
int n;

void go(int v) {
    done[col[v]] = 1;
    int cur = v;
    do {
        if(cur +1 < n && done[col[cur+1]] == 0) go(cur+1);
        if(cur -1 >= 0 && done[col[cur-1]] == 0) go(cur-1);
        q.pb(cur);
        cur = p[cur];
    } while(cur != v);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        scanf("%d", &n);
        readv(pp,n);
        p = pp;
        vi vis(n, 0);
        forn(i,0,n) p[i]--;
        int cnum = 0;
        col = vi(n);
        forn(i,0,n) if(vis[i] == 0) {
            col[i] = cnum;
            int cur = p[i];
            vis[i] = 1;
            while(cur != i) {
                vis[cur] = 1;
                col[cur] = cnum;
                cur = p[cur];
            }
            cnum++;
        }
        q.clear();
        done = vi (cnum, 0);
        go(0);
        
//        vi cnt(cnum, 0);
//        int dif = 0;
//        int r = 0;
//        int len = n;
//        int s = 0;
//        forn(l,0,n) {
//            while(r < n && dif < cnum) {
//                cnt[col[r]]++;
//                if(cnt[col[r]] == 1) dif++;
//                r++;
//            }
//            if(dif < cnum) break;
//            if(r-l < len) {
//                len = r-l;
//                s = l;
//            }
//            cnt[col[l]]--;
//            if(cnt[col[l]] == 0) dif--;
//        }
//        vi taken(cnum, 0);
//        vi q;
//        forn(i,s,s+len) {
//            if(taken[col[i]] == 0) {
//                q.pb(i);
//                int cur = p[i];
//                while(cur != i) {
//                    q.pb(cur);
//                    cur = p[cur];
//                }
//                taken[col[i]] = 1;
//            }
//        }
        reverse(all(q));
//        q = {0,7,6,5,4,3,2,1};
        
//        int ans = 0;
//        forn(i,0,n) ans += abs(q[i] - p[q[(i+1)%n]]);
//        printf("%d\n", ans);
        for(auto x : q) printf("%d ", x + 1);
        printf("\n");
    }
    
    
}