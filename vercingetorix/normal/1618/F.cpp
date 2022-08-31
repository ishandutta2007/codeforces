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

bool canto(string a, string b) {
    vi az, bz;
    forn(i,0,a.size()) if(a[i] == '0') az.pb(i);
    forn(i,0,b.size()) if(b[i] == '0') bz.pb(i);
    if(az.size() != bz.size()) return false;
    if(az.empty() && a.size() > b.size()) return false;
    forn(i,0,az.size()) if(az[i]-bz[i]!=az[0]-bz[0]) return false;
    if(!az.empty()) if(az[0]-bz[0] > 0 || az[0]-bz[0] < (int)a.size() - (int)b.size()) return false;
    return true;
}

string tos(ll x) {
    string ret;
    while(x > 0) {
        ret.pb('0' + x%2);
        x/=2;
    }
    reverse(all(ret));
    return ret;
}

void no() {
    cout<<"NO";
    exit(0);
}

void yes() {
    cout<<"YES";
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    ll x,y;
    cin>>x>>y;
    if(x==y) yes();
    if(y%2 == 0) {
        no();
    }
    string sx = tos(x);
    string sy = tos(y);
    sx.pb('1');
    if(canto(sx,sy)) yes();
    reverse(all(sx));
    if(canto(sx,sy)) yes();
    reverse(all(sx));
    sx.pop_back();
    while(sx.back() == '0') sx.pop_back();
    if(canto(sx,sy)) yes();
    reverse(all(sx));
    if(canto(sx,sy)) yes();
    no();
}