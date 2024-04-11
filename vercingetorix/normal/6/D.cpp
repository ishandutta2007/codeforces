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

int n,a,b;
int best;
vi ans;
vi cur;
int cursum = 0;
int h[12];

void go(int i) {
    if(cursum >= best) return;
    if(i == n-1) {
        if(h[i] < 0 && h[i-1] < 0) {
            best = cursum;
            ans = cur;
        }
    }
    else {
        cur.pb(0);
        while(h[i-1] >= 0) {
            cur.back()++;
            cursum++;
            h[i-1]-=b;
            h[i+1]-=b;
            h[i]-=a;
        }
        go(i+1);
        cur.back()++;
        cursum++;
        h[i-1]-=b;
        h[i+1]-=b;
        h[i]-=a;
        while(cur.back() <= 8) {
            go(i+1);
            cur.back()++;
            cursum++;
            h[i-1]-=b;
            h[i+1]-=b;
            h[i]-=a;
        }
        if(i == n-2) {
            while(h[i+1] >= 0) {
                cur.back()++;
                cursum++;
                h[i-1]-=b;
                h[i+1]-=b;
                h[i]-=a;
            }
            go(i+1);
        }
        h[i-1] += cur.back()*b;
        h[i] += cur.back()*a;
        h[i+1] += cur.back()*b;
        cursum -= cur.back();
        cur.pop_back();
    }
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d", &n, &a, &b);
    best = 100*n;
    forn(i,0,n) scanf("%d", &h[i]);
    go(1);
    printf("%d\n", best);
    forn(i,0,n-2) {
        while(ans[i]--) printf("%d ", i+2);
    }
    
    
}