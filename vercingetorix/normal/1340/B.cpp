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

bool sub(string &a, string &b) {
    forn(i,0,7) if(a[i] == '1' && b[i] == '0') return false;
    return true;
}

int con(string &a, string &b) {
    int ret = 0;
    forn(i,0,7) if(a[i] == '0' && b[i] == '1') ret++;
    return ret;
}

int costto[10][2001];
int d[2001][2001];

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    vs valid({"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"});
    int n, k;
    scanf("%d %d", &n, &k);
    vs a;
    char c[100];
    forn(i,0,n) forn(j,0,10) costto[j][i] = -1;
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
        forn(j,0,10) if(sub(a.back(), valid[j])) costto[j][i] = con(a.back(), valid[j]);
    }
    d[n][0] = 1;
    for(int i = n-1; i >= 0; i--) {
        set<int> chads;
        forn(j,0,10) chads.insert(costto[j][i]);
        vi chad;
        for(auto x : chads) if(x!=-1) chad.pb(x);
        forn(was,0,k+1) {
            if(d[i+1][was]) for(auto x : chad) if(x+was<=k) d[i][was+x] = 1;
        }
    }
    string ans;
    if(d[0][k] != 1) printf("-1\n");
    else {
        forn(i,0,n) {
            for(int j = 9; j>=0; j--) {
                int cto = costto[j][i];
                if(cto!=-1 && k>=cto && d[i+1][k-cto]) {
                    ans.pb('0'+j);
                    k-=cto;
                    break;
                }
                    
            }
            
        }
    }
    printf("%s\n", ans.c_str());
}