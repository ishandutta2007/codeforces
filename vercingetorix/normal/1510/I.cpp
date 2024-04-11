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
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n, &m);
    vpi w;
    forn(i,0,n) w.pb(mp(0, i));
    char c[1050];
    ld d = 1.5;
    forn(i,0,m) {
        scanf("%s", c);
        //        cout<<c<<endl;
        vector<ld> vote(2, 0);
        int cur = 0;
        forn(i,0,n) {
            while(cur < w[i].first) {
                cur++;
                vote[0] *= d;
                vote[1] *= d;
            }
            vote[c[w[i].second]-'0']++;
        }
        if(gen()%1000000 <= vote[0]*1000000 / (vote[0] + vote[1])) printf("0\n");
        else printf("1\n");
        fflush(stdout);
        int res;
        scanf("%d\n", &res);
        forn(i,0,n) {
            if(c[w[i].second] != '0'+res) w[i].first++;
        }
        srt(w);
    }
    
    
}