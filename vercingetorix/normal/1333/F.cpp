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
    cin>>n;
    vi ban(n+1, 0);
    int cur = 1;
    forn(k,2,n+1) if(ban[k] == 0) {
        cur++;
        for(int l = 2*k; l<=n; l+=k) ban[l]++;
    }
    vi ans(n+1,n);
    ans[cur] = min(ans[cur], 1);
    set<int> add, rem;
    forn(s,2,n+1) {
        for(int l = 2*s; l<=n; l+=s) {
            ban[l]--;
            if(ban[l] == 0) add.insert(l);
        }
        while(!add.empty() || !rem.empty()) {
            if(!add.empty()) {
                int k = *add.begin();
                add.erase(add.begin());
                cur++;
                for(int l = 2*k; l<=n; l+=k) {
                    ban[l]++;
                    if(ban[l] == 1) {
                        auto it = add.find(l);
                        if(it == add.end()) {
                            rem.insert(l);
                        }
                        else add.erase(it);
                    }
                }
            }
            else if(!rem.empty()) {
                int k = *rem.begin();
                rem.erase(rem.begin());
                cur--;
                for(int l = 2*k; l<=n; l+=k) {
                    ban[l]--;
                    if(ban[l] == 0) {
                        auto it = rem.find(l);
                        if(it == rem.end()) {
                            add.insert(l);
                        }
                        else rem.erase(it);
                    }
                }
            }
        }
        ans[cur] = min(ans[cur], s);
    }
    for(int i = n-1; i>=1; i--) ans[i] = min(ans[i], ans[i+1]);
    forn(i,2,n+1) printf("%d ", ans[i]);
    
    
}