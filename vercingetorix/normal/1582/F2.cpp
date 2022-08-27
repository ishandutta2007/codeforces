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
const int A = 8192;
int tar[A];
vector<int> banglist[A];

void remin(int v, int nw) {
    if(nw < tar[v]) {
        forn(i,nw,tar[v]) banglist[i].pb(v);
        tar[v] = nw;
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    forn(i,0,A) forn(j,0,A) banglist[i].pb(j);
    forn(i,0,A) banglist[i].pb(0);
    int n;
    scanf("%d", &n);
    readv(a,n);
    int INF = A;
    forn(i,0,A) tar[i] = INF;
    tar[0] = 0;
    forn(i,0,n) {
        forn(j,0,banglist[a[i]].size()) {
            int was = banglist[a[i]][j];
            remin(was^a[i], a[i]);
//            if(tar[was] < a[i]) {
//                tar[was^a[i]] = min(tar[was^a[i]], a[i]);
//                swap(banglist[a[i]][j], banglist[a[i]].back());
//                banglist[a[i]].pop_back();
//                j--;
//            }
        }
        banglist[a[i]].clear();
    }
    vi ans;
    forn(i,0,A) if(tar[i] < INF) ans.pb(i);
    printf("%d\n", ans.size());
    for(auto x: ans) printf("%d ", x);
    
}