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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    readv(d,n);
    vpi q;
    forn(i,0,n) {
        q.pb(mp(d[i], i));
    }
    srtrev(q);
    int k = q[0].first;
    vi chain(k+1);
    vpi ans;
    vvi fc(2*n+1);
    chain[0] = q[0].second * 2 + 1;
    chain[k] = q[0].second * 2 + 2;
    int pt = 1;
    int cur = k+1;
    forn(i,1,k) {
        int j = q[pt].second;
        chain[i] = j*2 + 1;
        if(cur - i == q[pt].first) {
            chain.pb(j*2+2);
            cur++;
            pt++;
        }
        else {
            fc[i+q[pt].first-1].pb(2*j+2);
            pt++;
        }
    }
    while(pt<n) {
        int j = q[pt].second;
        int l = q[pt].first;
        if(l>=2) {
            fc[0].pb(2*j+1);
            fc[l-2].pb(2*j+2);
        }
        else {
            printf("%d %d\n", 2*j+1, 2*j+2);
            printf("%d %d\n", 2*j+1, chain[0]);
        }
        pt++;
    }
    forn(i,0,cur-1) printf("%d %d\n", chain[i], chain[i+1]);
    forn(i,0,cur) {
        for(auto x : fc[i]) printf("%d %d\n", chain[i], x);
    }
    
    
}