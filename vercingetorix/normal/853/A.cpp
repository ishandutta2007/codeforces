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

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,k;
    scanf("%d %d", &n, &k);
    set<int> fr;
    forn(i,1,n+1) fr.insert(i+k);
    ll ans = 0;
    vi t(1+n);
    vpi fl;
    forn(i,1,n+1) {
        int x;
        scanf("%d", &x);
        fl.pb(mp(x, i));
    }
    sort(all(fl));
    reverse(all(fl));
    for(auto x : fl) {
        ll c = x.first;
        ll st = x.second;
        auto it = fr.lower_bound(st);
        ans += ll(*it - st)*c;
        t[st] = *it;
        fr.erase(it);
    }
    printf("%lld\n", ans);
    forn(i,1,n+1) printf("%d ", t[i]);
    
}