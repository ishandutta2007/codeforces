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

vll a;
vll b;

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(c, n);
    for(auto x : c) {
        if(x>=0) a.pb(x);
        else b.pb(x);
    }
    sort(all(a));
    reverse(all(a));
    
    sort(all(b));
    vll sum(k+1,0);
    ll ans = -1e18;
    ll cur = 0;
    for(auto x : a) {
        cur += sum[0];
        sum[0] += x;
    }
    int pt = 0;
//    ans = cur;
    vll num(k+1, 0);
    ll blad = 0;
    ll bsum = 0;
    ll bcnt =0;
    forn(i,0,b.size()) {
        blad += b[i]*i;
        bsum += b[i];
        bcnt++;
    }
    forn(i,0,b.size()) {
        ans = max(ans, cur + bcnt*sum[0] + num[0] * bsum + blad);
        bsum -= b[i];
        bcnt--;
        blad -= bsum;
        cur += num[pt] * b[i];
        num[pt] ++;
        if(pt==0) cur += sum[0];
        pt = (pt+1)%(k+1);
    }
    ans = max(ans, cur);
    cout<<ans;
}