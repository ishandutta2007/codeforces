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

ll get(const vi & a) {
    ll ret = 1;
//    int eq = 1;
    int z = 2;
    for(auto x : a) {
        if(x<0) return 0;
        if(x>18) return 0;
        if(x>=10) z= 0;
//        if(x%2==1) eq = 0;
        ret *= min(x+1, 19-x);
    }
    ret-=z;
    return ret;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int n;
        scanf("%d", &n);
        vi a;
        ll ans = 0;
        while(n>0) {
            a.pb(n%10);
            n/=10;
        }
        int l = a.size();
        vi d2(1,1);
        forn(i,0,10) d2.pb(d2.back()*2);
        if(l<=2) {
            ans += get(a);
        }
        else {
            forn(mask,0,d2[l-2]) {
                vi b = a;
                forn(i,0,l-2) {
                    if(mask & d2[i]) {
                        b[i] += 10;
                        b[i+2] --;
                    }
                }
                ans += get(b);
            }
            
        }
        printf("%lld\n", ans);
    }
    
    
}