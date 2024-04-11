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
    return (x+modulo*modulo)%modulo;
}

int n;
vvi ch, nb;
vi par, v_lvl;
vvi lvl;
vi a;

long long gcd2(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd2(b, a%b);
    return gcd2(a,b%a);
}

// <num, krat>
pll dfs(int v) {
    vpll d;
    for(auto u : ch[v]) {
        d.pb(dfs(u));
    }
    if(d.empty()) return mp(a[v], 1);
    else {
        ll num = d[0].first;
        ll krat = d[0].second;
        forn(i,1,d.size()) {
            if(num==0) break;
            ll num2 = d[i].first;
            ll krat2 = d[i].second;
            krat = (krat / gcd2(krat, krat2))*krat2;
            num = (min(num, num2)/krat) * krat;
            
        }
        if(num==0) krat = 1;
        return mp(num * d.size(), krat*d.size());
    }
    
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif

    scanf("%d", &n);
    
    v_lvl.resize(n);
    par.resize(n);
    ch.resize(n);
    nb.resize(n);
    lvl.resize(n+1);
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    
    int m=1;
    lvl[1].push_back(0);
    v_lvl[0]=1;
    for(int i=1;i<n;i++){
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        nb[u].push_back(v);
        nb[v].push_back(u);
        //xp;
    }
    int l=2;
    
    while(m<n){
        for(int k=0; k<lvl[l-1].size(); k++){
            int v=lvl[l-1][k];
            for(int h=0; h<nb[v].size();h++){
                if(v_lvl[nb[v][h]]==0){
                    v_lvl[nb[v][h]]=l;
                    lvl[l].push_back(nb[v][h]);
                    m++;
                    ch[v].push_back(nb[v][h]);
                    par[nb[v][h]]=v;
                }
            }
        }
        l++;
    }
    l--;
    ll sum = 0;
    forn(i,0,n) sum+=a[i];
    std::vector<long long> lsize(l+1);
    for(int i=1; i<=l;i++) lsize[i]=lvl[i].size();
    cout<<sum-dfs(0).first;
    
}