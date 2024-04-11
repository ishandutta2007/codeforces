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
    int n,m;
    cin>>n>>m;
    vs a(n);
    forn(i,0,n) cin>>a[i];
    vvi d(n, vi(m,0));
    for(int i = n-1; i >= 0; i--) {
        for(int j = m-1; j>=0; j--) {
            d[i][j] = 0;
            if(a[i][j] == '*') d[i][j]++;
            if(i==n-1 && j==m-1) continue;
            else if(i==n-1) {
                d[i][j] += d[i][j+1];
            }
            else if(j==m-1) {
                d[i][j] += d[i+1][j];
            }
            else {
                int done = 0;
                forn(l,1,10) {
                    forn(di,0,l+1) {
                        int dj = l-di;
                        if(i+di >= n || j+dj>=m) continue;
                        if(a[i+di][j+dj] == '*' && !done) {
                            d[i][j] += d[i+di][j+dj];
                            done = 1;
                        }
                    }
                }
            }
//            else if(a[i+1][j] == '*' && a[i][j+1] == '.') {
//                d[i][j] += d[i+1][j];
//            }
//            else if(a[i+1][j] == '.' && a[i][j+1] == '*') {
//                d[i][j] += d[i][j+1];
//            }
//            else {
//                d[i][j] += max(d[i][j+1], d[i+1][j]);
//            }
        }
    }
    cout<<d[0][0];
    
    
}