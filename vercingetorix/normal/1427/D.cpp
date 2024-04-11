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
vi c;
int n;

int w(int x) {
    int pt = 0;
    while(c[pt] != x) pt++;
    return pt;
}

void go(vi & op) {
    int pt = 0;
    vpi q;
    for(auto x : op) {
        q.pb(mp(pt, pt+x-1));
        pt+=x;
    }
    vi nc;
    reverse(all(q));
    for(auto x : q) {
        forn(i,x.first,x.second+1) nc.pb(c[i]);
    }
    c = nc;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    c.resize(n);
    forn(i,0,n) scanf("%d", &c[i]);
    int pt = 1;
    vvi ans;
    while(pt + 1 <= n){
        vi cur;
        if(pt > 1) cur.pb(pt-1);
        int ind = w(pt);
        cur.pb(ind-pt+2);
        if(ind + 1 < n) cur.pb(n-ind-1);
        if(cur.size() > 1) {
            ans.pb(cur);
            go(cur);
        }
        ind = w(pt+1);
        vi cur2;
        if(ind > 0) cur2.pb(ind);
        cur2.pb(n-pt-ind);
        cur2.pb(1);
        if(pt > 1) cur2.pb(pt-1);
        ans.pb(cur2);
        go(cur2);
        pt+=2;
    }
        
    printf("%d\n", (int)ans.size());
    for(auto x : ans) {
        printf("%d", (int) x.size()); for(auto y : x) printf(" %d", y);
        printf("\n");
    }
    
}