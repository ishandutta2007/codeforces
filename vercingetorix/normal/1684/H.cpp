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

bool check(vi & a, int tar) {
    int cur = 0;
    for(auto x : a) cur += x;
    int l = 0;
    vpi ans;
    while(l < a.size()) {
        int run = a[l];
        int r = l+1;
        while(r < a.size() && run + cur <= tar) {
            cur += run;
            run = run*2 + a[r++];
        }
        ans.pb(mp(l+1, r));
        l = r;
    }
    if(cur == tar) {
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d %d\n", x.first, x.second);
        return true;
    }
    return false;
}

bool checkr(vi & a, int tar) {
    int cur = 0;
    for(auto x : a) cur += x;
    int r = a.size() - 1;
    vpi ans;
    while(r>=0) {
        int l = r-1;
        int d2 = 2;
        while(l>=0 && r-l < 21 && a[l]*(d2-1) + cur <= tar) {
            cur += a[l]*(d2-1);
            l--;
            d2 *= 2;
        }
        ans.pb(mp(l+2, r+1));
        r = l;
    }
    if(cur == tar) {
        reverse(all(ans));
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d %d\n", x.first, x.second);
        return true;
    }
    return false;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        string s;
        cin>>s;
        vi a;
        forn(i,0,s.size()) a.pb(s[i]-'0');
        int sum = 0;
        for(auto x : a) sum += x;
        if(sum == 0) {
            printf("-1\n");
            continue;
        }
        int d2 = 1;
        while(d2 < sum) d2 *= 2;
        if(check(a, d2)) continue;
        if(check(a, 2*d2)) continue;
        if(check(a, 4*d2)) continue;
        if(checkr(a, d2)) continue;
        if(checkr(a, 2*d2)) continue;
        if(checkr(a, 4*d2)) continue;
        printf("-1\n");
    }
    
    
}