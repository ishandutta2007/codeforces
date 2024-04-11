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

int ans[100500];

int ask(int a,int b, int c) {
    if(a==b) return ans[a];
    else if(b==c) return ans[b];
    else if(a==c) return ans[a];
    printf("? %d %d %d\n", a+1, b+1, c+1);
    fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int ask(vi & x) {
    return ask(x[0],x[1],x[2]);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        vvi tri;
        vi res;
        for(int i = 0; i < n; i+=3) {
            tri.pb(vi({i,i+1,i+2}));
            res.pb(ask(tri.back()));
        }
        int p0 = 0;
        int p1 = 0;
        while(res[p0] != 0) p0++;
        while(res[p1] != 1) p1++;
        int v0,v1;
        if(ask(tri[p0][0], tri[p0][1], tri[p1][0]) == 1) {
            v0 = tri[p0][2];
            v1 = tri[p1][0];
        }
        else if(ask(tri[p0][1], tri[p1][0], tri[p1][1]) == 1) {
            v0 = tri[p0][0];
            v1 = tri[p1][1];
        }
        else {
            v0 = tri[p0][1];
            v1 = tri[p1][2];
        }
        ans[v0] = 0;
        ans[v1] = 1;
        forn(i,0,res.size()) {
            int x = tri[i][0];
            int y = tri[i][1];
            int z = tri[i][2];
            if(res[i] == 1) {
                if(ask(v0,x,y) == 1) {
                    ans[x] = 1;
                    ans[y] = 1;
                    ans[z] = ask(z,v0,v1);
                }
                else {
                    ans[z] = 1;
                    ans[x] = ask(x,v0,v1);
                    ans[y] = 1-ans[x];
                }
            }
            else {
                if(ask(v1,x,y) == 0) {
                    ans[x] = 0;
                    ans[y] = 0;
                    ans[z] = ask(z,v0,v1);
                }
                else {
                    ans[z] = 0;
                    ans[x] = ask(x,v0,v1);
                    ans[y] = 1-ans[x];
                }
            }
        }
        vi q;
        forn(i,0,n) if(ans[i] == 0) q.pb(i);
        printf("! %d", q.size());
        for(auto x : q) printf(" %d", x+1);
        printf("\n");
        fflush(stdout);
    }
    
    
}