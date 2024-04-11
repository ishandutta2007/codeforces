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

ll cnk(ll n, ll k) {
    if (k>n) return 0;
    if(2*k > n) k = n-k;
    ll ans = 1;
    forn(i,0,k) {ans = (ans * (n-i)) % mod; ans = (ans * invmod(i+1, mod))%mod;}
    return ans;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d", &n);
    vi a(n);
    vpi q;
    forn(i,0,n) {
        scanf("%d", &a[i]);
        if(a[i]>0) {
            q.pb(mp(a[i], i));
        }
    }
    sort(all(q));
    if(q.size() == 0) {
        ll ans = 1;
        forn (i, 0, n-1) {
            ans = (ans*2) % mod;
        }
        cout<<ans<<endl;
        return 0;
    }
    ll anstot = 0;
    forn(alf, 0, 2) {
        if (q[0].first == 1) alf++;
        ll ans = 1;
        forn (i, 0, q[0].first - 2) ans = (ans*2)%mod;
        int l,r;
        l = q[0].second;
        r = q[0].second;
        int cur = q[0].first;
        int s = q[0].second;
        if (alf == 0) r += q[0].first - 1;
        else l -= q[0].first - 1;
        forn(i, 1, q.size()) {
            int nx = q[i].first;
            int pos = q[i].second;
            if (pos > s) {
                if (r >= pos) {
                    ans = 0;
                    break;
                }
                if (pos - r > nx - cur) {
                    ans = 0;
                    break;
                }
                ans = (ans * cnk(nx - cur - 1, pos - r - 1)) % mod;
                r = pos;
                cur = nx;
                l = pos - nx + 1;
            }
            else {
                if (l <= pos || l - pos > nx - cur) {
                    ans = 0;
                    break;
                }
                ans = (ans * cnk(nx-cur-1, l-pos-1)) % mod;
                l = pos;
                cur = nx;
                r = pos + nx - 1;
            }

            
        }
        if(l<0 || r>n-1) ans =0;
        else ans = (ans * cnk(n - cur, l)) % mod;
        anstot += ans;
    }
    anstot = (anstot) % mod;
    cout<<anstot;
}