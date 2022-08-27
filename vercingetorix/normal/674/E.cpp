#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <cstring>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int q;
    scanf("%d", &q);
    const int mag = 50;
    vector<vector<double>> p(q, vd(mag, 1));
    vi par(q, -1);
    int cur = 1;
    forn(i,0,q) {
        int type, v;
        scanf("%d %d", &type, &v);
        v--;
        if(type == 1) {
            forn(i,0,mag) p[cur][i] = 1;
            par[cur] = v;
            double wasp = p[v][0];
            p[v][0] = p[v][0]/2;
            cur++;
            int curh = 1;
            while(par[v] >= 0 && curh<mag) {
                int u = par[v];
                double waspu = p[u][curh];
                p[u][curh] = p[u][curh] / (1+wasp) * (1+p[v][curh-1]);
                wasp = waspu;
                curh++;
                v=u;
                // update p[u][curh]
            }
        }
        else {
            double ans = 0;
            forn(i,0,mag) ans += 1-p[v][i];
            printf("%.10lf\n", ans);
        }
    }
}