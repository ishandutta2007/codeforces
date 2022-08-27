#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <set>
#include <list>
#include <map>
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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
const int MAXN = 200001;
ll n, t[4*MAXN];

void build (ll a[], int v, int tl, int tr) {
    if (tl == tr)
        t[v] = a[tl];
    else {
        int tm = (tl + tr) / 2;
        build (a, v*2, tl, tm);
        build (a, v*2+1, tm+1, tr);
    }
}

void update (int v, int tl, int tr, int l, int r, ll mult) {
    if (l > r)
        return;
    if (l == tl && tr == r)
        t[v] = (t[v]*mult)%mod;
    else {
        int tm = (tl + tr) / 2;
        update (v*2, tl, tm, l, min(r,tm), mult);
        update (v*2+1, tm+1, tr, max(l,tm+1), r, mult);
    }
}

int get (int v, int tl, int tr, int pos) {
    if (tl == tr)
        return t[v];
    int tm = (tl + tr) / 2;
    if (pos <= tm)
        return (t[v] * get (v*2, tl, tm, pos)) % mod;
    else
        return (t[v] * get (v*2+1, tm+1, tr, pos)) % mod;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,4*MAXN) t[i]=1;
    std::vector<std::vector<int>> praz(1000001);
    std::vector<bool> isp(1000001,false);
    
    std::vector<int> p;
    std::vector<int> mindiv(1000001);
    std::vector<ll> p1p(1000001);
    std::vector<ll> pp1(1000001);
    for(int i=2; i<=1000000; i++){
        int sq = (int) sqrt((double) i +1);
        bool f=false;
        for(int j=0; j<p.size();j++) {
            if(p[j] > sq) continue;
            if(i%p[j]==0){
                f=true;
                mindiv[i] = p[j];
                break;
            }
        }
        if(f) continue;
        p.push_back(i);
        isp[i]=true;
        //praz[i].push_back(i);
        mindiv[i]=i;
    }
    for(auto pri : p) {
        ll x,y, anp, anp1;
        
        gcd(pri, mod, anp,y);
        gcd(mod, pri-1, x,anp1);
        anp =(anp+mod*mod)%mod;
        anp1 =(anp1+mod*mod)%mod;
        p1p[pri] = ((pri-1)*anp)%mod;
        pp1[pri] = ((pri)*anp1)%mod;
    }
    //cout<<pp1[2]<<" "<<p1p[2]<<endl;
    int nn,m,k;
    string s;
    ll ans = 0;
    scanf("%d", &nn);
    n=nn;
    vi a(n);
    vvi divs(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
        int aa=a[i];
        if(aa==1) continue;
        int pr1=mindiv[aa];
        divs[i].pb(pr1);
        aa/=pr1;
        while(aa>1) {
            int pn = mindiv[aa];
            if(pn!=divs[i].back()) divs[i].pb(pn);
            aa/=pn;
        }
    }
    vi lastoccured(1000001, n);
    vvi nextocc(n);
    for(int i = n-1; i>=0; i--) {
        for(int j=0; j<divs[i].size(); j++) {
            int pr = divs[i][j];
            nextocc[i].pb(lastoccured[pr]);
            lastoccured[pr] = i;
        }
    }
    vb occ(1000001, false);
    ll curphi = 1;
    vll cum;
    for(int i =0; i<n; i++) {
        for(int j=0; j<divs[i].size(); j++) {
            int pr = divs[i][j];
            if(!occ[pr]) {
                occ[pr]=true;
                curphi=(curphi*p1p[pr])%mod;
            }
        }
        curphi = (curphi*a[i]) %mod;
        cum.pb(curphi);
    }
    build(cum.data(), 1, 0, n-1);
    vector<vpi> rends(n);
    int q;

    scanf("%d",&q);
        vi qans(q);
    forn(i, 0, q) {
        int l,r;
        scanf("%d %d",&l,&r);
        l--;
        r--;
        rends[l].pb(mp(r,i));
    }
    for(int i = 0; i<n; i++) {
        for(auto r:rends[i]) {
            qans[r.second] = get(1,0,n-1,r.first);
        }
        for(int j=0; j<divs[i].size(); j++) {
            int pr = divs[i][j];
            update(1, 0, n-1, i+1, nextocc[i][j]-1, pp1[pr]);
        }
        ll x,a1;
        gcd(mod,a[i],x,a1);
        a1=(a1+mod*mod)%mod;
        update(1, 0, n-1, i+1, n-1, a1);
    }
    for(auto x:qans) printf("%d\n", x);
    //cout<<ans;
}