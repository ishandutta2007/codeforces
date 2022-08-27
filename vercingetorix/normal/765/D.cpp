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

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    scanf("%d", &n);
    vi f(n+1);
    set<int> vals;
    forn(i,1,n+1) scanf("%d", &f[i]);
    forn(i,1,n+1) vals.insert(f[i]);
    for(auto x : vals) {
        if(f[x] != x) {
            cout<<-1;
            return 0;
        }
    }
    int m = vals.size();
    vi h(m+1);
    vi g(n+1);
    int pt = 1;
    for(auto x : vals) h[pt++] = x;
    forn(i,1,m+1) g[h[i]] = i;
    forn(i,1,n+1) {
        g[i] = g[f[i]];
    }
    printf("%d\n", m);
    forn(i,1,n+1) printf("%d ", g[i]);
    printf("\n");
    forn(i,1,m+1) printf("%d ", h[i]);
}