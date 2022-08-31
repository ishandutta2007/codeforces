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
int req(int l, int r) {
    printf("? %d %d\n", l+1, r+1);
    fflush(stdout);
    int x;
    scanf("%d", &x);
    return x-1;
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    int m = req(0,n-1);
    int ans = -1;
    if(m != 0 && req(0,m) == m) {
        int l = 0;
        int r = m;
        while(r-l>1) {
            int p = (r+l)/2;
            if(req(p,m) == m) l = p;
            else r = p;
        }
        ans = l;
    }
    else {
        int l = m;
        int r = n-1;
        while(r-l>1) {
            int p = (r+l)/2;
            if(req(m,p) == m) r = p;
            else l = p;
        }
        ans = r;
    }
    printf("! %d\n", ans+1);
    
}