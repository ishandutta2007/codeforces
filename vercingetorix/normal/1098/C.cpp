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
    ll n,s;
    cin>>n>>s;
    if(s < 2*n-1 || s > n*(n+1)/2) {
        cout<<"No\n";
        exit(0);
    }
    int l = 0;
    int r = n-1;
    while(r-l > 1) {
        int m = (r+l)/2;
        ll left = n;
        ll dm = 1;
        int lev = 1;
        ll cand = 0;
        while(left > 0) {
            ll tk = min(left, dm);
            cand += tk*lev;
            dm*=m;
            left -= tk;
            lev++;
        }
        if(cand <= s) r = m;
        else l = m;
    }
    ll cur = 0;
    vll cnt(n+1, 0);
    ll left = n;
    ll dm = 1;
    int lev = 1;
    while(left > 0) {
        ll tk = min(left, dm);
        cur += tk*lev;
        cnt[lev] = tk;
        dm*=r;
        left -= tk;
        lev++;
    }
    for(int l = n; l>=1; l--) {
        while(cnt[l] > 1 && cur < s) {
            if(lev - l <= s - cur) {
                cnt[l]--;
                cnt[lev]++;
                cur += lev-l;
                lev++;
            }
            else {
                cnt[l]--;
                cnt[l+s-cur]++;
                cur = s;
            }
        }
    }
    int vn = 1;
    vvi vl(n+1);
    forn(l,1,n+1) {
        forn(it,0,cnt[l]) vl[l].pb(vn++);
    }
    printf("Yes\n");
    forn(l,2,n+1) {
        forn(i,0,vl[l].size()) {
            printf("%d ", vl[l-1][i/r]);
        }
    }
//    cout<<r;
//    cout<<r;
//    cout<<r;
    
    
}