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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
vi cnt(40,0);
vi cntpick;
vll aleft;
vll d2;

bool test(int k) {
    vi full(40,0);
    vi cnt2 = cnt;
    int pt = 39;
    int did = 0;
    for(int i = 39; i>=0; i--) {
        int curdo = min(k-did, cntpick[i] - did);
        full[i] += curdo;
        did += curdo;
        cnt2[i] -= did;
    }
    int ptx = 0;
    int bl = 39;
    while(bl >= 0 || ptx < aleft.size()) {
        while(bl>=0 && cnt2[bl] == 0) bl--;
        if(bl < 0) {
            if(ptx >= aleft.size()) break;
            ll x = aleft[ptx];
            while(pt>=0 && full[pt] == 0) pt--;
            if(pt<0) return false;
            if(x > d2[pt+1]) return false;
            full[pt]--;
            ptx++;
        }
        else if(ptx >= aleft.size() || d2[bl] >= aleft[ptx]) {
            ll x = d2[bl];
            while(pt>=0 && full[pt] == 0) pt--;
            if(pt<0) return false;
            if(x > d2[pt+1]) return false;
            full[pt]--;
            cnt2[bl]--;
        }
        else {
            if(ptx >= aleft.size()) break;
            ll x = aleft[ptx];
            while(pt>=0 && full[pt] == 0) pt--;
            if(pt<0) return false;
            if(x > d2[pt+1]) return false;
            full[pt]--;
            ptx++;
        }
    }
    return true;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    ll x;
    ll dd2 = 1;
    int bit = 0;
    
    
    forn(i,0,51) d2.pb(1ll<<i);
    forn(i,0,n) {
        scanf("%lld", &x);
        while(x > dd2) {
            bit++;
            dd2 *= 2;
        }
        if(x==dd2) cnt[bit]++;
        else aleft.pb(x);
    }
    cntpick = cnt;
    forn(i,0,39) cntpick[i+1] = min(cntpick[i+1], cntpick[i]);
    sort(all(aleft));
    reverse(all(aleft));
    if(!test(cnt[0])) {
        cout<<-1;
        return 0;
    }
    int l = 0;
    int r = cnt[0];
    while(r-l>1) {
        int m = (l+r)/2;
        if(test(m)) r=m;
        else l=m;
    }
    forn(i,r,cnt[0]+1) printf("%d ", i);
}