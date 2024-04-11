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
int n;
char c[200500];
int cnt[26][150000];

int go(int l, int r, int cur) {
    if(l == r) {
        if(c[l] == 'a'+cur) return 0;
        else return 1;
    }
    int m = (l+r)/2;
    int c1 = cnt[cur][m];
    if(l>0) c1 -= cnt[cur][l-1];
    int c2 = cnt[cur][r] - cnt[cur][m];
    int md = m-l+1;
    c1 = md-c1;
    c2 = md-c2;
    return min(go(l,m,cur+1)+c2, go(m+1,r,cur+1)+c1);
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
        scanf("%d\n", &n);
        scanf("%s", c);
        forn(i,0,n) forn(j,0,26) cnt[j][i] = 0;
        int deg = 0;
        int d2 = 1;
        forn(i,0,n) {
            if(i>0) forn(j,0,26) cnt[j][i] = cnt[j][i-1];
            cnt[c[i]-'a'][i]++;
        }
        printf("%d\n", go(0,n-1,0));
        
    }
    
    
}