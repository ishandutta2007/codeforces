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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vi x(3), y(3);
    forn(i,0,3) cin>>x[i]>>y[i];
    vi sx = x;
    srt(sx);
    vpi a,b;
    forn(i,0,3) if(x[i] != sx[1]) {
        a.pb(mp(x[i], y[i]));
        b.pb(mp(sx[1],y[i]));
    }
    srt(y);
    if(y.back() != y[0]) {
        a.pb(mp(sx[1], y[0]));
        b.pb(mp(sx[1], y.back()));
    }
    cout<<a.size()<<'\n';;
    forn(i,0,a.size()) {
        cout<<a[i].first<<' '<<a[i].second<<' '<<b[i].first<<' '<<b[i].second<<'\n';
    }
    
    
}