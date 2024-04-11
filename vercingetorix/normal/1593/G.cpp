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
    int ta;
    scanf("%d", &ta);
    char c[1000500];
    forn(ifa,0,ta) {
        scanf("\n%s", c);
        string s(c);
        int n = s.size();
        vi r0,r1;
        forn(i,0,n) {
            if(i > 0) {
                r0.pb(r0.back());
                r1.pb(r1.back());
            }
            else {
                r0.pb(0);
                r1.pb(0);
            }
            if(s[i] == '(' || s[i] == ')') {
                if(i%2==0) r0.back()++;
                else r1.back()++;
            }
        }
        int q;
        scanf("%d", &q);
        while(q--) {
            int l,r;
            scanf("%d %d", &l, &r);
            r--;
            l--;
            int k1 = r1[r];
            int k2 = r0[r];
            if(l>0) {
                k1-=r1[l-1];
                k2-=r0[l-1];
            }
            printf("%d\n", abs(k1-k2));
        }
    }
    
    
}