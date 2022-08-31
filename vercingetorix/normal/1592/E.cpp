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

int last[1100500];
int pref[1100500];
vi touch;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    int ans = 0;
    pref[0] = a[0];
    forn(i,1,n) pref[i] = pref[i-1]^a[i];
    forn(i,0,1100500) last[i] = n;
    forn(old,0,20) {
        int bm = 0;
        forn(i,old,20) bm|=1<<i;
        int l = 0;
        while(l < n) {
            while(l<n && (a[l]&(1<<old)) == 0) l++;
            if(l==n) break;
            int r = l+1;
            while(r<n && (a[r]&(1<<old))) r++;
            int bef = 0;
            if(l>0) bef = pref[l-1]&bm;
            touch.clear();
            touch.pb(bef);
            last[bef] = l-1;
            forn(i,l,r) {
                int cur = bm&pref[i];
                ans = max(ans, i - last[cur]);
                last[cur] = min(i, last[cur]);
                touch.pb(cur);
            }
            l = r;
            for(auto x : touch) last[x] = n;
        }
    }
    cout<<ans;
    
}