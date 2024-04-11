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
const int C = 21;
ll cnk[C][C];

ll spow(ll y, ll k) {
    ll ret = 1;
    forn(i,0,k) ret*=y;
    return ret;
}

ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}

void factorize(ll x) {
    for(ll i = 2; i*i<=x; i++) {
        if(x%i==0) {
            printf("%d ", i);
            while(x%i==0) x/=i;
        }
    }
    if(x>1) printf("%lld ", x);
    printf("\n");
}

int p1 = 4777;
int l = 1000;
int temp  =1500;
int temp2  =1510;
int wd2 = 2000;
int p0 = 3000;
int d,p;
ll st[5001];

void goplus(int i, int j, int k) {
    printf("+ %d %d %d\n", i, j, k);
    st[k] = (st[i] + st[j])%p;
}

void deg(int i, int to) {
    printf("^ %d %d\n", i, to);
    ll ret = 1;
    forn(it,0,d) ret = ret*st[i]%p;
    st[to] = ret;
}

void bd2() {
    forn(i,0,30) goplus(wd2+i, wd2+i, wd2+i+1);
}

void b0() {
    vi bits;
    forn(i,0,30) if(p&(1<<i)) bits.pb(i);
    goplus(wd2+bits[0], wd2+bits[1], p0);
    forn(i,2,bits.size()) goplus(wd2+bits[i], p0, p0);
}

void mul(int f, int to ,int k) {
    goplus(p0, f, temp);
    goplus(p0, p0, to);
    forn(i,0,30) {
        if(k&(1<<i)) {
            goplus(temp, to, to);
            k-=1<<i;
        }
        if(k==0) break;
        
        goplus(temp, temp, temp);
    }
}

void gomin(int f, int to) {
    mul(f, to, p-1);
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
    ll g = gcd (a, modulo, x, y);
    if (g != 1)
    {
        return -1;
    }
    else {
        x = (x % modulo + modulo) % modulo;
        return x;
    }
}

int getx2yd2() {
    gomin(2,3);
    int fr = 10;
    vi w;
    vvll a;
    goplus(1, 2, 4);
    goplus(1, 3, 5);
    int xk = fr++;
    int yk = fr++;
    deg(1,xk);
    deg(2,yk);
    int xkm = fr++;
    int ykm = fr++;
    int cury = fr++;
    goplus(p0,2, cury);
    gomin(xk, xkm);
    gomin(yk, ykm);
    for(int y = 1; y<=(d-1)/2; y++) {
        deg(4, l);
        deg(5, l+1);
        if(d%2 == 0) {
            goplus(l, l+1, fr);
            goplus(fr, xkm, fr);
            goplus(fr, xkm, fr);
        }
        else {
            gomin(l+1, temp2);
            goplus(l, temp2, fr);
        }
//        if(d%2==0) {
            deg(cury, temp2);
            gomin(temp2, temp2);
            goplus(fr, temp2, fr);
            goplus(fr, temp2, fr);
//        }
        w.pb(fr++);
        a.pb(vll());
        for(int dx = d-2+d%2; dx > 0; dx-=2) {
            a.back().pb(2*cnk[d][dx]*spow(y,d-dx));
        }
//        reverse(all(a));
        goplus(2, 4, 4);
        goplus(3, 5, 5);
        goplus(cury, 2, cury);
    }
    forn(i,0,a.size()) {
        forn(j,i+1,a.size()) {
            ll d = gcd(a[j][i], a[i][i]);
            ll mi = a[j][i] / d;
            ll mj = a[i][i] / d;
            forn(k,i,a.size()) {
                a[i][k] *= mi;
                a[j][k] *= mj;
                a[j][k] -= a[i][k];
            }
            mul(w[i], w[i], mi%p);
            mul(w[j], w[j], mj%p);
            gomin(w[i], temp2);
            goplus(w[j], temp2, w[j]);
        }
        //        factorize(a[i][i]);
    }
    int pp = w[a.size() - 1];
    mul(pp, pp, invmod(a.back().back(), p));
    return pp;
}

int getx2(int posx) {
    goplus(posx, p0, 1);
    goplus(p1, p0, 2);
    return getx2yd2();
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,5001) st[i] = 1;
    st[1] = 10;
    st[2] = 13;
    scanf("%d %d", &d, &p);
    bd2();
    b0();
    forn(i,0,C) cnk[i][0] = 1;
    forn(i,1,C) forn(j,1,C) cnk[i][j] = cnk[i-1][j-1] + cnk[i-1][j];
//    cout<<d;
    if(d == 2) {
        goplus(1, 2, 3); //x+y
        gomin(2, 4); // -y
        goplus(1, 4, 5); //x-y
        deg(3, 6); // (x+y)^2
        deg(5, 7);
        gomin(7,8); //-(x-y)^2
        goplus(6, 8, 9);
        mul(9, 10, invmod(4, p));
        // cout<<st[10]<<endl;
        printf("f 10\n");
        exit(0);
    }
    int sx = l++;
    int sy = l++;
    int sxy = l++;
    goplus(1, 2, sxy);
    goplus(1, p0, sx);
    goplus(2, p0, sy);
    int sx2 = l++;
    int sy2 = l++;
    int sxy2 = l++;
    goplus(p0, getx2(sx), sx2);
    goplus(p0, getx2(sy), sy2);
    goplus(p0, getx2(sxy), sxy2);
//    printf("%d\n", st[sx2]);
//    printf("%d\n", st[sy2]);
//    printf("%d\n", st[sxy2]);
    int res= l++;
    goplus(sx2, sy2, res);
    gomin(res, res);
    goplus(sxy2, res, res);
    
    mul(res, res, invmod(2, p));
    printf("f %d\n", res);
//    printf("%d\n", st[res]);
    
    
//    forn(d,3,11) {
    
//    cout<<st[pp];
//        printf("BACK %lld\n", a.back().back());
    
//    }
//    cout<<1;
    
}