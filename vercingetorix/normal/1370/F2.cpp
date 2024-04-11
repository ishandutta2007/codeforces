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
vvi e;
vvi lev;
int n;

void dfs1(int u, int p, int l) {
    lev[l].pb(u);
    for(auto v : e[u]) if(v != p) {
        dfs1(v, u, l+1);
    }
}

pi req(vi a) {
    string s = "? " + to_string(a.size());
    for(auto x : a) s += " " + to_string(x + 1);
    cout<<s<<endl;
    cout.flush();
    pi res;
    cin >> res.first >> res.second;
    if(res.first == -1) {
        exit(1);
    }
    res.first -- ;
    return res;
}

int main()
{
//#ifndef ONLINE_JUDGE
//    freopen("input.txt", "rt", stdin);
//    freopen("output.txt", "wt", stdout);
//#endif
    int t;
    cin>>t;
    forn(afjb,0, t) {
        cin>>n;
        e = vvi();
        lev = vvi();
        lev.resize(2*n+10);
        e.resize(n);
        forn(i,0,n-1) {
            int u,v;
            cin>>u>>v;
            u--; v--;
            e[u].pb(v);
            e[v].pb(u);
        }
        string s = "? " + to_string(n);
        forn(i,1,n+1) s += " " + to_string(i);
        cout<<s<<endl;
        cout.flush();
        int root,d;
        cin>>root>>d;
        root--;
        dfs1(root, -1, 0);
        int r = d + 1;
        while(r > 1 && lev[r-1].size() == 0) r--;
        int l = (d-1)/2;
        int curt = root;
        while (r - l > 1) {
            int m = (r + l) / 2;
//            while(lev[m].size() == 0 && m > l) m--;
            auto res = req(lev[m]);
            if (res.second > d) r = m;
            else {
                l = m;
                curt = res.first;
            }
        }
        lev = vvi();
        lev.resize(n);
        dfs1(curt, -1, 0);
        auto res = req(lev[d]);
        cout << "! " + to_string(curt+1) + " " + to_string(res.first+1) <<endl;
        cout.flush();
        string ss;
        cin>>ss;
        if(ss == "Correct") continue;
        else break;
        
    }
}