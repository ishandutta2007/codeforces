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
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        if(n==1) {
            printf("-1\n");
            continue;
        }
        else if(n==2) {
            swap(a[0], a[1]);
            printf("%d %d\n", a[0], a[1]);
            continue;
        }
        set<int> x;
        forn(i,1,n+1) x.insert(i);
        forn(i,0,n-3) {
            auto it = x.begin();
            if(*it == a[i]) it++;
            printf("%d ", *it);
            x.erase(it);
        }
        vi was;
        forn(i,n-3,n) was.pb(a[i]);
        vi cur;
        for(auto lef : x) cur.pb(lef);
        while(cur[0] == was[0] || cur[1] == was[1] || cur[2] == was[2]) {
            next_permutation(all(cur));
            
        }
        printf("%d %d %d\n", cur[0], cur[1], cur[2]);
    }
    
    
}