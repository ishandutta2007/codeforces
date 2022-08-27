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

int ask(const vll & a) {
    if(a.empty()) return 0;
    printf("%d", a.size());
    for(auto x : a) printf(" %lld", x);
    printf("\n");
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    if(ret<0) exit(0);
    else return ret;
}

ll m = 10004205361450474;
//ll mk = 10000;
void go(ll l, ll r, ll mk, int k) {
    ll s = 0;
    forn(i,0,k-1) s = s*(mk+1)+mk;
    vll a;
    for(ll x = l + s; x <=r; x += s+1) a.pb(x);
    int ret = ask(a);
    int len = a.size();
    if(ret < len) r = a[ret] - 1;
    if(ret>0) l = a[ret-1] + 1;
    go(l, r, mk, k-1);
}



ll getm3(ll mk) {
    ll m3 = 0;
    forn(i,0,3) {
        m3=m3*(mk+1) + mk;
        mk = 10000;
    }
    return m3;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    ll mk = 10000;
    ll m4 = 0;
    forn(i,0,4) m4=m4*(mk+1) + 10000;
    int ret = ask(vll(1,m-m4));
    if(ret == 1) go(m-m4+1, m, 10000, 4);
    else {
        ret = ask(vll(1,2046));
        if(ret == 0) {
            ret = ask(vll(1,6));
            if(ret == 0) {
                ret = ask({2});
                if(ret == 0) ask({1});
                else ask({3,4,5});
            }
            else {
                vll a={14,30,62,126,254,510,1022};
                ret = ask(a);
                ll l = 7;
                ll r = 2046;
                if(ret < 7) r = a[ret] - 1;
                if(ret>0) l = a[ret-1] + 1;
                a.clear();
                for(ll i=l; i<r+1;i++) a.pb(i);
                ask(a);
            }
        }
        else {
            ll m3 = 0;
            forn(i,0,2) m3=m3*(mk+1) + 10000;
            vll a;
            vll b;
            ll last = 2047;
            while(b.size() < 2047) {
                last = last + min(last, 10000ll);
                b.pb(last);
                last++;
            }
            ll f = last + 10000;
            a.pb(f);
            for(ll i = f + m3+1; i < m-m4; i+= m3+1) {
                a.pb(i);
            }
            ret = ask(a);
            ll l = 2047;
            ll r = m-m4-1;
            if(ret < 2047) r = a[ret] - 1;
            if(ret > 0) l = a[ret-1] + 1;
            if(ret == 0) {
                ret = ask(b);
                if(ret < 2047) r = b[ret] - 1;
                if(ret > 0) l = b[ret-1] + 1;
                a.clear();
                for(ll i=l; i<r+1;i++) a.pb(i);
                ask(a);
            }
            else go(l,r,10000,2);
        }
    }
//    cout<<m-m4<<endl;
//    ll mm = m - m4;
//    while(getm3(mk) + mk-1 >= mm) mk--;
//    cout<<mk<<endl;
    
//    cout<<mm-m3<<endl;
//    ll mmm = mm - m3;
//    ll m2 = 0;
//    forn(i,0,2) m2=m2*(mk+1) + 10000;
//    cout<<mmm-m2<<endl;
    
}