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
typedef unsigned long long ull;
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
vs c;
ull d10[20];
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    d10[0] = 1;
    forn(i,1,20) d10[i] = d10[i-1]*10;
    int ta;
    cin>>ta;
    forn(ifa,0,ta) {
        int n;
        cin>>n;
        ull cur;
        cin>>cur;
        c = vs(n);
        forn(i,0,n) {
            cin >> c[i];
            c[i] += c[i];
        }
        ull to = 0;
        bool chen = false;
        forn(i,0,n) {
            if(chen) break;
            if(to == d10[n+1]) break;
            ull rem = d10[n-1-i];
            ull l = cur / rem;
            ull r = to / rem;
            int dig = l%10;
            int win = 10;
            vvi same(11);
            forn(len,1,11) forn(j,0,10) if(c[i].substr(j,len) == c[i].substr(dig, len)) same[len].pb(j);
            int ts =-1;
            while(1) {
                ts++;
                if(ts == 10) break;
                if(l/10==r/10 && ts < dig) continue;
                ull len = (r + ts - l + 1);
                if(same[min(len,(ull)10)].size() == 1) break;
                if(same[min(len,(ull)10)][1] + (ts - dig) >= 10) break;
            }
            to += ts * rem;
            if(to/rem >= r+10) chen=true;
            ull it = to/rem - l;
            forn(add,1,min(it,(ull)10)+1) if(c[i][dig] != c[i][dig + add]) chen = true;
        }
        cout<<to-cur<<'\n';
    }
    
    
}