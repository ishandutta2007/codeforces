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
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &a[i])

#define pb push_back
#define mp make_pair
int d[10][1000001];
int res[10][1000001];
int maxd[1000001];
const int mln = 1000000;
int dd[mln+1];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,1000001) {
        int x = i;
        while(x>0) {
            maxd[i] = max(maxd[i], x%10);
            x /= 10;
        }
    }
    forn(h,0,10) forn(i,0,10) {
        if(i>=h) {
            d[h][i] = 2;
            res[h][i] = -h;
            if(h==0) {
                d[h][i] = 1;
            }
        }
        else {
            d[h][i] = 1;
            res[h][i] = i-h;
        }
    }
    d[0][0] = 0;
    forn(h,0,10) {
        forn(i,10,1000001) {
            int r = max(h, maxd[i]);
            d[h][i] = d[h][i-r]+1;
            res[h][i] = res[h][i-r];
        }
    }
    
    ll n;
    cin>>n;
    int p = n/1000000;
    int q = n%1000000;
    ll ans = 0;
    while(p > 0) {
        ans += d[maxd[p]][q];
        q = mln + res[maxd[p]][q];
        p--;
    }
    ans += d[0][q];
    cout<<ans;
    
    
    
    
}