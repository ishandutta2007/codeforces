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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(afaf,0,t) {
        int n;
        scanf("%d", &n);
        vi l(n), r(n);
        forn(i,0,n) scanf("%d %d", &l[i], &r[i]);
        map<int, int> lx;
        map<int, int> rx;
        set<int> c;
        forn(i,0,n) {
            c.insert(l[i]);
            c.insert(r[i]);
        }
        forn(i,0,n) {
            lx[l[i]]++;
            rx[l[i]]+= 0;
        }
        forn(i,0,n) {
            rx[r[i]]++;
            lx[r[i]]+=0;
        }
        map<int, int> tol, tor;
        vi orc;
        for(auto x : c) orc.pb(x);
        sort(all(orc));
        int curl = 0;
        for(auto x : orc) {
            tol[x] = curl;
            curl += rx[x];
        }
        reverse(all(orc));
        int curr = 0;
        for(auto x : orc) {
            tor[x] = curr;
            curr += lx[x];
        }
        int ans = n;
        forn(i,0,n) ans = min(ans, tol[l[i]]+tor[r[i]]);
        printf("%d\n", ans);
    }
    
    
}