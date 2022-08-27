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
    vll f(2,1);
    forn(i,1,1000) f.pb(f[i] + f[i-1]);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        readv(c,n);
        ll sum = 0;
        for(auto x : c) sum+=x;
        int num = 0;
        ll cur = 0;
        while(cur < sum) cur += f[num++];
        if(cur>sum) {
            printf("NO\n");
            continue;
        }
        int tot = num;
        num--;
        int bad = 0;
        int last = -1;
        
        while(num >= 0) {
            vi big;
            forn(i,0,n) if(c[i] >= f[num] && last != i) big.pb(i);
            if(big.empty()) {
                bad = 1;
                break;
            }
            else if(big.size() == 1) {
                c[big[0]] -= f[num--];
                last = big[0];
            }
            else {
                int win = 0;
                for(auto tk : big) {
                    int num2 = num;
                    int last2 = last;
                    vi c2 = c;
                    c2[tk] -= f[num2--];
                    last2 = tk;
                    int bad2 = 0;
                    while(num2 >= 0) {
                        vi big2;
                        forn(i,0,n) if(c2[i] >= f[num2] && last2 != i) big2.pb(i);
                        if(big2.empty()) {
                            bad2 = 1;
                            break;
                        }
                        else {
                            c2[big2[0]] -= f[num2--];
                            last2 = big2[0];
                        }
                    }
                    if(bad2 == 0) {
                        win = 1;
                        break;
                    }
                }
                if(win == 0) {
                    bad = 1;
                    break;
                }
                else break;
            }
        }
        if(bad) printf("NO\n");
        else printf("YES\n");
        
    }
    
    
}