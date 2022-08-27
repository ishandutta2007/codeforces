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
    int t;
    read(t);
    forn(ifa,0,t) {
        int n,s;
        scanf("%d %d", &s, &n);
        vi a;
        while(s> 0) {
            a.pb(s%10);
            s/=10;
        }
        int sum = 0;
        for(auto x : a) sum+=x;
        while(sum < n) {
            int pt = 1;
            while(a[pt] == 0) pt++;
            a[pt]--;
            a[pt-1] += 10;
            sum += 9;
        }
        vi ans;
        int pt = 0;
        int d10 = 1;
        forn(i,0,n) {
            while(a[pt] == 0) {
                pt++;
                d10*=10;
            }
            ans.pb(d10);
            a[pt]--;
        }
        while(pt<a.size()) {
            while(a[pt]>0) {
                ans.back()+=d10;
                a[pt]--;
            }
            pt++;
            d10*=10;
        }
        forn(i,0,n) printf("%d ", ans[i]);
        printf("\n");
    }
    
    
}