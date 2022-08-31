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
    int d12,d13,d14,d23,d24,d34;
    int a1,a2,a3,a4,a12,a13,a14;
    cin>>d12>>d13>>d14>>d23>>d24>>d34;
    vi difs = {d12-d34, d13-d24,d14-d23};
    forn(i,0,3) forn(j,i+1,3) {
        if(abs(difs[i]) % 2 != abs(difs[j]) % 2) {
            cout<<-1;
            exit(0);
        }
    }
    a1 = 0;
    a2 =  -(difs[1] + difs[2])/2;
    a3 =  -(difs[0] + difs[2])/2;
    a4 =  -(difs[1] + difs[0])/2;
    int mn = min({a1,a2,a3,a4});
    a1-=mn;
    a2-=mn;
    a3-=mn;
    a4-=mn;
    d12 -= a1+a2;
    d13 -= a1+a3;
    d14 -= a1+a4;
    d23 -= a2+a3;
    d24 -= a2+a4;
    d34 -= a3+a4;
    if(min({d12,d13,d14,d23,d24,d34}) < 0 || d13 != d24 || d12 != d34 || d14 != d23) {
        cout<<-1;
        exit(0);
    }
    a12 = d13+d14-d12;
    a13 = d14+d12-d13;
    a14 = d12+d13-d14;
    if(a12%2 != 0 || a13%2 != 0 || a14%2 != 0) {
        cout<<-1;
        exit(0);
    }
    if(a12 < 0 || a13 <0 || a14<0) {
        cout<<-1;
        exit(0);
    }
    a12/=2;
    a13/=2;
    a14/=2;
    vs ans;
    while(a1--) ans.pb("abbb");
    while(a2--) ans.pb("babb");
    while(a3--) ans.pb("bbab");
    while(a4--) ans.pb("bbba");
    while(a12--) ans.pb("aabb");
    while(a13--) ans.pb("abab");
    while(a14--) ans.pb("abba");
    printf("%d\n", ans.size());
    forn(j,0,4) {
        string cur;
        forn(i,0,ans.size()) cur.pb(ans[i][j]);
        printf("%s\n", cur.c_str());
    }
    
    
    
}