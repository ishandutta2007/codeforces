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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        set<pi> q;
        forn(i,0,n) if(a[i] > 0) q.insert(mp(-a[i], i));
        vpi ans;
        while(q.size() > 1) {
            auto it = q.begin();
            pi x = *it;
            it++;
            pi y = *it;
            q.erase(x);
            q.erase(y);
            ans.pb(mp(x.second, y.second));
            a[x.second]--;
            a[y.second]--;
            if(a[x.second] > 0) q.insert(mp(-a[x.second], x.second));
            if(a[y.second] > 0) q.insert(mp(-a[y.second], y.second));
        }
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d %d\n", x.first+1, x.second+1);
        
    }
    
    
}