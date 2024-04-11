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

int gcd (int a, int b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

class stree {
public:
    vi t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = gcd(t[v*2], t[v*2+1]);
        }
    }
    
    int get (int v, int tl, int tr, int l, int r) {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        return  gcd(
                 get (v*2, tl, tm, l, min(r,tm)),
                 get (v*2+1, tm+1, tr, max(l,tm+1), r)
                 );
    }
};
const int A = 100001;
ll cd[A];
ll pcd[A];
ll pref[A];

ll solve(ll p , ll n, ll k, ll b) {
    if(k >= p || b>=p) {
        return solve(p, n, k%p, b%p) + (k/p*(n-1)+b/p*2)*n/2;
    }
    else if(k == 0) return 0;
    else {
        return solve(k, (k*n+b)/p, p, (k*n+b)%p);
    }
}

ll cbelow(ll p , ll n, ll k, ll b) {
    ll mx = 0;
    if(b <= 0) mx = (k-b)/k;
    if(mx >= n) return 0;
    n-=mx;
    b += mx*k;
    return solve(p, n, k ,b);
}

ll get(int l, int r, ll m) {
    ll mw = m;
    if(r == l) {
        ll mn = (m+l-1) / l;
        if(cd[l] >= mn) {
//            cout<<m<<' '<<l<<' '<<r<<' '<<cd[l]<<' '<<cd[r]<<' '<<(cd[l]-mn+2)*(cd[l]-mn+1)/2<<endl;
            return (cd[l]-mn+2)*(cd[l]-mn+1)/2;
        }
    }
    m -= pref[r-1] - pref[l];
    // cd[l] >= a >= 1
    // cd[r] >= b >= 1
    // a*l + b*r >= m
    ll c1 = cbelow(l, cd[r], r, m-1 - cd[r]*r);
    ll c2 = cbelow(l, cd[r], r, m-1 - cd[r]*r - cd[l]*l);
    ll ret2 =  c1 - c2;
    return cd[r] * cd[l] - ret2;
//    ll a = cd[l];


    ll b = 1;
    ll cur = cd[l]*l + r;
    ll ret = 0;
    for(int a = cd[l]; a >= 1; a--) {
        while(b < cd[r] && cur < m) {
            b++;
            cur+=r;
        }
        if(cur>=m) ret += cd[r] + 1 - b;
        else break;
        cur -= l;
    }
//    if(ret > 0) {
//        cout<<mw<<' '<<l<<' '<<r<<' '<<cd[l]<<' '<<cd[r]<<' '<<ret<<endl;
//    }
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(a,n);
    stree st;
    st.build(a, 1, 0, n-1);
    forn(s,0,n) {
        int e = s;
        while(e < n) {
            int l = e;
            int r = n;
            int def = st.get(1, 0, n-1, s, e);
            while(r-l > 1) {
                int m = (r+l)/2;
                if(st.get(1, 0, n-1, s, m) == def) l = m;
                else r = m;
            }
            cd[def] += r-e;
            e = r;
        }
    }
//    vi b;
//    forn(i,0,A) {
//        if(cd[i] > 0) cout<<i <<' '<<cd[i]<<endl;
//        forn(it,0,cd[i]) b.pb(i);
//    }
//    vi c;
//    forn(l,0,b.size()) forn(r,l,b.size()) {
//        int cur = 0;
//        forn(k,l,r+1) cur+=b[k];
//        c.pb(cur);
//    }
//    srt(c);
//    cout<<c[(c.size()+1) / 2 - 1];
    forn(i,1,A) pref[i] = pref[i-1] + ll(cd[i])*i;
    forn(i,1,A) pcd[i] = pcd[i-1] + cd[i];
    ll k = ll(n)*(n+1)/2;
    k = k*(k+1)/2;
    ll lv = 1;
    ll rv = pref[A-1] + 1;
    while(rv-lv > 1) {
        ll m = (rv+lv) / 2;
        ll cnt = 0;
        forn(l,1,A) {
            if(cd[l] == 0) continue;
            int r1 = lower_bound(pref, pref+A, m + pref[l-1]) - pref;
            int r2 = lower_bound(pref, pref+A, m + pref[l]) - pref;
            if(r2 < A) {
//                cout<<m<<' '<<l<<"+ "<<r2<< ' '<< cd[l] * (pcd[A-1] - pcd[r2])<<endl;
                cnt += cd[l] * (pcd[A-1] - pcd[r2]);
            }
            forn(r,r1,r2+1) cnt += get(l, r, m);
            
        }
//        cout<<m<<' '<<cnt<<endl;
        if(cnt > k -(k+1)/2) lv = m;
        else rv = m;
    }
    cout << lv;
    
    
}