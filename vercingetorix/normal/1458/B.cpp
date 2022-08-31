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

//int d[100][10001];
const int INF = 1e9;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    vi a(n), b(n);
    forn(i,0,n) scanf("%d %d", &a[i], &b[i]);
    vvi d(101, vi(10001, -INF));
//    forn(i,0,100) forn(j,0,10001) d[i][j] = 0;
    d[0][0] = 0;
    forn(i,0,n) {
        vvi nd = d;
        forn(k,0,100) {
            forn(w,0,9901) {
                nd[k+1][w+b[i]] = max(nd[k+1][w+b[i]], d[k][w] +a[i] - b[i]);
            }
        }
        d = nd;
    }
    int sum = 0;
    forn(i,0,n) sum += b[i];
    forn(k,1,n+1) {
        double ans = 0;
        forn(i,0,10001) {
            ans = max(ans, double(i)+double(min(sum-i, 2*d[k][i]))/2 );
        }
        printf("%.10lf ", ans);
    }
    

}