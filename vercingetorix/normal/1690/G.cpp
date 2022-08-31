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
        int n,m;
        scanf("%d %d", &n, &m);
        readv(a,n);
        int cm = a[0] + 1;
        set<pi> q;
        forn(i,0,n) if(a[i] < cm) {
            cm = a[i];
            q.insert(mp(i, a[i]));
        }
        q.insert(mp(n, -1));
        while(m--) {
            int i,d;
            scanf("%d %d", &i, &d);
            i--;
            auto it = q.lower_bound(mp(i, 0));
            a[i] -= d;
            if(it->first == i) {
                pi nx = mp(i, a[i]);
                vpi todel;
                while(it->second >= a[i]) {
                    todel.pb(*it);
                    it++;
                }
                for(auto x : todel) q.erase(x);
                q.insert(nx);
            }
            else {
                pi nx = mp(i, a[i]);
                auto it2  = it;
                it2--;
                if(it2->second > a[i]) {
                    vpi todel;
                    while(it->second >= a[i]) {
                        todel.pb(*it);
                        it++;
                    }
                    for(auto x : todel) q.erase(x);
                    q.insert(nx);
                }
            }
            printf("%d ", (int)q.size() - 1);
        }
        printf("\n");
    }
    
    
}