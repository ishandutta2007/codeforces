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
    int n;
    read(n);
    vvi a;
    forn(i,0,n) {
        readv(x,n);
        a.pb(x);
    }
    vvi ans;
    while(1) {
        int stop = 1;
        vi mv(n, 0);
        forn(i,0,n) {
            srt(a[i]);
            forn(j,1,n) if(a[i][j] == a[i][j-1]) {
                mv[i] = a[i][j];
                stop = 0;
                break;
            }
        }
        int l = 0;
        int r = 1;
        forn(it,0,2*n) {
            if(mv[r] == 0) mv[r] = mv[l];
            l = r;
            r ++ ;
            if(r == n) r = 0;
        }
        if(stop) break;
        ans.pb(mv);
        forn(i,0,n) {
            int i1 = (i+1)%n;
            int pt = 0;
            while(a[i1][pt] != mv[i1]) pt++;
            a[i1][pt] = mv[i];
        }
    }
    for(int shift = n-1; shift >= 1; shift--) {
        vi mv;
        forn(i,0,n) {
            int tar = (i+1+shift)%n;
            if(tar == 0 ) tar = n;
            mv.pb(tar);
        }
        forn(it,0,n-shift) {
            ans.pb(mv);
        }
    }
    printf("%d\n", ans.size());
    for(auto x : ans) {
        forn(i,0,n) printf("%d ", x[i]);
        printf("\n");
    }
    
    
}