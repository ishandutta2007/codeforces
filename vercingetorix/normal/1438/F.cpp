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
int req(int u, int v, int w) {
    printf("? %d %d %d\n", u,v,w);
    fflush(stdout);
    int res;
    scanf("%d", &res);
    return res;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int h;
    scanf("%d", &h);
    int n = 1;
    forn(i,0,h) n*=2;
    n-=1;
    // forn(affa,0,15315) rand();
    vi cnt(n,0);
    forn(i,0,420) {
        int x,y,z;
        do{
        x = gen()%n;
        y = gen()%n;
        z = gen()%n;
        } while(x==y || x==z || y==z);
        cnt[req(x+1,y+1,z+1)-1]++;
    }
    vpi a;
    forn(i,0,n) a.pb(mp(-cnt[i],i));
    sort(all(a));
    int u = a[0].second;
    int v = a[1].second;
    forn(i,0,n) {
        if (u==i || v==i) continue;
        if(req(u+1,v+1,i+1) == i+1) {
            cout<<"! "<<i+1;
            return 0;
        }
    }
    
}