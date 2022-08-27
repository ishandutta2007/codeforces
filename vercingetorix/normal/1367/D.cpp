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
    char c[200500];
    while(t--) {
        scanf("%s", c);
        int n;
        scanf("%d", &n);
        readv(a, n);
        scanf("\n");
        vi cnt(26,0);
        int pt = 25;
        string s(c);
        forn(i,0,s.size()) cnt[int(s[i]-'a')]++;
        string ans(n, '*');
        forn(i,0,26) {
            vi ind;
            forn(j,0,n) {
                if(a[j] == 0) ind.pb(j);
            }
            while(ind.size() > cnt[pt]) pt--;
            for(auto x : ind) ans[x] = 'a'+pt;
            pt--;
            for(auto j : ind) {
                forn(k,0,n) a[k] -= abs(k-j);
                a[j]--;
            }
        }
        cout<<ans<<endl;
    }
    
}