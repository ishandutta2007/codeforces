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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair

class stree {
public:
    vi t;
    int s;
    void build (int n) {
        t = vi(4*n,0);
    }
    
    void set (int v, int tl, int tr, int pos) {
        if (pos == tl && tr == pos) {
            t[v] = 1;
        }
        else {
            int tm = (tl + tr) / 2;
            if(pos<=tm) set(v*2, tl, tm, pos);
            else set(v*2+1, tm+1, tr, pos);
            t[v] = t[v*2] + t[v*2+1];
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if(l>r) return 0;
        if (tl == l && tr == r)
            return t[v];
        int tm = (tl + tr) / 2;
        return get (v*2, tl, tm, l, min(r,tm)) + get(v*2+1, tm+1, tr, max(l,tm+1), r);
    }
};

vll nfac(1,1);
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll i2 = (mod+1)/2;
    for(ll i = 1; i<= 1000000; i++) nfac.pb((nfac[i-1]*i)%mod);
    int n;
    scanf("%d", &n);
    readv(a,n);
    ll cnt = 0;
    ll cur = 1;
    stree st;
    st.build(n+1);
    ll ans = 0;
    for(int i = n-1; i>=0; i--) {
        ll c2 = ((cnt*(cnt-1))/2)%mod;
        ll num = st.get(1, 0, n, 0, a[i]-1);
        st.set(1, 0, n, a[i]);
        ans = (ans+num*cur)%mod;
        cur = (cur+num*nfac[cnt])%mod;
        ll h = ((num*(num-1))/2)%mod;
        num = (num*i2)%mod;
        num = (num * c2) % mod;
        ans = (ans + num * nfac[cnt]) % mod;
        ans = (ans + h*nfac[cnt]) % mod;
        cnt++;
    }
    cout<<ans;
    
}