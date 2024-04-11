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
    char c[555];
    while(t--) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        vs a(n);
        forn(i,0,n) {
            scanf("%s", c);
            a[i] = string(c);
        }
        for(int i = 0; i < n; i += 3) forn(j,0,m) a[i][j] = 'X';
        if(n%3 == 0) forn(j,0,m) if(a[n-1][j] == 'X') a[n-2][j] = 'X';
        for(int i = 3; i<n; i+=3) {
            if(m==1 || (a[i-1][1] =='.' && a[i-2][1] =='.')) {
                a[i-1][0] = 'X';
                a[i-2][0] = 'X';
            }
            else {
                a[i-1][1] = 'X';
                a[i-2][1] = 'X';
            }
        }
        forn(i,0,n) printf("%s\n", a[i].c_str());
    }
    
}