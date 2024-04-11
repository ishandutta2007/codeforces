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
    readv(to,n);
    vs a(n, string(n, '.'));
    int good = 1;
    vi f(n);
    forn(i,0,n) {
        to[i] -- ;
        if(to[i] != i) good = 0;
        f[to[i]] = i;
    }
    if(good) {
        printf("%d\n", n);
        forn(i,0,n) printf("%s\n", a[i].c_str());
        exit(0);
    }
    int pt = 0;
    int cur = f[0];
    vi vis(n,0);
    vis[0] = 1;
    while(cur != 0) {
        vis[cur] = 1;
        int nx = f[cur];
        if(nx < cur) {
            a[pt][nx] = '/';
            a[pt][cur] = '/';
        }
        else {
            a[pt][nx] = '\\';
            a[pt][cur] = '\\';
        }
        pt++;
        cur = nx;
    }
    forn(s,1,n) {
        if(vis[s] == 0) {
            vis[s] = 1;
            if(f[s] == s) continue;
            a[pt][0] = '\\';
            int cur = s;
            while(f[cur] != s) {
                vis[cur] = 1;
                int nx = f[cur];
                if(nx < cur) {
                    a[pt][nx] = '/';
                    a[pt][cur] = '/';
                }
                else {
                    a[pt][nx] = '\\';
                    a[pt][cur] = '\\';
                }
                pt++;
                cur = nx;
                vis[cur] = 1;
            }
            a[pt][0] = '/';
            a[pt][cur] = '/';
            pt++;
        }
    }
    reverse(all(a));
    printf("%d\n", n-1);
    for(auto x : a) printf("%s\n", x.c_str());
    
    
}