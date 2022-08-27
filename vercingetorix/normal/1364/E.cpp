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
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair

vvi res;

int get(int x, int y) {
    if(x==y) return 0;
    if(res[x][y] == -1) {
        printf("? %d %d\n", x+1, y+1);
        fflush(stdout);
        int ass;
        cin >> ass;
        if(ass == -1) exit(0);
        res[x][y] = ass;
        res[y][x] = ass;
    }
    return res[x][y];
    
}
int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int n;
    cin>>n;
    res = vvi(n, vi(n, -1));
    vi z(11, -1);
    vi d2 = {1};
    forn(u,0,10) d2.pb(d2.back()*2);
    while(1) {
        int a = gen()%n;
        int b = gen()%n;
        while (b == a) b = gen()%n;
        int cur = get(a,b);
        forn (i,0,11) if((cur & d2[i]) == 0) z[i] = a;
        int good = 1;
        forn(i,0,11) if(z[i] == -1) good = 0;
        if(good) break;
    }
    vi ord;
    forn(i,0,n) ord.pb(i);
    shuffle(ord.begin(), ord.end(), gen);
    map<int, int> pos;
    vi ans(n,0);
    int found0 = 0;
    int found2 = 0;
    forn(i,0,n) {
        int cur = 0;
        forn(j,0,11) {
            cur += d2[j]&get(ord[i],z[j]);
        }
        ans[ord[i]] = cur;
        pos[cur] = ord[i];
        if (cur == 0) {
            found2 = 1;
            forn(j,0,11) z[j] = ord[i];
        }
        if(found2 == 0) {
            for(auto x : pos) {
                if((x.first & cur) == 0) {
                    forn(j,0,11) {
                        if ((d2[j]&cur) == 0) z[j] = ord[i];
                        else z[j] = x.second;
                    }
                    found2 = 1;
                    break;
                }
            }
        }
    }
    cout<<'!';
    for(auto x : ans) cout<<' '<<x;
    cout<<endl;
}