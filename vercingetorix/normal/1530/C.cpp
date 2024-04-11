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
    read(t);
    while(t--) {
        int n;
        read(n);
        vvi a(2, vi(n));
        forn(tt,0,2) forn(i,0,n) scanf("%d", &a[tt][i]);
        srt(a[0]); srt(a[1]);
        vi sum(2,0);
        forn(i,0,n) forn(tt,0,2) sum[tt] += a[tt][i];
        int pt = 0;
        while(pt < n/4) {
            forn(tt,0,2) sum[tt] -= a[tt][pt];
            pt++;
        }
        int pt2 = pt;
        int nd = 0;
        while(sum[0] < sum[1]) {
            nd++;
            n++;
            sum[0]+=100;
            while(pt < n/4) {
                sum[0] -= a[0][pt];
                pt++;
            }
            while(pt2 > 0 && pt2+nd > n/4) {
                sum[1] +=a[1][--pt2];
            }
        }
        printf("%d\n", nd);
    }
    
    
}