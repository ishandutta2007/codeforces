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
void no() {
    cout<<0;
    exit(0);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d\n", &n);
    char c[100];
    set<int> l;
    set<int> r;
    set<int> f;
    ll ans = 1;
    forn(i,0,n) {
        int x;
        scanf("%s %d", c, &x);
        if(c[1] =='D') {
            if(!l.empty() && -*l.begin() > x) l.insert(-x);
            else if(!r.empty() && *r.begin() < x) r.insert(x);
            else f.insert(x);
        }
        else {
            if(!l.empty() && -*l.begin() > x) no();
            else if(!r.empty() && *r.begin() < x) no();
            else {
                if(f.find(x) != f.end()) {
                    f.erase(x);
                    ans = ans*2%mod;
                }
                l.erase(-x);
                r.erase(x);
                for(auto y : f) if(y<x) l.insert(-y);
                else r.insert(y);
                f.clear();
            }
        }
    }
    ans = ans * (f.size() + 1)%mod;
    cout<<ans;
    
    
    
}