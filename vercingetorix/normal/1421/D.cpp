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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(iaff,0,t) {
        int x,y;
        scanf("%d %d", &x, &y);
        readv(vx,6);
        vll c;
        forn(i,0,6) c.pb(vx[i]);
        ll ans = 5e18;
        ll pp = 0;
        if(x>0) pp += c[5]*x;
        else pp -= c[2]*x;
        if(y>0) pp += c[1]*y;
        else pp -= c[4]*y;
        ans = min(ans,pp);
        pp = 0;
        if (x-y > 0) pp += c[5]*(x-y);
        else pp += c[2]*(y-x);
        if(y>0) pp += c[0] * y;
        else pp-=c[3]*y;
        ans = min(ans,pp);
        pp = 0;
        if (y-x > 0) pp += c[1]*(y-x);
        else pp += c[4]*(x-y);
        if(x>0) pp += c[0] * x;
        else pp-=c[3]*x;
        ans = min(ans,pp);
        cout<<ans<<endl;
    }
}