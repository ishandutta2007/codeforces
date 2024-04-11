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

ll split(int x, int l) {
    ll sm = x/l;
    ll kbig = x%l;
    ll ksm = l - kbig;
    return sm*sm*ksm + (sm+1)*(sm+1)*kbig;
}

ll upg(int x, int l) {
    return split(x,l) - split(x, l+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    readv(a, n);
    ll cur = 0;
    forn(i,0,n) cur += ll(a[i])*a[i];
    vi curp(n, 1);
    set<pll> q;
    forn(i,0,n) q.insert(mp(-upg(a[i], curp[i]), i));
    while(k>n) {
        auto it = q.begin();
        int v = it->second;
        cur += it->first;
        curp[v]++;
        q.erase(it);
        q.insert(mp(-upg(a[v], curp[v]), v));
        k--;
    }
    printf("%lld\n", cur);
    
}