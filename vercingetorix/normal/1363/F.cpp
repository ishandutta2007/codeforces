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

const int A = 2020;
int d[A][A];
int cnt[26];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    scanf("%d\n", &ta);
    char c[2050];
    forn(ifa,0,ta) {
        int n;
        scanf("%d\n", &n);
        scanf("%s", c);
        string s(c);
        scanf("%s", c);
        string t(c);
        string ss = s;
        string st = t;
        srt(ss);
        srt(st);
        if(ss!=st) {
            printf("-1\n");
            continue;
        }
        forn(i,0,n+1) forn(j,0,n+1) d[i][j] = n;
        d[n][n] = 0;
        for(int lj = n; lj > 0; lj--) {
            forn(k,0,26) cnt[k] = 0;
            int neg = 0;
            forn(i,lj,n) {
                cnt[t[i]-'a']--;
                if(cnt[t[i]-'a'] == -1) neg++;
            }
            int li = n;
            while(neg > 0) {
                li--;
                cnt[s[li]-'a']++;
                if(cnt[s[li]-'a'] == 0) neg--;
            }
            while(li>=0) {
                if(s[li-1] == t[lj-1]) d[li-1][lj-1] = min(d[li-1][lj-1], d[li][lj]);
                if(cnt[t[lj-1]-'a'] > 0) d[li][lj-1] = min(d[li][lj-1], d[li][lj]);
                if(li == 0) break;
                d[li-1][lj] = min(d[li-1][lj], d[li][lj] + 1);
                li--;
                cnt[s[li]-'a']++;
            }
        }
//        forn(i,0,n+1) {
//            forn(j,0,n+1) cout<<d[i][j]<<' ';
//            cout<<'\n';
//        }
        printf("%d\n", d[0][0]);
    }
    
    
}