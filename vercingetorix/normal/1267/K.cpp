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

ll cnk[200][200];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,200) cnk[i][0] = 1;
    forn(n,1,200) forn(k,1,200) cnk[n][k] = cnk[n-1][k] + cnk[n-1][k-1];
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        ll n;
        cin>>n;
        int cur = 2;
        map<int, int> a;
        while(n>0) {
            a[n%cur]++;
            n/=cur;
            cur++;
        }
        cur--;
        vpi b;
        for(auto x : a) b.pb(x);
        int taken = 0;
        srtrev(b);
        ll ans = 1;
        for(auto x : b) {
            int av = cur-x.first - taken;
            if(x.first==0) av--;
            ans *= cnk[av][x.second];
            taken+=x.second;
        }
        
        if(cur > 2 && b.back().first == 0) {
            b.back().second--;
            ll ans2 = 1;
            cur--;
            taken = 0;
            for(auto x : b) {
                int av = cur-x.first - taken;
                if(x.first==0) av--;
                if(av < x.second) {
                    ans2 = 0;
                    break;
                }
                ans2 *= cnk[av][x.second];
                taken+=x.second;
            }
            ans -= ans2;
        }
        cout<<ans-1<<'\n';
    }
    
    
}