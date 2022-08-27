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
int n,k;
vi a;

int can(int m) {
    vi amin(n);
    int cur = 0;
    int curmin = 0;
    forn(i,0,n) {
        if(a[i] >= m) cur++;
        else cur--;
        curmin = min(cur, curmin);
        amin[i] = curmin;
        if(i >= k-1) {
            if(i == k-1) {
                if(cur>0) return 1;
            }
            else {
                if(cur > amin[i-k]) return 1;
            }
        }
    }
    return 0;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    scanf("%d %d", &n, &k);
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    int l = 0;
    int r = n+1;
    while(r-l>1) {
        int m = (r+l)/2;
        if(can(m)) l = m;
        else r = m;
    }
    cout<<l;
    
}