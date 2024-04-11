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
    int n,r;
    scanf("%d", &n);
    readv(a,n);
    int ans = 0;
    vvi pos(n+1);
    forn(i,0,n) pos[a[i]].pb(i);
    forn(i,0,n) pos[a[i]].pb(1e9);
    pos[0].pb(1e9);
    vi last(2, 0);
    forn(i,0,n) {
        int x = a[i];
        if(x==last[0] || x==last[1]) continue;
        else {
            int p = last[0];
            int q = last[1];
            auto it1 = lower_bound(all(pos[p]), i);
            auto it2 = lower_bound(all(pos[q]), i);
            ans ++;
            if(*it1 > *it2) last[0] = x;
            else last[1] = x;
        }
    }
    cout<<ans;
    
}