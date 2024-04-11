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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n,m,i,j;
        cin>>n>>m>>i>>j;
        ll best = -1;
        vll ans;
        for(ll x1 = 1; x1<=n; x1+=max(n-1,1)) {
            for(ll y1=1; y1<=m; y1+=max(m-1,1)) {
                for(ll x2 = 1; x2<=n; x2+=max(n-1,1)) {
                    for(ll y2=1; y2<=m; y2+=max(m-1,1)) {
                        if(abs(x1-i) + abs(x2-i) + abs(x1-x2) + abs(y1-j) + abs(y2-j) + abs(y1-y2) > best) {
                            best =abs(x1-i) + abs(x2-i) + abs(x1-x2) + abs(y1-j) + abs(y2-j) + abs(y1-y2);
                            ans= vll({x1,y1,x2,y2});
                        }
                    }
                }
            }
        }
        for(auto x : ans) printf("%lld ", x);
        printf("\n");
    }
    
}