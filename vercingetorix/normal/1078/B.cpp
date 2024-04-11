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
int cnt[101];
int d[101][10001];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    for(auto x : a) cnt[x]++;
    int ans = 0;
    forn(i,1,101) {
        forn(tk,1,cnt[i]+1) {
            int ret = cnt[i];
            int dif = 0;
            if(ret != tk) dif++;
            cnt[i] = 0;
//            cnt[i] -= tk;
            forn(it,0,tk+1) forn(sum,0,tk*i+1) d[it][sum] = 0;
            d[0][0] = 1;
            forn(cur,1,101) {
                if(cnt[cur] > 0) dif++;
                forn(jnum,0,cnt[cur]) {
                    for(int was = tk-1; was >= 0; was--) forn(sum,0,tk*i+1-cur) {
                        d[was+1][sum+cur] |= d[was][sum];
                    }
                }
            }
            int bad = 0;
            forn(tr,1,tk+1) if(d[tr][tr*i] != 0) bad = 1;
            if(bad == 0) {
                int cand = tk;
                if(dif == 1) cand = n;
                ans = max(ans, cand);
            }
            cnt[i] = ret;
//            cnt[i] += tk;
        }
    }
    cout<<ans;
    
    
}