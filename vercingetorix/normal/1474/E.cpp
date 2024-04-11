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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n;
        scanf("%d\n", &n);
        vpi op;
        vpi ord;
        forn(i,0,n) ord.pb(mp(max(i, n-1-i), i));
        srt(ord);
        for(auto x : ord) {
            int v = x.second;
            if(v >= n-1-v) op.pb(mp(v, 0));
            else op.pb(mp(v, n-1));
        }
        op.pop_back();
//        cout<<1<<endl;
        vi ans;
        ll res = 0;
        forn(i,0,n) ans.pb(i);
        reverse(all(op));
        for(auto x : op) {
            int u = x.first;
            int v = x.second;
            res += ll(u-v)*ll(u-v);
            swap(ans[u], ans[v]);
        }
        reverse(all(op));
        printf("%lld\n", res);
        forn(i,0,n) printf("%d ", 1+ans[i]);
        printf("\n");
        printf("%d\n", n-1);
        for(auto x : op) printf("%d %d\n", x.first+1, x.second+1);
        
    }
    
}