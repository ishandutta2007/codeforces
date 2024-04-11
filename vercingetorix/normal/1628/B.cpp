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
    int ta;
    read(ta);
    char c[5];
    forn(ifa,0,ta) {
        int n;
        scanf("%d\n", &n);
        vs a;
        forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
        }
        int can = 0;
        forn(i,0,n) {
            if(a[i][0] == a[i].back()) can = 1;
        }
        set<string> s2;
        set<string> v2;
        set<string> v3;
        if(can == 0) {
        forn(i,0,n) {
            string cur = a[i];
            if(cur.size() == 2) {
                v2.insert(cur);
                reverse(all(cur));
                if(s2.find(cur) != s2.end()) {
                    can = 1;
                    break;
                }
                if(v2.find(cur) != v2.end()) {
                    can = 1;
                    break;
                }
            }
            else {
                v3.insert(cur);
                s2.insert(cur.substr(0, 2));
                reverse(all(cur));
                if(v3.find(cur) != v3.end()) {
                    can = 1;
                    break;
                }
                cur.pop_back();
                if(v2.find(cur) != v2.end()) {
                    can = 1;
                    break;
                }
            }
        }
        }
        if(can) printf("YES\n");
        else printf("NO\n");
        
    }
    
    
}