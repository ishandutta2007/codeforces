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
    int n;
    read(n);
    vi a(n+1,0), b(n+1, 0);
    forn(i,1,n+1) scanf("%d", &a[i]);
    forn(i,1,n+1) scanf("%d", &b[i]);
//    vi to(n+1,0);
//    forn(i,1,n+1) to[i] = i + b[i] - a[i+b[i]];
//    vi suf(n+1, n+1);
//    for(int i = n; i>=0; i--) {
//        suf[i] = to[i];
//        if(i < n) suf[i] = min(suf[i], suf[i+1]);
//    }
//    int cur = n;
//    int ans = 0;
//    while(1)  {
//        int was = cur;
//        ans++;
//        cur = suf[was];
//        if(cur == was) break;
//        if(cur == 0) break;
//    }
//    if(cur != 0) ans = -1;
    vi d(n+1, -1);
    vi p(n+1);
    d[n] = 0;
    p[n] = n;
    deque<int> q;
    q.pb(n);
    while(!q.empty()) {
        int v = q.front();
        q.pop_front();
        int mn = v + b[v] - a[v + b[v]];
        while(d[mn] == -1) {
            d[mn] = d[v] + 1;
            p[mn] = v;
            q.pb(mn++);
        }
    }
    printf("%d\n", d[0]);
    if(d[0] != -1) {
        vi ans;
        int last = 0;
        while(last!=n) {
            ans.pb(last);
            last = p[last];
        }
        reverse(all(ans));
        for(auto x : ans) printf("%d ", x);
    }
//    cout<<ans;
    
    
}