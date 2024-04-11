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
const int A = 5001;
int d[A][A];
int pref[A];
int suf[A];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        int n,m;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        forn(i,0,n+1) forn(j,0,m+1) {
            d[i][j] = 0;
        }
        forn(i,0,n+1) {
            pref[i] = 0;
            suf[i] = 0;
        }
        for(int i = n-1; i>=0; i--) for(int j = m-1; j>=0; j--) if(s[i] == t[j]) d[i][j] = 1+d[i+1][j+1];
        int cur = 0;
        forn(i,0,n) {
            if(cur < m && s[i] == t[cur]) cur++;
            pref[i] = cur;
        }
        cur = 0;
        for(int i = n-1; i>=0; i--) {
            if(cur<m && s[i] == t[m-1-cur]) cur++;
            suf[i] = cur;
        }
        if(pref[n-1] < m) {
            printf("-1\n");
            continue;
        }
        int ans = n;
        forn(l,0,n) {
            forn(tl,0,m) if(d[l][tl] > 0) {
                int len = d[l][tl];
                int r = l + len-1;
                int tr = tl + len-1;
                int cand = n-len;
                if(tl > 0) if(l == 0 || pref[l-1] < tl) continue;
                if(tr+1<m) if(r+1==n || suf[r+1] < m-tr-1) continue;
                if(l != 0) {
                    cand += 1 + l - tl;
                }
                ans = min(ans, cand);
            }
        }
        printf("%d\n", ans);
//        printf("+\n");
    }
    
    
}