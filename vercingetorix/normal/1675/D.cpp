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
vvi ch;
vvi ans;
int pt = 0;

void dfs(int v, int ind) {
    ans[ind].pb(v);
    if(!ch[v].empty()) {
        dfs(ch[v][0], ind);
        forn(i,1,ch[v].size()) {
            pt++;
            ans.pb(vi());
            dfs(ch[v][i], pt-1);
        }
    }
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
        readv(p,n);
        forn(i,0,n) p[i]--;
        ch.clear();
        ch.resize(n);
        int root = -1;
        forn(i,0,n) {
            if(p[i]==i) root = i;
            else ch[p[i]].pb(i);
        }
        ans.clear();
        pt = 1;
        ans.pb(vi());
        dfs(root, 0);
        printf("%d\n", (int)ans.size());
        for(auto x : ans) {
            printf("%d\n", x.size());
            for(auto y : x) printf("%d ", y+1);
            printf("\n");
        }
    }
    
    
}