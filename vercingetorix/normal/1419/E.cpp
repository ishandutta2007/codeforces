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

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        vi pr;
        vi div;
        int m = n;
        for(int l = 2; l*l <= n; l++) {
            if(n%l == 0) {
                div.pb(l);
                if(l*l<n) div.pb(n/l);
                if(m%l == 0) {
                    pr.pb(l);
                    while(m%l==0) m/=l;
                }
            }
        }
        if(m>1) pr.pb(m);
        div.pb(n);
        if(pr.size() == 1) {
            for(auto x : div) printf("%d ", x);
            printf("\n");
            printf("0\n");
        }
        else if(pr.size() >= 3) {
            int k = pr.size();
            vvi to(k);
            forn(i,0,k) to[i].pb(pr[i]*pr[(i+k-1)%k]);
            forn(i,0,k) pr.pb(to[i][0]);
            forn(i,0,k) to[i].pb(pr[i]);
            for(auto x : div) {
                int done = 0;
                forn(i,0,2*k) if(x == pr[i]) {
                    done = 1;
                    break;
                }
                if(done == 0) {
                    int pt = 0;
                    while(x%pr[pt]!=0) pt++;
                    to[pt].pb(x);
                }
            }
            forn(i,0,k) for(auto x : to[i]) printf("%d ", x);
            printf("\n");
            printf("0\n");
        }
        else if(div.size() == 3) {
            for(auto x : div) printf("%d ", x);
            printf("\n");
            printf("1\n");
        }
        else {
            if((n/pr[0])%pr[0] != 0) swap(pr[0],pr[1]);
            vvi to(2);
            to[0].pb(pr[0]*pr[1]);
            to[1].pb(pr[0]*pr[0]*pr[1]);
            forn(i,0,2) pr.pb(to[i][0]);
            forn(i,0,2) to[i].pb(pr[i]);
            for(auto x : div) {
                int done = 0;
                forn(i,0,4) if(x == pr[i]) {
                    done = 1;
                    break;
                }
                if(done == 0) {
                    int pt = 0;
                    while(x%pr[pt]!=0) pt++;
                    to[pt].pb(x);
                }
            }
            forn(i,0,2) for(auto x : to[i]) printf("%d ", x);
            printf("\n");
            printf("0\n");
        }
    }
    
    
}