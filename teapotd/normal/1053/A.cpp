#define _USE_MATH_DEFINES/////////////////////////////////////////////////////
#include <bits/stdc++.h>//////////////////////////////////////////////////////
#ifdef LOC////////////////////////////////////////////////////////////////////
#include "debuglib.h"/////////////////////////////////////////////////////////
#else/////////////////////////////////////////////////////////////////////////
#define deb(...)//////////////////////////////////////////////////////////////
#define DBP(...)//////////////////////////////////////////////////////////////
#endif////////////////////////////////////////////////////////////////////////
#define x first///////////////////////////////////////////////////////////////
#define y second//////////////////////////////////////////////////////////////
#define mp make_pair//////////////////////////////////////////////////////////
#define pb push_back//////////////////////////////////////////////////////////
#define sz(x)int((x).size())//////////////////////////////////////////////////
#define each(a,x)for(auto&a:(x))///////////////// by teapotd /////////////////
#define all(x)(x).begin(),(x).end()///////////////////////////////////////////
#define rep(i,b,e)for(int i=(b);i<(e);i++)////////////////////////////////////
using namespace std;using namespace rel_ops;using ll=int64_t;using Pii=pair///
<int,int>;using ull=uint64_t;using Vi=vector<int>;void run();int main(){cin.//
sync_with_stdio(0);cin.tie(0);cout<<fixed<<setprecision(10);run();return 0;}//
//--------------------------------------------------------------------------//

int uplg(int n) { return 32-__builtin_clz(n); }
int uplg(ll n)  { return 64-__builtin_clzll(n); }
int cmp(double a, double b, double eps=1e-9) { return (a>b+eps) - (a+eps<b); }

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll c = a%b;
        a = b;
        b = c;
    }
    return a;
}

void run() {
    ll n, m, k;
    cin >> n >> m >> k;
    ll area = n*m*2;

    if (area % k) {
        cout << "NO\n";
        return;
    }

    bool odd = (k%2);
    if (!odd) k /= 2;

    ll g = gcd(k, n);
    k /= g;

    ll a = n/g;
    ll b = m/k;

    if (odd) {
        if (a < n) a *= 2;
        else b *= 2;
    }

    cout << "YES\n";
    cout << "0 0\n";
    cout << a << " 0\n";
    cout << "0 " << b << "\n";
}