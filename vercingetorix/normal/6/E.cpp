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
    int n,k;
    scanf("%d %d", &n , &k);
    readv(a,n);
    int r = 0;
    vpi e;
    int best = -1;
    multiset<int> cur;
    forn(l,0,n) {
        while(1) {
            if(r==n) break;
            if(!cur.empty()) {
                if(a[r] - *cur.begin() > k) break;
                else {
                    auto it = cur.end();
                    it--;
                    if(*it - a[r] > k) break;
                }
            }
            cur.insert(a[r++]);
        }
        if(r - l > best) {
            best = r-l;
            e.clear();
            e.pb(mp(l+1,r));
        }
        else if(r-l==best) {
            e.pb(mp(l+1,r));
        }
        cur.erase(cur.find(a[l]));
    }
    printf("%d %d\n", best, (int)e.size());
    for(auto x : e) {
        printf("%d %d\n", x.first, x.second);
    }
    
    
    
    
}