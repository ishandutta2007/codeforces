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
vi x, y, z;
int dist(int i, int j) {
    return abs(x[i]-x[j])+abs(y[i]-y[j])+abs(z[i]-z[j]);
}
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    x.resize(n);
    y.resize(n);z.resize(n);
    forn(i,0,n) {
        scanf("%d %d %d", &x[i], &y[i], &z[i]);
    }
    vi a(n,0);
    map<pi, vpi> s;
    forn(i,0,n) {
        s[mp(x[i], y[i])].pb(mp(z[i], i));
    }
    for(auto & u : s) {
        sort(all(u.second));
        while(u.second.size() >= 2) {
            int k = u.second.size();
            int i = u.second[k-1].second;
            int j = u.second[k-2].second;
            u.second.pop_back();
            u.second.pop_back();
            printf("%d %d\n", i+1, j+1);
            a[i] = 1;
            a[j] = 1;
        }
    }
    map<int, vpi> sy;
    forn(i,0,n) {
        if(a[i] == 1) continue;
        sy[x[i]].pb(mp(y[i], i));
    }
    for(auto & u : sy) {
        sort(all(u.second));
        while(u.second.size() >= 2) {
            int k = u.second.size();
            int i = u.second[k-1].second;
            int j = u.second[k-2].second;
            u.second.pop_back();
            u.second.pop_back();
            printf("%d %d\n", i+1, j+1);
            a[i] = 1;
            a[j] = 1;
        }
    }
    vpi rest;
    forn(i,0,n) {
        if(a[i] == 1) continue;
        rest.pb(mp(x[i], i));
    }
    sort(all(rest));
    while(rest.size() >= 2) {
        int k = rest.size();
        int i = rest[k-1].second;
        int j = rest[k-2].second;
        rest.pop_back();
        rest.pop_back();
        printf("%d %d\n", i+1, j+1);
        a[i] = 1;
        a[j] = 1;
    }
//    forn(i,0,n) if(!a[i]) {
//        int l = i;
//        forn(j,l+1,n) {
//            if(a[j]) continue;
//            if(l==i) l = j;
//            else if(dist(i,j) < dist(i,l)) l = j;
//        }
//        a[i] = 1;
//        a[l] = 1;
//        printf("%d %d\n", i+1, l+1);
//    }
}