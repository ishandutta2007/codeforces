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
vi par, c;
vvi ch;
vi st;
void dst(int v) {
    st[v] = 1;
    for(auto u : ch[v]) {
        dst(u);
        st[v] += st[u];
    }
}
vi ans;
int can = 1;
void dfs(int v, vi x) {
    if(c[v] + 1 > st[v]) {
        can = 0;
        return;
    }
    ans[v] = x[c[v]];
    int pt = 0;
    for(auto u : ch[v]) {
        vi g;
        while(g.size() < st[u]) {
            if(pt == c[v]) pt++;
            g.pb(x[pt++]);
        }
        dfs(u, g);
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,r;
    scanf("%d", &n);
    par.resize(n);
    c.resize(n);
    ch.resize(n);
    st.resize(n);
    int root = -1;
    vi val;
    forn(i,0,n) {
        scanf("%d %d", &par[i], &c[i]);
        if(par[i] == 0) root = i;
        else{
            par[i] -- ;
            ch[par[i]].pb(i);
        }
        val.pb(i+1);
    }
    dst(root);
    ans.resize(n);
    dfs(root, val);
    if(can == 0) printf("NO\n");
    else {
        printf("YES\n");
        forn(i,0,n) printf("%d ", ans[i]);
    }
}