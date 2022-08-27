#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    cin>>t;
    forn(affa,0,t) {
        int n,m;
        cin>>n>>m;
        if (m<n) {
            cout<<0<<endl;
            continue;
        }
        int ml = 0;
        int d2 = 1;
        while(n + ml <= m) {
            if((n&d2)==0) ml += d2;
            if (n + ml <= m) d2 *= 2;
        }
        int ans = 0;
        while(d2 > 0) {
            if((n&d2)==0) {
                ml -= d2;
                if (n + ml <= m) {
                    ans += d2;
                    n += d2;
                }
            }
            d2/=2;
        }
//        int mex = 0;
//        int d2 = 1;
//        while(d2 <= max(n,m)) d2*=2;
//        int ans = 0;
//        while(d2 >= 1) {
//            if((d2&n)==0) {
//                if(m>=d2) {
//                    m-=d2;
//                    ans += d2;
//                }
//            }
//            else ans += d2;
//            d2/=2;
//        }
        cout<<ans<<endl;
    }
    
}