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
typedef std::vector<vs> vvs;
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
int n,m,k;
int tmp_toi(const string & s) {
    int cur = 0;
    for(auto x : s) {
        if(x == '_') cur=cur*27;
        else cur = cur*27 + 1+int(x-'a');
    }
    return cur;
}

vi has(555555,-1);
vi ban(555555, 1);

set<int> fr;
string to1(const vs & ss) {
    //    if(ss.empty()) return;
    int l = ss.size();
    string ret;
    forn(i,0,k) {
        char f = ss[0][i];
        forn(j,1,l) if(ss[j][i] != f) f='_';
        ret.pb(f);
    }
    return ret;
}

const int MAXN = 729*729;
int N = MAXN;
vvi g(MAXN);
bool used[MAXN];
vector<int> tans;

void dfs (int v) {
    used[v] = true;
    for (size_t i=0; i<g[v].size(); ++i) {
        int to = g[v][i];
        if (!used[to])
            dfs (to);
    }
    tans.push_back (v);
}

void topological_sort() {
    for (int i=0; i<N; ++i)
        used[i] = false;
    tans.clear();
    for (int i=0; i<N; ++i)
        if (!used[i])
            dfs (i);
    reverse (tans.begin(), tans.end());
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d %d\n", &n, &m, &k);
    vs tmp;
    vi tmpcode;
    char c[10];
    forn(i,0,n) {
        scanf("%s", c);
        tmp.pb(string(c));
        int ind = tmp_toi(tmp.back());
        tmpcode.pb(ind);
        has[ind] = i+1;
        ban[ind] = 0;
        fr.insert(ind);
    }
    vvs ord(n);
    forn(i,0,m) {
        int v;
        scanf("%s %d\n", c, &v);
        int bad = 1;
        int indv = tmpcode[v-1];
        string sc(c);
        forn(mask, 0, 1<<k) {
            string temp = sc;
            forn(j,0,k) if(mask & (1<<j)) temp[j] = '_';
            int ind = tmp_toi(temp);
            if(ind == indv) bad = 0;
            else g[indv].pb(ind);
        }
        if(bad) {
            cout<<"NO";
            exit(0);
        }
    }
    topological_sort();
    vi pos(MAXN);
    forn(i,0,MAXN) pos[tans[i]] = i ;
    forn(v,0,MAXN) for(auto u : g[v]) if(pos[u] < pos[v]) {
        cout<<"NO";
        exit(0);
    }
    vi ans;
    forn(i,0,MAXN) if(ban[tans[i]] == 0) ans.pb(has[tans[i]]);
    printf("YES\n");
    for(auto x : ans) printf("%d ", x);
    
}