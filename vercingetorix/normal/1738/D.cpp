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
        readv(b,n);
        int k = 0;
        forn(i,0,n) k += b[i] > (i+1);
        vvi after(n+2);
        forn(i,0,n) after[b[i]].pb(i+1);
        int cur = 0;
        if(!after[n+1].empty()) cur = n+1;
        printf("%d\n", k);
        while(!after[cur].empty()) {
            int nx = after[cur][0];
            for(auto x : after[cur]) if(!after[x].empty()) nx = x;
            for(auto x : after[cur]) if(x!=nx) printf("%d ", x);
            printf("%d ", nx);
            cur = nx;
        }
//        vi big(n,0);
//        if(b[0] == 0) big[0] = 0;
//        else big[0] = 1;
//        forn(i,1,n) {
//            if(b[i] == b[i-1]) big[i] = big[i-1];
//            else big[i] = big[i-1]^1;
//        }
//        int k =  0;
//        forn(i,0,n) k += big[i];
//        vi ans(n,-1);
//        forn(i,1,n) if(big[i] != big[i-1]) ans[i-1] = b[i];
//        vi taken(n+1,0);
//        forn(i,0,n) if(ans[i] != -1) taken[ans[i]] = 1;
//        int pts = 1;
//        int ptb = k+1;
//        forn(i,0,n) if(ans[i] == -2) {
//            if(big[i] == 1) {
//                while(taken[pts]) pts++;
//                ans[i] = pts++;
//            }
//            else {
//                while(taken[ptb]) ptb++;
//                ans[i] = ptb++;
//            }
//        }
//        printf("%d\n", k);
//        forn(i,0,n) printf("%d ", ans[i]);
        printf("\n");
    }
    
    
}