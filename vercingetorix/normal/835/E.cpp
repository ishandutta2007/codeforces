#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
int n,x,y;

int req(vi a) {
    if(a.empty()) return 0;
    int y1 = y;
    int k = a.size() - 1;
    if(k%2 == 1) y1 ^= x;
    printf("? %d", (int)a.size());
    for(auto v : a) printf(" %d", v);
    printf("\n");
    fflush(stdout);
    int res;
    scanf("%d", &res);
    if(res == y1) return 1;
    else return 0;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    scanf("%d %d %d", &n, &x, &y);
    vi bitsim(10);
    vi s;
    int dbit = -1;
    forn(i,0,10) {
        vi q;
        forn(j,1,n+1) {
            if(j & (1<<i)) q.pb(j);
        }
        bitsim[i] = req(q);
        if(bitsim[i] == 1) {
            dbit = i;
            s = q;
        }
    }
    forn(i,0,10) {
        if (i==dbit) continue;
        vi ns1, ns2;
        for(auto u : s) if(u & (1<<i)) ns1.pb(u);
        else ns2.pb(u);
        if(ns1.empty()) {
            s=ns2;
            continue;
        }
        else {
            if(req(ns1) == 1) s=ns1;
            else s=ns2;
        }
    }
    int a = s[0];
    int b = a;
    forn(i,0,10) if(bitsim[i]) b ^= (1<<i);
    if(a>b) swap(a,b);
    printf("! %d %d\n", a, b);
    
}