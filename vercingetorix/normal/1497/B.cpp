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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        vi cnt(100500,0);
        readv(a,n);
        for(auto x : a) cnt[x%m]++;
        int ans = 0;
        forn(i,0,m) {
            if(cnt[i] > 0) {
                ans ++;
                if(i*2==m || i == 0) cnt[i] =  0;
                else {
                    int mn = min(cnt[i], cnt[m-i]);
                    cnt[i] -= mn;
                    cnt[m-i] -= mn;
                    if(cnt[i]>0) cnt[i]--;
                    if(cnt[m-i]>0) cnt[m-i]--;
                    ans+=cnt[i]+cnt[m-i];
                    cnt[i] = 0;
                    cnt[m-i] = 0;
                }
            }
        }
        printf("%d\n", ans);
        
    }
    
    
}