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
        scanf("%d", &n);
        readv(a,n);
        vi neg;
        vi pos;
        int z = 0;
        forn(i,0,n) {
            if(a[i] < 0) neg.pb(a[i]);
            else if(a[i]>0) pos.pb(a[i]);
            else z++;
        }
        
        srtrev(pos);
        srt(neg);
        ll ans = -1e18;
        if(n==5) {
            ll cand = 1;
            for(auto x : a) cand*=x;
            ans = cand;
        }
        if(z>0) ans = 0;
        if(pos.size() >= 5) {
            ll cand = 1;
            forn(i,0,5) cand*=pos[i];
            ans = max(ans, cand);
        }
        if(pos.size() >= 3 && neg.size() >= 2) {
            ll cand = 1;
            forn(i,0,3) cand*=pos[i];
            forn(i,0,2) cand*=neg[i];
            ans = max(ans, cand);
        }
        if(pos.size() >= 1 && neg.size() >= 4) {
            ll cand = 1;
            forn(i,0,1) cand*=pos[i];
            forn(i,0,4) cand*=neg[i];
            ans = max(ans, cand);
        }
        reverse(all(neg));
        reverse(all(pos));
        if(neg.size() >= 5) {
            ll cand = 1;
            forn(i,0,5) cand*=neg[i];
            ans = max(ans, cand);
        }
        if(neg.size() >= 3 && pos.size() >= 2) {
            ll cand = 1;
            forn(i,0,3) cand*=neg[i];
            forn(i,0,2) cand*=pos[i];
            ans = max(ans, cand);
        }
        if(neg.size() >= 1 && pos.size() >= 4) {
            ll cand = 1;
            forn(i,0,1) cand*=neg[i];
            forn(i,0,4) cand*=pos[i];
            ans = max(ans, cand);
        }
        printf("%lld\n", ans);
    }
    
    
}