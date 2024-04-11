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
const int A = 101;
int d[A][A][2][2];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d[0][0][0][0] = 1;
    d[0][0][1][0] = 1;
    forn(kl,1,A) {
        forn(k,0,kl+1) {
            int l = kl-k;
            forn(need,0,2) {
                if(k > 0) d[k][l][0][need] |= d[k-1][l][1][need];
                if(l > 0) d[k][l][0][need] |= d[k][l-1][1][need^1];
            }
            forn(need,0,2) {
                d[k][l][1][need] = 1;
                if(k > 0) if(d[k-1][l][0][need]== 0) d[k][l][1][need] = 0;
                if(l > 0) if(d[k][l-1][0][need]== 0) d[k][l][1][need] = 0;
            }
        }
    }
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(a,n);
        vi cnt(2,0);
        forn(i,0,n) cnt[abs(a[i])%2]++;
        if(d[cnt[0]][cnt[1]][0][0] == 1) printf("Alice\n");
        else printf("Bob\n");
    }
    
    
}