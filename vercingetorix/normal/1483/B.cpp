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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vpi d;
        forn(i,0,n) d.pb(mp(i,i));
        int last = -1;
        vi ans;
        vi nxt(n);
        vi prev(n);
        forn(i,0,n) nxt[i] = i+1;
        forn(i,0,n) prev[i] = i-1;
        while(d.size() > 1) {
            vpi nd;
            for(auto x : d) {
                int l = x.first;
                int r = x.second;
                if(last == -1) {
                    nd.pb(x);
                    last = a[r];
                }
                else {
                    int tr = gcd(last, a[l]);
                    if(tr == 1) {
                        ans.pb(l);
                        last = -1;
                        if(prev[l] != -1) nxt[prev[l]] = nxt[l];
                        if(nxt[l] != n) prev[nxt[l]] = prev[l];
                        if(r>l) {
                            nd.pb(mp(nxt[l],r));
                            last = a[r];
                        }
                    }
                    else {
                        if(nd.empty()) {
                            nd.pb(x);
                            last = a[r];
                        }
                        else {
                            nd.back().second = r;
                            last = a[r];
                        }
                    }
                }
            }
            d = nd;
        }
        int l = d[0].first;
        int r = d[0].second;
        while(l!=r && gcd(a[l], a[r]) == 1) {
            ans.pb(l);
            l = nxt[l];
        }
        if(l==r && a[l] == 1) ans.pb(l);
        printf("%d", ans.size());
        for(auto x : ans) printf(" %d", x+1);
        printf("\n");
        
    }
    
}