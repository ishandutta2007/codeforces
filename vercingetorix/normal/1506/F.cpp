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
    scanf("%d\n", &t);
    while(t--) {
        int n;
        read(n);
        readv(r,n);
        readv(c,n);
        vpi e;
        forn(i,0,n) {
            e.pb(mp(r[i], c[i]));
        }
        srtrev(e);
        if(e.back() != mp(1,1)) e.pb(mp(1,1));
        reverse(all(e));
        ll ans = 0;
        forn(i,0,(int)e.size() - 1) {
            int r1 = e[i].first;
            int r2 = e[i+1].first;
            int c1 = e[i].second;
            int c2 = e[i+1].second;
            int d2 = r2-c2;
            int d1 = r1-c1;
            if(d2 - d1 >= 2) {
                ans += ((d2-d2%2) - (d1-d1%2))/2;
            }
            else if(d2 == d1) {
                if(d1 % 2 == 0) ans += r2-r1;
            }
            else {
                if(d1%2==1) ans++;
            }
        }
        cout<<ans<<endl;
    }
    
}