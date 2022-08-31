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
const int A = 100000;
ll d[A];
int best[2];

void upd(int x) {
    if(best[0] == x) return;
    else if(best[1] == x) {
        if(d[x] > d[best[0]]) swap(best[0], best[1]);
    }
    else if(d[x] >= d[best[0]]) {
        best[1] = best[0];
        best[0] = x;
    }
    else if(d[x] >= d[best[1]]) {
        best[1] = x;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,q;
    scanf("%d %d", &n, &q);
    vll v(n), c(n);
    forn(i,0,n) scanf("%lld", &v[i]);
    forn(i,0,n) scanf("%lld", &c[i]);
    forn(i,0,n) c[i]--;
    const ll INF = 1e18;
    forn(afaf,0,q) {
        ll ans = 0;
        forn(i,0,n) d[i] = -INF;
        best[0] = 0;
        best[1] = 1;
        ll a,b;
        scanf("%lld %lld", &a, &b);
        forn(i,0,n) {
            int col = c[i];
            d[col] = max(d[col], d[col] + a*v[i]);
            int ind = best[0];
            if(ind == col) ind = best[1];
            ll up = b*v[i];
            if(d[ind] > 0) up += d[ind];
            d[col] = max(d[col], up);
            upd(col);
            ans = max(ans, d[col]);
        }
        printf("%lld\n", ans);
    }
    
}