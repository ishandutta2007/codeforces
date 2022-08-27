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
    int n,x1,x2;
    scanf("%d %d %d", &n, &x1, &x2);
    readv(a,n);
    vpi q;
    forn(i,0,n) q.pb(mp(a[i],i));
    srt(q);
    vi can1(n+1,0);
    vi can2(n+1,0);
    for(int i = n-1; i>=0; i--) {
        int cur = q[i].first;
        int n1 = (x1 + cur - 1)/cur;
        int n2 = (x2 + cur - 1)/cur;
        if(n1 + i <= n) {
            can1[i] = 1;
            if(can2[n1+i]) {
                printf("Yes\n");
                printf("%d %d\n", n1, n-n1-i);
                forn(j,i,n1+i) printf("%d ", q[j].second+1);
                printf("\n");
                forn(j,n1+i,n) printf("%d ", q[j].second+1);
                printf("\n");
                exit(0);
            }
        }
        if(n2 + i <= n) {
            can2[i] = 1;
            if(can1[n2+i]) {
                printf("Yes\n");
                printf("%d %d\n", n-n2-i, n2);
                forn(j,n2+i,n) printf("%d ", q[j].second+1);
                printf("\n");
                forn(j,i,n2+i) printf("%d ", q[j].second+1);
                printf("\n");
                exit(0);
            }
        }
    }
    printf("No\n");
    
    
}