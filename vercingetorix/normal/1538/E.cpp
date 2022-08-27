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
map<string, ll> cnt;
map<string, string> e;
map<string, string> st;

int getcnt(string s) {
    int ret = 0;
    for(int i = 0; i + 4 <= s.size(); i++) {
        if(s.substr(i, 4) == "haha") ret++;
    }
    return ret;
}

vs split(string s) {
    vs ret;
    string cur;
    for(auto x : s) {
        if(x != ' ') cur.pb(x);
        else {
            ret.pb(cur);
            cur.clear();
        }
    }
    ret.pb(cur);
    return ret;
}

ll un(string name, string a, string b) {
    string addo = e[a];
    if(addo.size() > 3) addo = addo.substr(addo.size() - 3);
    string addor = st[b];
    while(addor.size() > 3) addor.pop_back();
    cnt[name] = cnt[a] + cnt[b] + getcnt(addo+addor);
    st[name] = st[a];
    if(st[name].size() < 3) st[name] += st[b];
    if(st[name].size() > 3) st[name].resize(3);
    e[name] = e[b];
    if(e[name].size() < 3) e[name] = e[a] + e[b];
    if(e[name].size() > 3) e[name] = e[name].substr(e[name].size() - 3);
    return cnt[name];
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    while(t--) {
        int n;
        scanf("%d\n", &n);
        ll res = 0;
        forn(i,0,n) {
            string s;
            getline(cin, s);
            vs op = split(s);
            string name = op[0];
            if(op[1] == ":=") {
                string val = op[2];
                cnt[name] = getcnt(val);
                e[name] = val;
                st[name] = val;
            }
            else {
                string n1 = op[2];
                string n2 = op[4];
                res = un(name, n1, n2);
            }
            res = cnt[name];
        }
        printf("%lld\n", res);
        
    }
    
    
}