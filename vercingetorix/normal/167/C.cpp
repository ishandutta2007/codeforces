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

int can[200];

void go(int k) {
    int A = 100;
    vi gr(A,0);
    forn(i,1,A) {
        int dk = 1;
        while(dk <= i) {
            can[gr[i-dk]] = 1;
            dk*=k;
        }
        while(can[gr[i]]) gr[i]++;
        dk = 1;
        while(dk <= i) {
            can[gr[i-dk]] = 0;
            dk*=k;
        }
    }
    forn(i,0,A) if(gr[i] == 0) printf("%d ", i);
    
    printf("\n");
    forn(i,0,A) if(((i+1)/(k+1)+i+1)%2) printf("%d ", i);
    printf("\n");
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
//    forn(k,2,20) if(k%2 == 0){
//        printf("GO %d\n", k);
//        go(k);
//    }
//    exit(0);
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        ll a,b;
        scanf("%lld %lld", &a, &b);
        if(a < b) swap(a,b);
        if(b == 0) {
            printf("Second\n");
            continue;
        }
        if(a==b) {
            printf("First\n");
            continue;
        }
        int cur = 0;
        int ans = -1;
        while(b!=0) {
            if(b%2) {
                ll c = a - a%b;
                if(c%2 == 0) {
                    ans = cur;
                    break;
                }
            }
            else {
                vll d;
                ll m = a/b - 1;
                if(m>0 && ((m+1)/(b+1)+m)%2) {
                    ans = cur;
                    break;
                }
            }
//                if(m>0) {
//                    while(m>0) {
//                        d.pb(m%b);
//                        m/=b;
//                    }
//                    vi gr(d.size(), 0);
//                    gr[0] = 1;
//                    forn(i,1,d.size()) {
//                        int op = 0;
//                        for(int j = i-1; j>=0; j--) {
//                            op ^= gr[j];
//                            can[op] = 1;
//                        }
//                        while(can[gr[i]]) gr[i]++;
//                        op = 0;
//                        for(int j = i-1; j>=0; j--) {
//                            op ^= gr[j];
//                            can[op] = 0;
//                        }
//                    }
//                    int g = 0;
//                    forn(i,0,d.size()) if(d[i]%2) g ^= gr[i];
//                    if(g != 0) {
//                        ans = cur;
//                        break;
//                    }
//                }
//            }
            cur^=1;
            a%=b;
            swap(a,b);
        }
        if(ans == -1) ans = cur^1;
        if(ans != -1) {
            if(ans) printf("Second\n");
            else printf("First\n");
        }
        else printf("?\n");
    }
    
    
}