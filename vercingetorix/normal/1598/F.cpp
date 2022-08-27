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
vs a;
int good[1<<20];
int mend[1<<20];
int ans[1<<20];
int cnt[20][1000500];
int fall[20];
int sm[1<<20];
int sum[20];
const int A = 400500;

void countp(int ss) {
    int cur = 0;
    for(auto x : a[ss]) {
        if(x=='(') cur++;
        else cur--;
        fall[ss] = min(fall[ss], cur);
        if(cur==fall[ss]) cnt[ss][cur + A]++;
    }
    sum[ss] = cur;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    char c[500500];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
        countp(i);
    }
    mend[0] = 0;
    good[0] = 1;
    ans[0] = 0;
    int res = 0;
    sm[0] = 0;
    forn(mask,0,1<<n) {
        forn(bit,0,n) {
            if((mask&(1<<bit)) == 0) {
                int nmask = mask | (1<<bit);
                sm[nmask] = sm[mask] + sum[bit];
            }
        }
    }
    forn(mask,0,1<<n) {
        if(good[mask] == 0) continue;
        forn(bit,0,n) {
            if((mask&(1<<bit)) == 0) {
                int nmask = mask | (1<<bit);
                res = max(res, ans[mask] + cnt[bit][A - sm[mask]]);
                if(fall[bit] + sm[mask] >= 0) {
                    good[nmask] = 1;
                    ans[nmask] = max(ans[nmask], ans[mask] + cnt[bit][A - sm[mask]]);
                }
            }
        }
    }
    
    forn(i,0,1<<n) res = max(res, ans[i]);
    cout<<res;
    
}