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
const int A = 200500;
int parent[A];
int rk[A];
int timer[A];
void make_set (int v, int tm) {
    parent[v] = v;
    rk[v] = 0;
    timer[v] = tm;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
        timer[a] = min(timer[a], timer[b]);
    }
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
        int n,k;
        scanf("%d %d", &n, &k);
        map<int, vpi> x,y;
        forn(i,0,n) {
            int a,b,tm;
            scanf("%d %d %d", &a, &b, &tm);
            make_set(i, tm);
            x[a].pb(mp(b,i));
            y[b].pb(mp(a,i));
        }
        for(auto v : x) {
            srt(v.second);
            forn(i,1,v.second.size()) {
                if(v.second[i].first-v.second[i-1].first <= k) union_sets(v.second[i].second, v.second[i-1].second);
            }
        }
        for(auto v : y) {
            srt(v.second);
            forn(i,1,v.second.size()) {
                if(v.second[i].first-v.second[i-1].first <= k) union_sets(v.second[i].second, v.second[i-1].second);
            }
        }
        vi boom;
        forn(i,0,n) if(i == find_set(i)) boom.pb(timer[i]);
        srt(boom);
        int ans = boom.size()-1;
        ans = min(ans,boom.back());
        forn(i,0,boom.size()) {
            ans = min(ans, max((int)boom.size()-i-2, boom[i]));
        }
        printf("%d\n", ans);
//        for(auto x : boom) cout<<x<<' ';
//        cout<<endl;
    }
    
    
}