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
std::vector<int> p;

int phi (int n) {
    int result = n;
    for (auto i :p) {
        if(i*i>n) break;
        if (n % i == 0) {
            while (n % i == 0)
                n /= i;
            result -= result / i;
        }
    }
    if (n > 1)
        result -= result / n;
    return result;
}


int pow2(int k, int n) {
    if (n==0) return 1;
    if(n==1) return k;
    int x = pow2(k, n/2);
    return x*x*pow2(k, n%2);
}
void del(int n, vi & del){
    if(n==1) {
        del.pb(1);
        return;
    }
    vi razl;
int curn = n;
for(auto pr:p) {
    while(curn%pr==0) {
        razl.pb(pr);
        curn/=pr;
    }
}

if(curn>1) razl.pb(curn);
vi un;
un.pb(razl[0]);
map<int,int> deg;
for(auto pr:razl) deg[pr]++;
forn(i,1,razl.size()) {
    if(razl[i]!=razl[i-1]) un.pb(razl[i]);
}
while(un.size() <7) un.pb(1);
vi degs;
forn(i,0,7) degs.pb(deg[un[i]]);
forn(i0,0,degs[0]+1)
forn(i1,0,degs[1]+1)
forn(i2,0,degs[2]+1)
forn(i3,0,degs[3]+1)
forn(i4,0,degs[4]+1)
forn(i5,0,degs[5]+1)
    forn(i6,0,degs[6]+1)
    {
    int d = pow2(un[0],i0) *pow2(un[1],i1) *pow2(un[2],i2) *pow2(un[3],i3) *pow2(un[4],i4) *pow2(un[5],i5) *pow2(un[6],i6);
    //if(d==n) continue;
    del.pb(d);
}
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
    std::vector<bool> isp(1001,false);
    
    
    std::vector<int> mindiv(1001);
    for(int i=2; i<=1000; i++){
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
    vi num(1000001, 0);
    vll cnk(1000001, 0);
    vll inv(1000001, 0);
    vi phin(1000001, 0);
    int n,m,k,q;
    //string s;
    ll ans = 0;
    vi lol;
    //del(24, lol);
    scanf("%d %d %d", &n,&k,&q);
    vi a(n);
    forn(i,0,n) {
        scanf("%d", &a[i]);
        vi dels;
        del(a[i], dels);
        
        for(auto x: dels) {
            if(phin[x]==0) phin[x] = phi(x);
            num[x]++;
            if(num[x]==k) {
                cnk[x] = 1;
                ans = (ans+ phin[x])%mod;
            }
            if(num[x]>k) {
                ll old = cnk[x];
                int u = num[x]-1;
                cnk[x] = (cnk[x]*(u+1)) %mod;
                if(inv[u-k+1]==0) {
                    ll xx,yy;
                    gcd(u-k+1,mod,xx,yy);
                    inv[u-k+1] = (xx+mod*mod)%mod;
                }
                cnk[x] = (cnk[x]*(inv[u-k+1])) %mod;
                ans = (ans + phin[x]*(cnk[x]-old+mod)) % mod;
            }
        }
    }
    vi qu(q);
    forn(i,0,q) {
        scanf("%d", &qu[i]);
        vi dels;
        del(qu[i], dels);
        
        for(auto x: dels) {
            if(phin[x]==0) phin[x] = phi(x);
            num[x]++;
            if(num[x]==k) {
                cnk[x] = 1;
                ans = (ans+ phin[x])%mod;
            }
            if(num[x]>k) {
                ll old = cnk[x];
                int u = num[x]-1;
                cnk[x] = (cnk[x]*(u+1)) %mod;
                if(inv[u-k+1]==0) {
                    ll xx,yy;
                    gcd(u-k+1,mod,xx,yy);
                    inv[u-k+1] = (xx+mod*mod)%mod;
                }
                cnk[x] = (cnk[x]*(inv[u-k+1])) %mod;
                ans = (ans + phin[x]*(cnk[x]-old+mod)) % mod;
            }
        }
        printf("%d\n", (int) ans);
    }
    
    //cout<<ans;
}