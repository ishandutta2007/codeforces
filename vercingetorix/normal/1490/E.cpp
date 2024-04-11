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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vpll q;
        forn(i,0,n) q.pb(mp(a[i], i));
        sort(all(q));
        vi bad(n, 0);
        ll sum = 0;
        forn(i,0,n) {
            sum += q[i].first;
            if(i < n-1 && q[i+1].first > sum) {
                bad[i] = 1;
            }
        }
        for(int i = n-1; i>=1; i--) {
            if(bad[i]) bad[i-1] = 1;
        }
        vi ans;
        forn(i,0,n) if(bad[i] == 0) ans.pb(q[i].second + 1);
        srt(ans);
        printf("%d\n", ans.size());
        for(auto x : ans) printf("%d ", x);
        printf("\n");
    }
    
}