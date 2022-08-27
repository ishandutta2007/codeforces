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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll n,k,m;
    scanf("%lld %lld %lld", &n, &k, &m);
    readv(a, n);
    if(k>=n) {
        forn(i,0,n) if(a[i]!=a[0]) {
            if(a[0] != a.back()) {
                printf("%lld\n", n*m);
            }
            else {
                ll cnt = 2;
                int l = 1;
                int r = n-2;
                while(a[0] == a[l]) l++,cnt++;
                while(a[0] == a[r]) r--,cnt++;
                if(cnt >= k) printf("%lld\n", n*m-k*(m-2));
                else printf("%lld\n", n*m);
            }
            return 0;
        }
        printf("%lld\n", (n*m)%k);
        return 0;
    }
    deque<pi> na;
    ll nn = n;
    forn(i,0,n) {
        if(na.empty() || na.back().first != a[i]) na.pb(mp(a[i],1));
        else {
            na.back().second++;
            if(na.back().second == k) {
                na.pop_back();
                nn -= k;
            }
        }
    }
    n = nn;
    if(na.empty()) {
        printf("0\n");
        return 0;
    }
    a.clear();
    for(auto x : na) forn(i,0,x.second) a.pb(x.first);
    int l = n;
    int r = n;
    while(1) {
        if(na.empty()) {
            vi nna;
            forn(i,0,l) nna.pb(a[i]);
            forn(i,n-r,n) nna.pb(a[i]);
            nn = l+r;
            n = l+r;
            a = nna;
            forn(i,0,n) {
                if(na.empty() || na.back().first != a[i]) na.pb(mp(a[i],1));
                else {
                    na.back().second++;
                    if(na.back().second == k) {
                        na.pop_back();
                        nn -= k;
                    }
                }
            }
            printf("%lld\n", nn);
            return 0;
        }
        else if(na.size() == 1) {
            int x = na[0].first;
            ll cnt = (m-2)*ll(na[0].second);
            while(l>0 && a[l-1] == x) {
                cnt++;
                l--;
            }
            while(r>0 && a[n-r] == x) {
                cnt++;
                r--;
            }
            cnt = cnt%k;
            if(cnt!=0) {
                printf("%lld\n", cnt+l+r);
                return 0;
            }
            else {
                na.clear();
                vi nna;
                forn(i,0,l) nna.pb(a[i]);
                forn(i,n-r,n) nna.pb(a[i]);
                nn = l+r;
                n = l+r;
                a = nna;
                forn(i,0,n) {
                    if(na.empty() || na.back().first != a[i]) na.pb(mp(a[i],1));
                    else {
                        na.back().second++;
                        if(na.back().second == k) {
                            na.pop_back();
                            nn -= k;
                        }
                    }
                }
                printf("%lld\n", nn);
                return 0;

            }
        }
        else {
            if(na.back().first == na[0].first && na.back().second + na[0].second >= k) {
                int tr = na.back().second;
                int tl = k - tr;
                l -= tr;
                r -= tl;
                na.pop_back();
                na[0].second -= tl;
                if(na[0].second == 0) na.pop_front();
            }
            else {
                ll inone = 0;
                for(auto x : na) inone += x.second;
                printf("%lld\n", (m-2)*inone +l +r);
                return 0;
            }
        }
    }
    
}