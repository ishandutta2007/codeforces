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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
int n;
vi p, w;
vpi ans;
void aswap(int pos1, int pos2) {
    if (pos1 == pos2) return;
    ans.pb(mp(pos1, pos2));
    int u = p[pos1];
    int v = p[pos2];
    swap(p[pos1], p[pos2]);
    swap(w[u], w[v]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    int n,r;
    scanf("%d", &n);
    p.resize(n);
    
    forn(i,0,n) scanf("%d", &p[i]);
//    readv(p,n);
    forn(i,0,n) p[i]--;
    w= vi(n);
    forn(i,0,n) w[p[i]] = i;
//    vpi ans;
    forn(i,1,n-1) {
        if(w[i] >= n/2) aswap(w[i], 0);
        else {
            aswap(w[i],n-1);
            aswap(0, n-1);
        }
        if (i>=n/2) aswap(0,i);
        else {
            aswap(0,n-1);
            aswap(n-1,i);
        }
    }
    if(p[0] != 0) aswap(0,n-1);
    printf("%d\n", ans.size());
    for(auto x : ans) {
        printf("%d %d\n", x.first+1, x.second+1);
    }
    
}