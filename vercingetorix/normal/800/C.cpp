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
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

ll gcd (ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

ll invmod(ll a, ll modulo) {
    ll x, y;
    gcd(a, modulo, x, y);
    return (x%modulo+modulo)%modulo;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    if(m==1) {
        cout<<1<<endl<<0;
        return 0;
    }
    vi ban(m,0);
    forn(i,0,n) {
        int x;
        scanf("%d", &x);
        ban[x] = 1;
    }
    vi div;
    forn(i,1,m+1) {
        if(m%i == 0) div.pb(i);
    }
    vvi al(m+1);
    vi cnt(m+1,0);
    vi nx(m+1,m);
    if(!ban[0]) {
        al[m].pb(0);
        cnt[m]++;
    }
    for(int v = m-1; v > 0; v--) {
        if(m%v != 0) continue;
        int lo = m/v;
        forn(i,1,m/v+1) {
            if(gcd(i,lo) == 1 && !ban[v*i]) {
                al[v].pb(v*i);
                cnt[v]++;
            }
            if(m%(v*i) != 0) continue;
            if (i==1) continue;
            int cand = v*i;
            if(cnt[cand] > cnt[nx[v]]) {
                nx[v] = cand;
            }
        }
        cnt[v] += cnt[nx[v]];
    }
//    cout<<cnt[1];
    vi ans = al[1];
    int curd = 1;
    while(1) {
        curd = nx[curd];
        for(auto x : al[curd]) ans.pb(x);
        if(curd == m) break;
    }
    printf("%d\n", ans.size());
    for(int i = ans.size()-1; i>0; i--) {
        int v = ans[i];
        int u = ans[i-1];
        int d = gcd(v,u);
        d = gcd(d,m);
        ans[i] = (v/d * invmod(u/d, m/d)) % m;

    }
    for(auto x : ans) printf("%d ", x);
    
}