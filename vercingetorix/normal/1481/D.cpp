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
    char c[1050];
    forn(ifa,0,ta) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        vs a;
        forn(i,0,n) {
            scanf("%s", c);
            a.pb(string(c));
        }
        if(m%2 == 1 || a[0][1] == a[1][0]) {
            printf("YES\n");
            forn(i,0,m+1) printf("%d ", 1 + i%2);
            printf("\n");
            continue;
        }
        else if(n == 2) {
            printf("NO\n");
            continue;
        }
        printf("YES\n");
        if(a[0][2] == a[2][0]) {
            forn(i,0,m+1) printf("%d ", 1 + 2*(i%2));
            printf("\n");
            continue;
        }
        else if(a[1][2] == a[2][1]) {
            forn(i,0,m+1) printf("%d ", 2 + i%2);
            printf("\n");
            continue;
        }
        else if(a[0][1] == a[1][2] and a[0][1] == a[2][0]) {
            forn(i,0,m+1) printf("%d ", 1 + i%3);
            printf("\n");
            continue;
        }
        vi ord = {0,1,2};
        while(a[ord[0]][ord[1]] != a[ord[1]][ord[2]]) next_permutation(all(ord));
        deque<int> ans;
        ans.pb(0);
        ans.pb(1);
        ans.pb(2);
        forn(i,0,(m-2)/2) {
            ans.push_front(ans.front()^2);
            ans.pb(ans.back()^2);
        }
        forn(i,0,m+1) printf("%d ", ord[ans[i]]+1);
        printf("\n");
    }
    
    
}