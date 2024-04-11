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
ll gcd (ll a, ll b) {
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    forn(ifa,0,t) {
        int n,m;
        scanf("%d %d", &n, &m);
        readv(a,n);
        scanf("\n");
        vector<char> c(n);
        forn(i,0,n) {
            scanf("%c", &c[i]);
            if(i!=n-1) scanf(" ");
        }
        vvpi pos(2);
        forn(i,0,n) {
            if(a[i]%2==0) pos[0].pb(mp(a[i],i));
            else pos[1].pb(mp(a[i],i));
        }
        srt(pos[0]);
        srt(pos[1]);
        vi ans(n,-1);
        deque<int> q;
        forn(pp,0,2) {
            q.clear();
            for(auto x : pos[pp]) {
                if(q.empty()) {
                    q.pb(x.second);
                    continue;
                }
                int r = q.back();
                if(c[r] == 'L' && c[x.second] == 'L') {
                    ans[r] = (a[x.second]+a[r])/2;
                    ans[x.second] = (a[x.second]+a[r])/2;
                    q.pop_back();
                }
                else if(c[r] == 'R' && c[x.second] == 'L') {
                    ans[r] = (a[x.second]-a[r])/2;
                    ans[x.second] = (a[x.second]-a[r])/2;
                    q.pop_back();
                }
                else q.pb(x.second);
            }
            while(q.size() >= 2) {
                int l = q.size();
                int x = q[l-1];
                int r = q[l-2];
                q.pop_back();
                q.pop_back();
                if(c[r] == 'R' && c[x] == 'R') {
                    ans[r] = (2*m-a[r]-a[x])/2;
                    ans[x] = (2*m-a[r]-a[x])/2;
                }
                else if(c[r] == 'L' && c[x] == 'R') {
                    ans[r] = (2*m+a[r]-a[x])/2;
                    ans[x] = (2*m+a[r]-a[x])/2;
                }
            }
        }
        forn(i,0,n) printf("%d ", ans[i]);
        printf("\n");
    }
    
    
}