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

int cnt[20];
vpi ans;

void go(int r, int add) {
    if(r == 0) return;
    else if(r == 1) {
        cnt[add]++;
        return;
    }
    else if(r == 2) {
        cnt[add]++;
        cnt[add+1]++;
    }
    else {
        int deg =0 ;
        int tar = 1;
        while(tar < r) {
            deg ++;
            tar*=2;
        }
        if(tar == r) {
            cnt[deg+add]++;
            go(r-1, add);
            return;
        }
        go(tar-r-1, add);
        int tar2 = tar/2;
        cnt[deg-1+add]++;
        forn(i,tar2+1,r+1) {
            ans.pb(mp(i<<add, (tar-i)<<add));
            cnt[deg+add]++;
        }
        go(r-tar2, add+1);
    }
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
        int n;
        ans.clear();
        scanf("%d", &n);
        forn(i,0,20) cnt[i] = 0;
        if(n==2) {
            printf("-1\n");
            continue;
        }
        go(n,0);
        
//        forn(i,0,20) cout<<i<<' '<<cnt[i]<<'\n';
//        cout<<'\n';
        int to = 19;
        while(cnt[to]==0) to--;
        int dup = to-1;
        int z = 0;
        while(cnt[dup] < 2) dup--;
        ans.pb(mp(1<<dup, 1<<dup));
        cnt[dup] -= 2;
        cnt[dup+1]++;
        z++;
        forn(i,0,to) {
            while(cnt[i] > 1) {
                ans.pb(mp(1<<i, 1<<i));
                cnt[i]-=2;
                cnt[i+1]++;
                z++;
            }
            if(cnt[i] == 1) {
                int j = i+1;
                while(cnt[j] == 0) j++;
                if(j == to) {
                    ans.pb(mp(1<<i, 0));
                    ans.pb(mp(1<<i, 1<<i));
                    cnt[i]--;
                    cnt[i+1]++;
                }
                else {
                    ans.pb(mp(1<<i, 1<<j));
                    ans.pb(mp((1<<i)+(1<<j), (1<<j)-(1<<i)));
                    cnt[i]--;
                    cnt[i+1]++;
                    cnt[j]--;
                    cnt[j+1]++;
                }
            }
        }
        forn(i,0,z) ans.pb(mp(1<<to, 0));
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d %d\n", x.first, x.second);
    }
    
    
}