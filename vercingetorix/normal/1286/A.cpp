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
int best;
vvi holes(2);

int test(int c0, int c1) {
    if(c0<0 || c1<0) return 100500;
    vi x = {c0, c1};
    vi pt(2,0);
    forn(i,0,2) {
        while(pt[i] < holes[i].size() && holes[i][pt[i]] <= x[i]) {
            x[i] -= holes[i][pt[i]++];
        }
    }
    return 2*int(holes[0].size() + holes[1].size() - pt[0] - pt[1]);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    readv(p,n);
    if(n == 1) {
        cout<<0;
        return 0;
    }
    vpi q;
    vi used(n+1, 0);
    forn(i,0,n) {
        if(p[i] != 0) q.pb(mp(i, p[i] % 2));
        used[p[i]] = 1;
    }
    vi cnt(2,0);
    forn(i,1,n+1) {
        if(used[i] == 0) cnt[i%2]++;
    }
    int ans = 0;
    if(q.empty()) {
        cout<<1;
        return 0;
    }
    int k = q.size();
    
    forn(i,0,k-1) {
        if(q[i].second == q[i+1].second) holes[q[i].second].pb(q[i+1].first-q[i].first - 1);
        else ans++;
    }
    forn(i,0,2) srt(holes[i]);
    best = n+1;
    forn(i,0,4) {
        vi c = cnt;
        int fail = 0;
        if(i&1) c[q[0].second] -= q[0].first;
        else fail++;
        if(i&2) c[q.back().second] -= n-1-q.back().first;
        else fail++;
        best = min (best , fail+test(c[0], c[1]));
    }
    cout << best + ans;
    
}