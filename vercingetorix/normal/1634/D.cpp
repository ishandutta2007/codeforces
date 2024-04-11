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

int ask(int i, int j, int k) {
    printf("? %d %d %d\n", i+1, j+1, k+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        int a=0, b=1,c=2;
        int cur = ask(a,b,c);
        forn(d,3,n) {
            int abd = ask(a,b,d);
            int bcd = ask(b,c,d);
            if(abd >= bcd) {
                if(abd > cur) {
                    c = d;
                    cur = abd;
                }
            }
            else {
                if(bcd>cur) {
                    a= d;
                    cur = bcd;
                }
            }
        }
        int pt = 0;
        while(pt == a || pt == b || pt == c) pt++;
        vi ans;
        if(ask(a,b,pt) < cur) ans.pb(c);
        if(ask(a,c,pt) < cur) ans.pb(b);
        if(ask(c,b,pt) < cur) ans.pb(a);
        if(ans.size() < 2) ans.pb(ans.back());
        printf("! %d %d\n", ans[0]+1, ans[1]+1);
        fflush(stdout);
    }
    
    
}