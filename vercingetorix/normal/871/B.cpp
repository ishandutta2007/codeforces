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

const int MAXN = 100000;

int req(int x, int y) {
    printf("? %d %d\n", x, y);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi x1(n), y1(n);
    forn(i,0,n) x1[i] = req(i,0);
    y1[0] = x1[0];
    forn(j,1,n) y1[j] = req(0,j);
    vvi x(n, vi(n));
    forn(i,0,n) forn(j,0,n) x[i][j] = x1[i]^x1[0]^y1[j];
    vvi ans;
    forn(to0,0,n) {
        vi a(n);
        forn(i,0,n) a[i] = x[i][to0];
        vi cnt(n,0);
        bool bad = false;
        forn(i,0,n) {
            if(a[i]>=n) {
                bad = true;
                break;
            }
            cnt[a[i]]++;
            if(cnt[a[i]]>1) bad = true;
        }
        if(bad) continue;
        vi arev(n);
        forn(i,0,n) arev[a[i]] = i;
        
        forn(i,0,n) if((a[0]^arev[i]) != x[0][i]) bad = true;
        forn(i,0,n) if((a[i]^arev[0]) != x[i][0]) bad = true;
        if(!bad) ans.pb(a);
    }
    printf("!\n");
    printf("%d\n", ans.size());
    forn(i,0,n) printf("%d ", ans[0][i]);
    fflush(stdout);
    
    
}