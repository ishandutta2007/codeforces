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
vvi r;
bool more(int i, int j) {
    int res = 0;
    forn(k,0,5) if(r[i][k] < r[j][k]) res++;
    if(res>=3) return true;
    else return false;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    char c[500];
    while(t--) {
        int n;
        scanf("%d\n", &n);
        r = vvi(n, vi(5,0));
        forn(i,0,n) forn(j,0,5) scanf("%d", &r[i][j]);
        vi bad(n,0);
        int ind = 0;
        forn(i,1,n) {
            if(more(i,ind)) ind = i;
        }
        int can = 1;
        forn(i,0,n) {
            if(i==ind) continue;
            if(more(i,ind)) can = 0;
        }
        if(can) printf("%d\n", ind+1);
        else printf("-1\n");
        
    }
    
}