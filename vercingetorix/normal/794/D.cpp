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

#define pb push_back
#define mp make_pair
const ll A = 300000;
set<ll> e;
vi nb[A];
int col[A];
vi cols[2*A+1];

int vis[A];

bool check() {
    for(auto x : e) {
        int u = x/A;
        int v = x%A;
        if(abs(col[u] - col[v]) > 1) return false;
    }
    forn(val,0,2*A+1) {
        forn(i,0,cols[val].size()) {
            forn(j,i+1,cols[val].size()) {
                int u = cols[val][i];
                int v = cols[val][j];
                if(u>v) swap(u,v);
                if(e.find(A*u+v) == e.end()) return false;
            }
        }
    }
    forn(val,0,2*A) {
        for(auto xu : cols[val]) {
            for(auto xv : cols[val+1]) {
                int u = xu;
                int v = xv;
                if(u>v) swap(u,v);
                if(e.find(A*u+v) == e.end()) return false;
            }
        }
    }
    return true;
}

bool ce(int u, int v) {
    if(u>v) swap(u,v);
    return (e.find(A*u+v) != e.end());
}

void dfs(int v, int p) {
    for(auto u : nb[v]) {
        if(u==p) continue;
        if(vis[u]) continue;
        int to;
        if(col[v] < A) {
            int t1 = cols[col[v] + 1][0];
            int t2 = cols[col[v] + 2][0];
            if(!ce(t1,u)) to = col[v] - 1;
            else if(!ce(t2, u)) to = col[v];
            else to = col[v] + 1;
        }
        else if(col[v] > A) {
            int t1 = cols[col[v] - 1][0];
            int t2 = cols[col[v] - 2][0];
            if(!ce(t1,u)) to = col[v] + 1;
            else if(!ce(t2, u)) to = col[v];
            else to = col[v] - 1;
        }
        else {
            int t1 = cols[col[v] - 1][0];
            int t2 = cols[col[v] + 1][0];
            if(!ce(t1,u)) to = col[v] + 1;
            else if(!ce(t2, u)) to = col[v] - 1;
            else to = col[v];
        }
        col[u] = to;
        cols[to].pb(u);
        vis[u] = 1;
        dfs(u,v);
    }
}
bool found = false;
vi path;
int vis2[A];
void dfsp(int v, int p, int to) {
    if(v == to) {
        found = true;
        path.pb(v);
        return;
    }
    for(auto u : nb[v]) {
        if(u==p) continue;
        if(vis2[u]) continue;
        vis2[u] = 1;
        dfsp(u, v, to);
        if(found) {
            path.pb(v);
            return;
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--; v--;
        if(u>v) swap(u,v);
        e.insert(A*u+v);
        nb[u].pb(v);
        nb[v].pb(u);
    }
    bool done = false;
    int a,b,c;
    forn(u,0,n) {
        forn(v,u+1,n) {
            if(e.find(A*u+v) == e.end()) {
                done = true;
                vis2[u] = 1;
                dfsp(u,-1,v);
                reverse(all(path));
                int ind = 1;
                while(ce(path[ind+1], u)) ind++;
                a = u;
                b = path[ind];
                c = path[ind+1];
                break;
            }
            
        }
        if(done) break;
    }
//    forn(i,0,n) {
//        forn(iu,0,nb[i].size()) {
//            int ud = nb[i][iu];
//            forn(iv,iu+1,nb[i].size()) {
//                int v = nb[i][iv];
//                int u = ud;
//                if(u>v) swap(u,v);
//                if(e.find(A*u+v) == e.end()) {
//                    done = true;
//                    a = u;
//                    b = i;
//                    c = v;
//                    break;
//                }
//            }
//            if(done) break;
//        }
//        if(done) break;
//    }
    if(!done) {
        printf("YES\n");
        forn(i,0,n) printf("1 ");
        return 0;
    }
    col[a] = A-1;
    col[b] = A;
    col[c] = A+1;
    cols[A-1].pb(a);
    cols[A].pb(b);
    cols[A+1].pb(c);
    vis[a] = 1;
    vis[b] = 1;
    vis[c] = 1;
    dfs(a,b);
    dfs(c,b);
    if(check()) {
        printf("YES\n");
        forn(i,0,n) printf("%d ", col[i]);
    }
    else printf("NO\n");
}