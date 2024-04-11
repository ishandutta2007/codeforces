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
    vvi b(n, vi(n));
    forn(i,0,n) forn(j,0,n) scanf("%d", &b[i][j]);
    int ans = 0;
    forn(mask,0,1<<((n+1)/2)) {
        vi c;
        int m = mask;
        forn(i,0,(n+1)/2) {
            c.pb(m%2);
            m/=2;
        }
        forn(i,0,(n-1)/2) c.pb(0);
        vi pref(1,0);
        forn(i,0,n) {
            pref.pb(pref.back()^c[i]);
        }
        vvi a = b;
        forn(col,0,n) {
            int shift = pref[col+1];
            if(col >= (n+1)/2) shift ^= pref[col+1-(n+1)/2];
            if(shift) forn(row,(n-1)/2,n) a[row][col] *= -1;
        }
//        printf("\n%d\n", mask);
//        forn(i,0,n) {
//            forn(j,0,n) printf("%d ", a[i][j]);
//            printf("\n");
//        }
        int cand = 0;
        int mid = (n-1)/2;
        int s = (n+1)/2;
        forn(i,0,n) cand += a[mid][i];
        forn(row,0,mid) {
            int cur1 = a[row][mid] + a[row + s][mid];
            int cur2 = -cur1;
            forn(col,0,mid) {
                cur1 += abs(a[row][col] + a[row+s][col] + a[row][col+s] + a[row+s][col+s]);
                cur2 += abs(a[row][col] + a[row+s][col] - a[row][col+s] - a[row+s][col+s]);
            }
            cand += max(cur1, cur2);
        }
        ans = max(ans, cand);
    }
    cout<<ans;
    
    
}