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
const int A= 1050;
vpi x;
int to[2*A];
int p[2*A];
int taken[2*A];
int n,m;
void turn(int last) {
    if(last!=-1 && to[last] != -1 && taken[to[last]] == 0) {
        taken[to[last]] = 1;
        printf("%d\n", to[last]+1);
        fflush(stdout);
    }
    else {
        int tk = -1;
        forn(i,0,2*n) {
            if(taken[i] == 0 && to[i] != -1) {
                if(p[to[i]] > p[i]) i = to[i];
                printf("%d\n", i+1);
                taken[i] = 1;
                fflush(stdout);
                return;
            }
            if(taken[i] == 0 && (tk==-1 || p[i] > p[tk])) tk = i;
        }
        taken[tk] = 1;
        printf("%d\n", tk+1);
        fflush(stdout);
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    read(n);
    read(m);
    forn(i,0,2*n) scanf("%d", &p[i]);
    forn(i,0,2*n) to[i] = -1;
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        to[u] = v;
        to[v] = u;
    }
    int t;
    read(t);
    int last = -1;
    if(t == 2) {
        int x;
        read(x);
        x--;
        last = x;
        taken[last] = 1;
    }
    forn(i,0,n) {
        turn(last);
        if(i!=n-1) {
            int x;
            read(x);
            x--;
            last = x;
            taken[last] = 1;
        }
    }
    
    
}