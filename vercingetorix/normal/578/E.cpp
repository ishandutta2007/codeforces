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

void win(vi & ans) {
    for(auto x : ans) printf("%d ", x+1);
    exit(0);
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    char c[100500];
    scanf("%s", c);
    string s(c);
    vi a;
    int n= s.size();
    forn(i,0,n) {
        if(s[i] == 'L') a.pb(0);
        else a.pb(1);
    }
    vi e[2];
    vvi q;
    int num = 0;
    forn(i,0,n) {
        if(e[a[i]].empty()) {
            e[a[i]^1].pb(num++);
            q.pb({i});
        }
        else {
            int ind = e[a[i]].back();
            e[a[i]].pop_back();
            e[a[i]^1].pb(ind);
            q[ind].pb(i);
        }
    }
    printf("%d\n", num-1);
    vi f[2][2];
    forn(i,0,num) {
        f[a[q[i][0]]][a[q[i].back()]].pb(i);
    }
    vi z01,z10;
    for(auto ind : f[0][1]) for(auto x : q[ind]) z01.pb(x);
    for(auto ind : f[1][0]) for(auto x : q[ind]) z10.pb(x);
    vi ord;
    int cur = 0;
    if(f[1][1].size() > f[0][0].size()) cur = 1;
    while(!f[cur][cur].empty()) {
        ord.pb(f[cur][cur].back());
        f[cur][cur].pop_back();
        cur^=1;
    }
    if(ord.empty()) {
        if(z01.empty()) win(z10);
        else if(z10.empty()) win(z01);
        else if(z01.back() > z10.back()) {
            z10.pb(z01.back());
            z01.pop_back();
            for(auto x: z01) z10.pb(x);
            win(z10);
        }
        else {
            z01.pb(z10.back());
            z10.pop_back();
            for(auto x: z10) z01.pb(x);
            win(z01);
        }
        
    }
    else {
        int last = ord.back();
        ord.pop_back();
        int col = a[q[last].back()];
        if(col == 0) {
            for(auto ind : f[0][1]) ord.pb(ind);
            ord.pb(last);
            for(auto ind : f[1][0]) ord.pb(ind);
        }
        else {
            for(auto ind : f[1][0]) ord.pb(ind);
            ord.pb(last);
            for(auto ind : f[0][1]) ord.pb(ind);
        }
        vi ans;
        for(auto ind : ord) for(auto x : q[ind]) ans.pb(x);
        win(ans);
        
    }
    
}