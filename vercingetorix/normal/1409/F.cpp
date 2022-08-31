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
//int d[201][201][3];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    cin>>n>>k;
    string s;
    string t;
    cin>>s>>t;
    if(t[0] == t[1]) {
        int c0 = 0;
        int c1  =0;
        for(auto x : s ) {
            if(x==t[0]) c1++;
            else c0++;
        }
        c1 += min(c0, k);
        cout<<c1*(c1-1)/2;
        exit(0);
    }
    vvi d(n+1, vi(k+1, -INF));
    d[0][0] = 0;
    for(auto x : s) {
        vvi nd = d;
        if(x==t[0]) {
            forn(i,0,n+1) forn(j,0,k+1) {
                if(j < k) nd[i][j+1] = max(nd[i][j+1], d[i][j] + i);
                if(i<n) nd[i+1][j] = max(nd[i+1][j], d[i][j]);
            }
        }
        else if(x==t[1]) {
            forn(i,0,n+1) forn(j,0,k+1) {
                nd[i][j] = max(nd[i][j], d[i][j] + i);
                if(i<n && j < k) nd[i+1][j+1] = max(nd[i+1][j+1], d[i][j]);
            }
        }
        else {
            forn(i,0,n+1) forn(j,0,k+1) {
                if(j<k) nd[i][j+1] = max(nd[i][j+1], d[i][j] + i);
                if(i<n && j < k) nd[i+1][j+1] = max(nd[i+1][j+1], d[i][j]);
            }
        }
        d = nd;
    }
    int ans = 0;
    forn(i,0,n+1) forn(j,0,k+1) ans = max(ans, d[i][j]);
    cout<<ans;
    
    
    
}