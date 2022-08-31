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
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,pp;
    scanf("%d %d", &n, &pp);
    ll p = pp;
    vll a(n), b(n);
    ll sum = 0;
    ll init = 0;
    forn(i,0,n) {
        int u,v;
        scanf("%d %d", &u, &v);
        a[i] = u;
        sum += a[i];
        b[i] = v;
        init += b[i];
    }
    if(p>=sum) {
        cout<<-1;
        return 0;
    }
    ll decay = sum - p;
    ld l = 0;
    ld r = (ld)init / (ld)decay;
    forn(i,0,500) {
        ld m = (l+r)/2;
        ld need = 0;
        forn(i,0,n) need += max(m*a[i] - b[i], ld(0))/p;
        if(need > m) r = m;
        else l = m;
    }
    printf("%.10lf", (double) l);
    
    
}