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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d\n", &t);
    vpi mv = {mp(-1,0), mp(1,0), mp(0,1), mp(0, -1)};
    forn(afaf,0,t) {
        int n,m;
        scanf("%d %d\n", &n, &m);
        vs a(n);
        forn(i,0,n) getline(cin, a[i]);
        int lost = 0;
        int good = 0;
        forn(i,0,n) forn(j,0,m) {
            if (a[i][j] == 'B') {
                for(auto x : mv) {
                    int i1 = i + x.first;
                    int j1 = j + x.second;
                    if (i1 >= 0 && j1 >= 0 && i1 < n && j1 < m) {
                        if (a[i1][j1] == 'G') lost = 1;
                        else if (a[i1][j1] == '.') a[i1][j1] = '#';
                    }
                }
            }
            if (a[i][j] == 'G') good = 1;
        }
        vvi vis(n, vi(m, 0));
        vpi proc;
        if (lost) {
            cout<<"No\n";
            continue;
        }
        if (a[n-1][m-1] == '.') {
            proc.pb(mp(n-1, m-1));
            vis[n-1][m-1] = 1;
        }
        while(proc.size() > 0) {
            int i = proc.back().first;
            int j = proc.back().second;
            proc.pop_back();
            for(auto x : mv) {
                int i1 = i + x.first;
                int j1 = j + x.second;
                if (i1 >= 0 && j1 >= 0 && i1 < n && j1 < m) {
                    if (vis[i1][j1]) continue;
                    if (a[i1][j1] == '.' || a[i1][j1] == 'G') {
                        vis[i1][j1] = 1;
                        proc.pb(mp(i1,j1));
                    }
                }
            }
        }
        forn(i,0,n) forn(j,0,m) if (a[i][j] == 'G' && vis[i][j] == 0) lost = 1;
        if (lost) cout<<"No\n";
        else cout<<"Yes\n";
    }
}