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
#include <array>
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

struct node {
    array<int, 2> ch;
    array<int, 2> best;
    node() : ch({-1,-1}) {};
    void reset() {
        best = {0,0};
        ch = {-1,-1};
    }
};
#ifdef LOCAL
const int A= 300;
#else
const int A = 300500;
#endif

node d[A*30];
int pt;

int go(int v, int val, int ind, int bit, int cur) {
    int iind = (ind & (1<<(bit+1))) != 0;
    if(bit == -1) {
        d[v].best[iind] = max(d[v].best[iind], cur);
        return cur;
    }
    
    int nx = ((val^ind)&(1<<bit))!=0;
    if(d[v].ch[nx^1] != -1) {
        int ineed = (val & (1<<bit))==0;
        cur = max(cur, d[d[v].ch[nx^1]].best[ineed]+1);
    }
    if(d[v].ch[nx] == -1) d[v].ch[nx] = pt++;
    cur = go(d[v].ch[nx], val, ind, bit-1, cur);
//    d[d[v].ch[nx]].best[iind] = max(d[d[v].ch[nx]].best[iind], cur);
    d[v].best[iind] = max(d[v].best[iind], cur);
    return cur;
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
        pt = 1;
        int n;
        scanf("%d", &n);
        readv(a,n);
        int ans = 0;
        forn(i,0,n) {
            ans = max(ans, go(0, a[i], i, 29, 1));
        }
        printf("%d\n", ans);
        forn(i,0,pt) d[i].reset();
    }
    
    
}