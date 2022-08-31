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
int pos = 0;
int to = 0;
int curt = 0;
int dir = 1;
const  int INF = 2e9;
int need = INF;
int ans;
void com(int nt, int x) {
    int p = nt - curt;
    int npos = pos+dir*p;
    if(abs(pos-to) <= p) npos = to;
    int l = min(npos,pos);
    int r = max(npos,pos);
    if(need>=l && need<=r) ans++;
    pos = npos;
    curt = nt;
    if(to == pos) {
        to = x;
        if(to == pos) dir = 0;
        else dir = (to-pos)/abs(to-pos);
    }
    need = x;
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
        read(n);
        pos = 0;
        to =0;
        curt = 0;
        dir = 0;
        need = INF;
        ans = 0;
        forn(i,0,n) {
            int nt, x;
            scanf("%d %d", &nt, &x);
            com(nt,x);
        }
        int l = min(to,pos);
        int r = max(to,pos);
        if(need>=l && need<=r) ans++;
        printf("%d\n", ans);
    }
    
    
}