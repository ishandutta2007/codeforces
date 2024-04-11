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
    char c[500500];
    while(t--) {
        int n;
        scanf("%d\n", &n);
        vvi q(26);
        forn(i,0,n) {
            scanf("%s", c);
            string s(c);
            vi cnt(26,0);
            int num = 0;
            for(auto x : s) {
                num++;
                cnt[x-'a']++;
            }
            forn(i,0,26) q[i].pb(2*cnt[i] - num);
        }
        int ans = 0;
        forn(l,0,26) {
            srtrev(q[l]);
            int sum = 0;
            int pt = 0;
            while(pt<q[l].size() && q[l][pt] + sum > 0) {
                sum+=q[l][pt++];
            }
            ans = max(ans, pt);
        }
        printf("%d\n", ans);
    }
    
}