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

#ifdef LOCAL
const int A = 100500;
#else
const int A = 100500;
#endif
int n;
int a[22][A];
int len[22];
int cur[100];
int curlen = 0;

vi ans(100,0);

void go(int bit) {
    if(len[bit] == 0) {
        if(ans.size() > curlen) {
            ans.clear();
            forn(i,0,curlen) ans.pb(cur[i]);
        }
        return;
    }
    if(bit == 21) return;
    int need = 0;
    forn(i,0,len[bit]) if(a[bit][i] & 1) need = 1;
    if(need == 0) {
        len[bit+1] = 0;
        forn(i,0,len[bit]) {
            a[bit+1][len[bit+1]++] = a[bit][i]/2;
        }
        go(bit+1);
    }
    else {
        for(int sg = -1; sg<=1; sg+=2) {
            int deg = sg*(1<<bit);
            cur[curlen++] = deg;
            len[bit+1] = 0;
            forn(i,0,len[bit]) {
                int val = (a[bit][i] & 1) ? (a[bit][i] - sg)/2 : a[bit][i]/2;
                if(val != 0 && (len[bit+1]==0 || a[bit+1][len[bit+1]-1] != val)) a[bit+1][len[bit+1]++] = val;
            }
            go(bit+1);
            curlen--;
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    read(n);
    forn(i,0,n) scanf("%d", &a[0][i]);
    forn(i,0,n) {
        if(a[0][i] == 0) {
            swap(a[0][i], a[0][n-1]);
            n--;
            i--;
        }
    }
//    n = 100000;
//    forn(i,0,n) a[0][i] = i - 50000;
//    n = 20;
//    forn(i,0,n) a[0][i] = 1<<i;
//    forn(i,0,n) a[0][n+i] = -(1<<i);
//    n*=2;
    sort(a[0], a[0] + n);
//    forn(i,0,n) printf("%d ", a[0][i]);
//    printf("\n");
    len[0] = n;
    go(0);
    printf("%d\n", ans.size());
    for(auto x : ans) printf("%d ", x);
    
    
}