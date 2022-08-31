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
int n;
vi a;
vi ans;
void go(int i) {
    a[i+2] = a[i]^a[i+1]^a[i+2];
    a[i+1] = a[i+2];
    a[i] = a[i+2];
    ans.pb(i+1);
}

void fin() {
    printf("YES\n");
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d ", x);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        ans.clear();
        scanf("%d", &n);
        a.resize(n);
        forn(i,0,n) scanf("%d", &a[i]);
//        readv(a,n);
        int s = 0;
        int o = 0;
        forn(i,0,n) {
            if(a[i] == 0) o = 1;
            s^=a[i];
        }
        if(o == 0 || s == 1) {
            printf("NO\n");
            continue;
        }
        if(n == 4 && a[0]==1 && a[1] == 0 && a[2] == 0 && a[3] == 1) {
            printf("NO\n");
            continue;
        }
        if(a[0] == 1) {
            int pt = 1;
            while(pt < n-1 && a[pt] == a[pt+1]) pt+=2;
            if(pt >= n-1) {
                printf("NO\n");
                continue;
            }
            for(int i = pt-1; i >= 0; i-=2) {
                go(i);
            }
        }
        
        if(a[1] == 1) {
            if(n == 3) go(0);
            else {
                go(1);
                if(a[1] == 1) go(0);
            }
        }
        int r = 1;
        while(r < n) {
            if(a[r] == 0) r++;
            else {
                if(a[r+1] == 1) go(r-1);
                else go(r);
            }
        }
        fin();
        
//        int pt = 0;
//        while(a[pt] != 0) pt++;
//        int l = pt;
//        int r = pt;
//        while(r + 1 < n && a[r+1] == 0) r++;
//        while(l > 1) {
//            ans.pb(l-1);
//            a[l-1] = 0;
//            a[l-2] = 0;
//            l -= 2;
//        }
//        while(r < n-3) {
//            ans.pb(r+2);
//            a[r+3]  = a[r+1]^a[r+2]^a[r+3];
//            a[r+2] = a[r+3];
//            a[r+1] = a[r+3];
//            if(a[r+1] == 1) {
//                ans.pb(r+1);
//                a[r+1] = 0;
//                a[r+2] = 0;
//            }
//            while(r + 1 < n && a[r+1] == 0) r++;
//        }
        
    }
    
    
}