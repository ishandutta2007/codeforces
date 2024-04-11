#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const ll INF = 1e18;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,sel,k;
    scanf("%d %d %d", &n, &sel, &k);
    vll c(n);
    forn(i,0,n) scanf("%lld", &c[i]);
    forn(i,0,n) c[i] = -c[i];
    int num;
    vi tp(n,0);
    scanf("%d", &num);
    forn(i,0,num) {
        int x;
        scanf("%d", &x);
        x--;
        tp[x] += 1;
    }
    scanf("%d", &num);
    forn(i,0,num) {
        int x;
        scanf("%d", &x);
        x--;
        tp[x] += 2;
    }
    vll b, m, a, o;
    forn(i,0,n) {
        if(tp[i] == 0) o.pb(c[i]);
        else if(tp[i] == 1) m.pb(c[i]);
        else if(tp[i] == 2) a.pb(c[i]);
        else if(tp[i] == 3) b.pb(c[i]);
    }
    sort(all(b)); reverse(all(b));
    sort(all(a)); reverse(all(a));
    sort(all(m)); reverse(all(m));
    sort(all(o)); reverse(all(o));
    int as = a.size(), bs = b.size(), ms = m.size(), os = o.size();
    if(as + bs < k || ms + bs < k || 2*k > sel + min(k, bs)) {
        cout<<-1;
        return 0;
    }
    ll csum = 0;
    ll ans = -INF;
    int bp = 0;
    m.pb(-INF); a.pb(-INF); o.pb(-INF);
    while(2*k > sel + bp || bp + as < k || bp + ms < k || bp + as + ms + os < sel) csum += b[bp++];
    int pa = 0, pm = 0, po = 0;
    while(bp + pa < k) csum += a[pa++];
    while(bp + pm < k) csum += m[pm++];
    while(bp + pa + pm + po < sel) {
        ll best = max(o[po], max(a[pa], m[pm]));
        if(best == o[po]) csum += o[po++];
        else if(best == a[pa]) csum += a[pa++];
        else if(best == m[pm]) csum += m[pm++];
    }
    ans = max(ans, csum);
    for(int i = bp + 1; i <= min(bs, sel); i++) {
        csum += b[bp++];
        ll worst = INF;
        if(po>0) worst = min(worst, o[po-1]);
        if(pa>0) worst = min(worst, a[pa-1]);
        if(pm>0) worst = min(worst, m[pm-1]);
        if(pa>0 && worst == a[pa-1]) csum -= a[--pa];
        else if(pm>0 && worst == m[pm-1]) csum -= m[--pm];
        else if(po>0 && worst == o[po-1]) csum -= o[--po];
        while (pm > max(0, k - bp) && m[pm - 1] < o[po]) {
            csum -= m[--pm];
            csum += o[po++];
        }
        while (pa > max(0, k - bp) && a[pa - 1] < o[po]) {
            csum -= a[--pa];
            csum += o[po++];
        }
        while (pm > max(0, k - bp) && m[pm - 1] < o[po]) {
            csum -= m[--pm];
            csum += o[po++];
        }
        while (pa > max(0, k - bp) && a[pa - 1] < o[po]) {
            csum -= a[--pa];
            csum += o[po++];
        }
        while (pm > max(0, k - bp) && m[pm - 1] < a[pa]) {
            csum -= m[--pm];
            csum += a[pa++];
        }
        while (pa > max(0, k - bp) && a[pa - 1] < m[pm]) {
            csum -= a[--pa];
            csum += m[pm++];
        }
        ans = max(ans, csum);
    }
    cout<<-ans;

    
}