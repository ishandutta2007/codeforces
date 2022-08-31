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
    char c[200500];
    forn(ifa,0,ta) {
        int n,k;
        scanf("%d %d\n", &n, &k);
        scanf("%s", c);
        if(n%k != 0) {
            printf("-1\n");
            continue;
        }
        vi cnt(26,0);
        forn(i,0,n) cnt[c[i]-'a']++;
        int can = 1;
        forn(i,0,26) if(cnt[i] % k) can = 0;
        if(can) {
            printf("%s\n", c);
            continue;
        }
        int fg = n/k;
        vi f(26,0);
        vi bf;
        int bfg;
        int pos = 0;
        forn(i,0,n) {
            int cur = c[i]-'a';
            if(c[i] != 'z') {
                can = 0;
                forn(j,(c[i]-'a')+1, 26) if(f[j]) can = 1;
                if(can || fg>0) {
                    bf = f;
                    pos = i;
                    bfg = fg;
                }
            }
            if(f[cur]) f[cur]--;
            else if(fg>0) {
                fg--;
                f[cur] = k-1;
            }
            else break;
        }
        string ans;
        forn(i,0,pos) ans.pb(c[i]);
        if(bf[(c[pos]-'a')+1] == 0 && bfg > 0) {
            bfg--;
            bf[(c[pos]-'a')+1] += k;
        }
        bf[0] += bfg*k;
        int pt = c[pos]-'a';
        pt++;
        while(bf[pt] == 0) pt++;
        bf[pt]--;
        ans.pb('a'+pt);
        forn(i,0,26) ans += string(bf[i], 'a'+i);
        printf("%s\n", ans.c_str());
        
    }
    
    
}