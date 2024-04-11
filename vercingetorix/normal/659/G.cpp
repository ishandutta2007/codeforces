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

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    //string s;
    ll ans = 0;
    scanf("%d",&n);
    vi h(n);
    forn(i,0,n) {
        scanf("%d",&h[i]);
        ans = ans+(ll)(h[i]-1);
    }
    ans=ans%mod;
    h.pb(1);
        h.pb(1);
    if(n==1) {
        cout<<h[0]-1;
        return 0;
    }
    
    int nn  =0;
    while(nn<n) {
        while((h[nn]==1)&&(nn<n)) nn++;
        int nnn=nn+1;
        while(h[nnn]!=1) nnn++;
        if(nn==n) break;
        ll sumspos = 0;
        //sumspos = h[nn]-1;
        ll curspos=min(h[nn],h[nn+1])-1;
        forn(i,nn+1,nnn) {
            ll lol = min(h[i], h[i-1]);
            sumspos = (sumspos + curspos*(lol-1)) % mod;
            if(i<nnn-1) curspos*=min((ll)h[i+1], lol)-1;
            curspos = curspos % mod;
        }
        int l = nn;
        //    while()
        ans=(ans+sumspos)%mod;
        while(l<nnn-1) {
            ll lol = min(h[l], h[l+1]);
            sumspos+=mod-(lol-1)*(lol-1)%mod;
            sumspos=sumspos%mod;
            ll lol2 = min(lol, (ll)h[l+2]);
            if(lol2==1) break;
            ll inv2 = invmod(lol2-1, mod);
            ll inv =  invmod(lol-1, mod);
            sumspos = (sumspos*inv)%mod;
            sumspos = (sumspos*inv2)%mod;
            sumspos = (sumspos*((ll)min(h[l+1],h[l+2])-1))%mod;
            ans = (ans + sumspos)%mod;
            l++;
        }
       // ans=(ans+sumspos)%mod;
        nn=nnn;
    }
    cout<<ans;
}