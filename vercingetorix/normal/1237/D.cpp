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
    int m = 0;
    forn(i,0,n) if(a[i] > a[m]) m = i;
    int br = -1;
    vi ans(n,-1);
    forn(i,0,n) {
        int ind = (m+i)%n;
        if(a[ind]*2 < a[m]) {
            br = i;
            break;
        }
    }
    if(br == -1) {
        forn(i,0,n) printf("-1 ");
        exit(0);
    }
    ans[m] = br;
    
    vpi q;
    q.pb(mp(a[m], 0));
    for(int i = 1; i<n; i++) {
        int ind = (m+n-i)%n;
        while(!q.empty() && q.back().first >= a[ind]) q.pop_back();
        q.pb(mp(a[ind], i));
        if(q[0].first * 2 >= a[ind]) ans[ind] = i+ans[m];
        else {
            int bad = a[ind]/2;
            if(a[ind]%2==0) bad--;
            auto it = upper_bound(all(q), mp(bad, n));
            it--;
            ans[ind] = i - it->second;
        }
        int ind1 = (ind+1)%n;
        ans[ind] = min(ans[ind], 1+ans[ind1]);
    }
    forn(i,0,n) printf("%d ", ans[i]);
}