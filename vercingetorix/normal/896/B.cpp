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


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,c;
    scanf("%d %d %d", &n, &m, &c);
    vi a(n, -1);
    forn(afaf,0,m) {
        int p;
        scanf("%d", &p);
        
        forn(i,0,n) {
            if(2*p <= c) if(a[i] == -1 || a[i] > p) {
                printf("%d\n", i+1);
                a[i] = p;
                break;
            }
            if(c < 2*p) if(a[n-1-i] == -1 || p > a[n-1-i]) {
                printf("%d\n", n-i);
                a[n-1-i] = p;
                break;
            }
        }
        fflush(stdout);
        bool good = true;
        forn(i,0,n) if(a[i] == -1) good = false;
        forn(i,0,n-1) if(a[i-1] > a[i]) good = false;
        if(good) break;
    }
    
}