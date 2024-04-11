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

int mex(const vi & a) {
    int n = a.size();
    vi have(n+3,0);
    for(auto x : a) if(x < n+1) have[x] = 1;
    int pt = 0;
    while(have[pt] > 0) pt++;
    return pt;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int  t;
    read(t);
    while(t--) {
        int n,m;
        read(n);
        readv(a,n);
        vi q;
        int curmax = n;
        while(1) {
            int to = mex(a);
            if(to == curmax) {
                a[curmax-1] = curmax;
                q.pb(curmax--);
                if(curmax == 0) break;
            }
            else {
                a[to] = to;
                q.pb(to+1);
            }
        }
        printf("%d\n", (int)q.size());
        for(auto x : q) printf("%d ", x);
        printf("\n");
//        forn(i,0,n) {
//            int to = mex(a);
//            if(to == n) break;
//            a[i] = to;
//            a.pb(i+1);
//        }
    }
    
}