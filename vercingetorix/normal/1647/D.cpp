#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <queue>
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
ll gcd (ll a, ll b) {return b==0 ? a : gcd(b, a%b);}
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

bool isp(int n) {
    for(int l =2 ; l*l<=n; l++) {
        if(n%l == 0) return false;
    }
    return true;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    const int A = 100500;
    vi isdeg(A, 0);
    forn(l,2,sqrt(2e9)) {
        if(!isp(l)) continue;
        ll dl = l;
        while(dl < A) {
            isdeg[dl] = l;
            dl *= l;
        }
        
    }
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n,d;
        scanf("%d %d", &n, &d);
        if(n/d%d != 0) {
            printf("NO\n");
            continue;
        }
        if(isp(n/(d*d))) {
            printf("NO\n");
            continue;
        }
        int wasn = n;
        int wd = d;
        if(n == d*d) {
            printf("NO\n");
            continue;
        }
        if(isdeg[d] > 0) {
            int p = isdeg[d];
            int deg = 0;
            while(n%p == 0) {
                n/=p;
                deg++;
            }
            int deg2 = 0;
            while(d%p==0) {
                d/=p;
                deg2++;
            }
            if(deg2 == 1) {
                if(isp(n)) printf("NO\n");
                else printf("YES\n");
                continue;
            }
            int mx = deg/deg2;
            if(mx > 2) {
                if(mx == 3) {
                    while(wasn % wd == 0) {
                        wasn/=wd;
                        
                    }
                    if(deg2==2 && wasn*p == wd) printf("NO\n");
                    else printf("YES\n");
                    continue;
                }
                printf("YES\n");
                continue;
            }
            int cnt = deg%deg2;
            if(n>1) {
                cnt++;
                if(!isp(n)) cnt++;
            }
            if(cnt>1) printf("YES\n");
            else printf("NO\n");
        }
        else {
            if(n==d*d || isp(n/(d*d))) printf("NO\n");
            else printf("YES\n");
        }
//        if(!isp(d)) {
//            printf("YES\n");
//            continue;
//        }
//        while(n%d) n/=d;
//        if(n == 1 || isp(n)) {
//            printf("NO\n");
//        }
//        else printf("YES\n");
    }
    
    
}