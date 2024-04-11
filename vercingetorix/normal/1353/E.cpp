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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int solve(vi & a) {
    int n = a.size();
    int ans = n;
    int add = 0;
    int c1 = 0;
    forn(i,0,n) c1+=a[i];
    vi cnt(2,0);
    forn(i,0,n) {
        cnt[a[i]]++;
        c1 -= a[i];
        if(cnt[0] > cnt[1]) {
            add += cnt[1];
            cnt[0] = 0;
            cnt[1] = 0;
        }
        ans = min(ans, add+c1+cnt[0]);
    }
    ans = min(ans, add+cnt[0]);
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    char c[1000100];
    while(t--) {
        int n,k;
        scanf("%d %d\n", &n, &k);
        scanf("%s", c);
//        int ans = 0;
        vi cnt(2,0);
        vi cnt1(k,0);
        vi cntr(k,0);
        vvi pos(k);
        vvi lan(k);
        forn(i,0,n) {
            cnt[c[i]-'0']++;
            if(c[i]=='1') {
                cnt1[i%k]++;
                pos[i%k].pb(i);
                lan[i%k].pb(1);
            }
            else lan[i%k].pb(0);
            
            cntr[i%k]++;
        }
        int ans = cnt[1];
        forn(r,0,k) {
            if(cnt1[r]==0) continue;
            int cand = cnt[1] - cnt1[r];
//            int need1 = (pos[r].back()-pos[r][0])/k + 1;
            ans = min(ans, cand+ solve(lan[r]));
        }
//        forn(r,0,k) {
//            vi cnt(2,0);
//            for(int i = r; i < n; i+=k) cnt[c[i]-'0']++;
//            ans += min(cnt[0], cnt[1]);
//        }
        printf("%d\n", ans);
        
        
    }
    
}