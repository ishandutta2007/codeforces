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
const int INF = 1e9;
vvi d;

void proc(int x) {
    int xtr = 0;
    while(x > 7) {
        x-=3;
        xtr += 1;
    }
    vvi nd(6, vi(6,-INF));
    forn(i,0,6) forn(j,0,6) {
        int maxdec = min(min(i,j), x);
        forn(dec,0,maxdec+1) {
            int cur = d[i][j] + xtr + dec;
            if(x-dec>=3) {
                nd[j-dec][x-dec-3] = max(nd[j-dec][x-dec-3], cur+1);
            }
            if(x-dec>=6) {
                nd[j-dec][x-dec-6] = max(nd[j-dec][x-dec-6], cur+2);
            }
            if(x-dec<=5) {
                nd[j-dec][x-dec] = max(nd[j-dec][x-dec], cur);
            }
        }
    }
    forn(add,0,3){
    forn(i,0,6) forn(j,0,6) {
        if(i>=3) nd[i-3][j] = max(nd[i-3][j], nd[i][j]+1);
        if(j>=3) nd[i][j-3] = max(nd[i][j-3], nd[i][j]+1);
    }
    }
    d=nd;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    vi cnt(m+1,0);
    forn(i,0,n) {
        int x;
        read(x);
        cnt[x]++;
    }
    d =vvi(6, vi(6,-INF));
    d[0][0] = 0;
    forn(i,1,m+1) {
        proc(cnt[i]);
//        cout<<(cnt[i])<<endl;
//        
//        forn(i,0,6) {
//            forn(j,0,6) cout<<d[i][j]<<' ';
//            cout<<endl;
//        }
    }
    int ans = 0;
    forn(i,0,6) forn(j,0,6) ans = max(ans, d[i][j]);
    cout<<ans;
    
    
}