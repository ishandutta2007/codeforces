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
#define readv(x, n) vll x(n); forn(i,0,n) scanf("%lld", &x[i])

#define pb push_back
#define mp make_pair
int bb[2];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    readv(a,n);
    vll b(n);
    ll p = 0;
    ll f = 0;
    ll s = 0;
    forn(sum,2,2*m+1) {
        bb[0]= 0;
        bb[1] = 0;
        int swin = 0;
        int nbig = 0;
        forn(i,0,n) {
            int r = a[i]%sum;
            if(r >= bb[0]) {
                bb[1] = bb[0];
                bb[0] = r;
            }
            else if(r>bb[1]) {
                bb[1] = r;
            }
//            swin = max(swin, r/2);
            if(r*2 < sum) {
                swin = max(swin, r);
            }
            else {
                nbig++;
                swin = max(swin, sum - r - 1);
            }
        }
        swin = max(swin, bb[1]/2);
        if(nbig % 2 == 0) swin = max(swin, bb[0]/2);
        int l = min(sum-1, 2*m+1-sum);
        if(swin >= max(sum - m,1)) {
            int cnt = swin - max(sum-m,1)+1;
            p+=cnt;
            l-=2*cnt;
//            printf("%d %d %d %d\n", sum, cnt, l, nbig%2);
        }
//        else printf("%d %d %d %d\n", sum, 0, l, nbig%2);
        
//        p += swin;
//        int l = sum -1 -2*swin;
        if(nbig%2==0) s+=l;
        else f+=l;
    }
    printf("%lld %lld %lld %lld", p,p,f,s);
    
    
}