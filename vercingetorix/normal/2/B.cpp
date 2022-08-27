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
    int n;
    read(n);
    vvi a(n,vi(n));
    vvi p(n,vi(n));
    forn(i,0,n) forn(j,0,n) scanf("%d", &a[i][j]);
    vvi d(n, vi(n, 1e9));
    int k = 2;
    string path1, path2;
    const int z = 50000;
    forn(i,0,n) forn(j,0,n) {
        int add = 0;
        while(a[i][j] != 0 && a[i][j] %k ==0) {
            a[i][j] /= k;
            add++;
        }
        if(a[i][j] == 0) add = z;
        if(i + j == 0) d[i][j] = 0;
        if(i > 0 && d[i-1][j] < d[i][j]) {
            p[i][j] = 0;
            d[i][j] = d[i-1][j];
        }
        if(j > 0 && d[i][j-1] < d[i][j]) {
            p[i][j] = 1;
            d[i][j] = d[i][j-1];
        }
        d[i][j] += add;
    }
    int ans = d[n-1][n-1];
    int x = n-1;
    int y = n-1;
    while(x+y>0) {
        if(p[x][y] == 0) {
            path1.pb('D');
            x--;
        }
        else {
            path1.pb('R');
            y--;
        }
    }
    reverse(all(path1));
    d = vvi(n, vi(n, 1e9));
    k = 5;
    forn(i,0,n) forn(j,0,n) {
        int add = 0;
        while(a[i][j] != 0 &&a[i][j] %k ==0) {
            a[i][j] /= k;
            add++;
        }
        if(a[i][j] == 0) add = z;
        if(i + j == 0) d[i][j] = 0;
        if(i > 0 && d[i-1][j] < d[i][j]) {
            p[i][j] = 0;
            d[i][j] = d[i-1][j];
        }
        if(j > 0 && d[i][j-1] < d[i][j]) {
            p[i][j] = 1;
            d[i][j] = d[i][j-1];
        }
        d[i][j] += add;
    }
    
    x = n-1;
    y = n-1;
    while(x+y>0) {
        if(p[x][y] == 0) {
            path2.pb('D');
            x--;
        }
        else {
            path2.pb('R');
            y--;
        }
    }
    reverse(all(path2));
    if(d[n-1][n-1] < ans) {
        ans = min(ans, d[n-1][n-1]);
        path1 = path2;
    }
    forn(i,0,n) forn(j,0,n) {
        if(a[i][j] == 0 && ans > 0) {
            printf("1\n");
            forn(i1,0,i) printf("D");
            forn(i1,0,j) printf("R");
            forn(i1,0,n-1-i) printf("D");
            forn(i1,0,n-1-j) printf("R");
            exit(0);
        }
    }
    
    cout<<ans<<endl;
    cout<<path1;
    
}