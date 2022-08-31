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
    vi x(3), y(3);
    forn(i,0,3) cin>>x[i]>>y[i];
    int ans = 10000;
    pi p;
    forn(i,0,1001) forn(j,0,1001) {
        int cand = 1;
        forn(k,0,3) cand += abs(x[k]-i) + abs(y[k]-j);
        if(cand < ans) {
            p = mp(i,j);
            ans = cand;
        }
    }
//    cout<<ans;
    printf("%d\n", ans);
    printf("%d %d\n", p.first, p.second);
    forn(i,0,3) {
        int a = p.first;
        int b = p.second;
        while(a!=x[i] || b!=y[i]) {
            if(a<x[i]) a++;
            else if(a>x[i]) a--;
            else if(b<y[i]) b++;
            else if(b>y[i]) b--;
            printf("%d %d\n", a,b);
        }
    }
    
    
}