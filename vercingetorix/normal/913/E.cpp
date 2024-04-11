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

map<int, string> f,e,t;

map<string, int> val;
map<int, string> ans;

void upd(string & a, string b) {
    if(a=="" || a.size() > b.size() || (a.size() == b.size() && b<a)) a=b;
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    val["x"] = 240;
    val["y"] = 204;
    val["z"] = 170;
    f[val["x"]] = "x";
    f[val["y"]] = "y";
    f[val["z"]] = "z";
    
    forn(it,0,10) {
        forn(i,0,256) {
            if(!f[i].empty()) upd(f[255^i], "!"+f[i]);
            if(!e[i].empty()) upd(f[i], "("+e[i]+")");
        }
        forn(i,0,256) if(!f[i].empty()) upd(t[i], f[i]);
        forn(i,0,256) forn(j,0,256) {
            if(!t[i].empty() && !f[j].empty()) {
                upd(t[i&j], t[i]+"&"+f[j]);
            }
        }
        forn(i,0,256) if(!t[i].empty()) upd(e[i], t[i]);
        forn(i,0,256) forn(j,0,256) {
            if(!e[i].empty() && !t[j].empty()) {
                upd(e[i|j], e[i]+"|"+t[j]);
            }
        }
    }
    forn(i,0,256) {
        if(!f[i].empty()) upd(ans[i], f[i]);
        if(!t[i].empty()) upd(ans[i], t[i]);
        if(!e[i].empty()) upd(ans[i], e[i]);
    }
    forn(i,0,256) {
//        cout<<i<<' '<<ans[i]<<endl;
    }
    int n;
    scanf("%d\n", &n);
    forn(i,0,n) {
        string s;
        getline(cin, s);
        int res= 0;
        forn(j,0,8) res+=(s[j]-'0')*(1<<j);
        printf("%s\n", ans[res].c_str());
    }
}