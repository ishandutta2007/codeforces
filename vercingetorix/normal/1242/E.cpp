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
bool can(ll a, ll b, ll c) {
    if(a>b) swap(a,b);
    if((a+b)%2 != c) return false;
    if(b-a+2 <= c && b+a-2 >= c) return true;
    else return false;
}

set<pi> inner_edge;

bool check(int u, int v) {
    if(v>u) swap(u,v);
    if(inner_edge.find(mp(u,v)) != inner_edge.end()) return true;
    else return false;
}

void ins(int u, int v) {
    if(v>u) swap(u,v);
    inner_edge.insert(mp(u,v));
}

void rot(vi & cur) {
    int wf = cur.back();
    for(int i=cur.size()-1; i >0; i--) cur[i] = cur[i-1];
    cur[0] = wf;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(aa,n);
    vpi a;
    forn(i,0,n) a.pb(mp(aa[i], i));
    srt(a);
    vll mn(n), mx(n);
    mn[0] = a[0].first;
    mx[0] = a[0].first;
    forn(i,1,n) {
        mx[i] = mx[i-1] + a[i].first - 2;
        if(a[i].first %2 == mn[i-1]%2) {
            if(mx[i-1] >= a[i].first - 2) mn[i] = 4;
            else mn[i] = 2 + a[i].first - mx[i-1];
        }
        else {
            if(mx[i-1] >= a[i].first-1) mn[i] = 3;
            else mn[i] = 2 + a[i].first - mx[i-1];
        }
    }
    vll b(n);
    b[n-1] = mn[n-1];
    for(int i = n-2; i>=0; i--) {
        if(b[i+1] >= mx[i]) b[i] = mx[i];
        else if(a[i+1].first >= mx[i]) b[i] = mx[i];
        else if(mx[i] - a[i+1].first +4 <= b[i+1]) b[i] = mx[i];
        else if(a[i+1].first+b[i+1]-2>=mn[i]) {
            b[i] = a[i+1].first+b[i+1]-2;
            if(b[i] + 2 <=mx[i] && can(b[i]+2, a[i+1].first, b[i+1])) b[i]+=2;
        }
        else {
            cout<<"DEAD\n";
            exit(2115);
        }
    }
    vvi ans(n);
    int cn=0;
    vi cur;
    forn(i,0,b[0]) cur.pb(cn++);
    ans[a[0].second] = cur;
    int shift = 0;
    
    forn(i,1,n) {
//        reverse(all(cur));
//        cur.pb(cur[0]);
//        reverse(all(cur));
//        cur.pop_back();
//        int wf = cur.back();
//        for(int i=cur.size()-1; i >0; i--) cur[i] = cur[i-1];
//        cur[0] = wf;
//        cur.pop_back();
//        cur.pb(wf);
//         ans.pb(cur);
//        reverse(all(cur));
        int nc = a[i].first;
        int come = (a[i].first + b[i-1] - b[i])/2;
        int comv = come+1;
        if(comv > cur.size()) {
            cout<<"EM";
        }
//        ans.pb(vi());
        if(come == 1) {
            ins(cur[b[i-1] - 1], cur[b[i-1]-2]);
        }
        
        int nv = a[i].first- comv;
        if(nv == 0) {
            if(check(cur[b[i-1]-comv], cur[b[i-1]-1])) rot(cur);
        }
        for(int j = b[i-1]-comv; j<b[i-1]; j++) ans[a[i].second].pb(cur[j]);
        vi app;
        forn(it,0,nv) app.pb(cn++);
        for(auto x : app) ans[a[i].second].pb(x);
        reverse(all(app));
        int uk = cur.back();
        cur.pop_back();
        forn(i,0,come-1) cur.pop_back();
        for(auto x : app) cur.pb(x);
        cur.pb(uk);
        if(cur.size() != b[i]) {
            cout<<"EM";
        }
    }
//    printf("%lld\n", mn[n-1]);
    printf("%d\n", cn);
    for(auto x : ans) {
        for(auto y : x) printf("%d ", y+1);
        printf("\n");
    }
    
    
}