#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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
int n;
vi x, y;
vi a,b;
const ll A = 1000000;

bool add2(int xc, int yc) {
    if(ll(xc)*xc + ll(yc)*yc > A*A*3*3/4) return false;
    else return true;
}

bool add(int xc, int yc) {
    if(ll(xc)*xc + ll(yc)*yc > A*A) return false;
    else return true;
////    if(abs(xc) > A || abs(yc) > A) return false;
//    if(xc > 0 && yc < 0) b.pb(ind);
//    else if(xc<0 && yc>0) b.pb(ind);
//    else a.pb(ind);
//    return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
//    vi x(n), y(n);
    x.resize(n);
    y.resize(n);
    forn(i,0,n) scanf("%d %d", &x[i], &y[i]);
//    forn(i,0,n) {
//        x[i] = gen()%1000000;
//        y[i] = gen()%1000000;
//        if(!add(x[i], y[i])) i--;
//    }
    vpi f;
    vi to;
    vi sg(2*n);
    
//    forn(i,0,n) {
//        add(x[i], y[i]);
//    }
    vi l;
    forn(i,0,n) l.pb(i);
    while(l.size() > 3) {
//        while(1) {
            int j1 = gen()%l.size();
            int j2 = gen()%l.size();
            if(j1 == j2) continue;
            int i1 = l[j1];
            int i2 = l[j2];
            if(add(x[i1]+x[i2],y[i1]+y[i2])) {
                swap(l[j1], l.back());
                l.pop_back();
                if(j2 == l.size()) j2 = j1;
                swap(l[j2], l.back());
                l.pop_back();
                to.pb(x.size());
                f.pb(mp(i1+1,i2+1));
                l.pb(x.size());
                x.pb(x[i1]+x[i2]);
                y.pb(y[i1]+y[i2]);
            }
            else if(add(x[i1]-x[i2],y[i1]-y[i2])) {
                swap(l[j1], l.back());
                l.pop_back();
                if(j2 == l.size()) j2 = j1;
                swap(l[j2], l.back());
                l.pop_back();
                to.pb(x.size());
                f.pb(mp(i1+1,-i2-1));
                l.pb(x.size());
                x.pb(x[i1]-x[i2]);
                y.pb(y[i1]-y[i2]);
            }
//        }
    }
//    while(1) {
//        if(a.size() > 1) {
//            int i1 = a.back();
//            a.pop_back();
//            int i2 = a.back();
//            a.pop_back();
//            if(add(x[i1]+x[i2],y[i1]+y[i2],x.size())) {
//                to.pb(x.size());
//                f.pb(mp(i1+1,i2+1));
//                x.pb(x[i1]+x[i2]);
//                y.pb(y[i1]+y[i2]);
//            }
//            else {
//                add(x[i1]-x[i2],y[i1]-y[i2],x.size());
//                to.pb(x.size());
//                f.pb(mp(i1+1,-i2-1));
//                x.pb(x[i1]-x[i2]);
//                y.pb(y[i1]-y[i2]);
//            }
//        }
//        else if(b.size() > 1) {
//            int i1 = b.back();
//            b.pop_back();
//            int i2 = b.back();
//            b.pop_back();
//            if(add(x[i1]+x[i2],y[i1]+y[i2],x.size())) {
//                to.pb(x.size());
//                f.pb(mp(i1+1,i2+1));
//                x.pb(x[i1]+x[i2]);
//                y.pb(y[i1]+y[i2]);
//            }
//            else {
//                add(x[i1]-x[i2],y[i1]-y[i2],x.size());
//                to.pb(x.size());
//                f.pb(mp(i1+1,-i2-1));
//                x.pb(x[i1]-x[i2]);
//                y.pb(y[i1]-y[i2]);
//            }
//        }
//        else break;
//    }
    forn(mask,0,1<<l.size()) {
        vi scur;
        ll sx = 0; ll sy = 0;
        forn(i,0,l.size()) {
            if(mask&(1<<i)) scur.pb(-1);
            else scur.pb(1);
            sx += x[l[i]]*scur.back();
            sy += y[l[i]]*scur.back();
            sg[l[i]] = scur.back();
        }
        if(add2(sx, sy)) break;
    }
//    for(auto xx : a) sg[xx] = 1;
//    for(auto xx : b) sg[xx] = 1;
    while(!to.empty()) {
        int i1 = f.back().first;
        int i2 = f.back().second;
        int j = to.back();
        f.pop_back();
        to.pop_back();
        sg[abs(i1)-1] = sg[j]*i1/abs(i1);
        sg[abs(i2)-1] = sg[j]*i2/abs(i2);
    }
//    int sx = 0, sy = 0;
//    forn(i,0,n) sx += sg[i]*x[i];
//    forn(i,0,n) sy += sg[i]*y[i];
//    cout<<sx<<' '<<sy<<'\n';
    forn(i,0,n) printf("%d ", sg[i]);
    
    
}