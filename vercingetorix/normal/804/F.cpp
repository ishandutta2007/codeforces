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
#include <random>
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

long long gcd(long long a, long long b){
    if(a==0) return b;
    if(b==0) return a;
    if(a>b) return gcd(b, a%b);
    return gcd(a,b%a);
}

vvll cnk(5001, vll(5001, 0));
//vvi g,gr;
//vpi e;

char g[5000][5000];
char reach[5000][5000];
//char has[5000][5000];

const int MAXN = 5100;
vector<int> lst[MAXN];
int parent[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
}

int find_set (int v) {
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            parent[v] = a;
            lst[a].push_back (v);
        }
    }
}

vector<char> used;
vector<int> order, component;

int n,a,b;

void dfs1 (int v) {
    used[v] = true;
    forn(u,0,n) if(g[v][u])
        if (!used[ u ])
            dfs1 (u);
    order.push_back (v);
}

void dfs2 (int v) {
    used[v] = true;
    component.push_back (v);
//    for (size_t i=0; i<gr[v].size(); ++i)
    forn(u,0,n) if(g[u][v])
        if (!used[ u ])
            dfs2 (u);
}

vi ss;
vs s;

void cond() {
    used.assign (n, false);
    for (int i=0; i<n; ++i)
        if (!used[i])
            dfs1 (i);
    used.assign (n, false);
    for (int i=0; i<n; ++i) {
        int v = order[n-1-i];
        if (!used[v]) {
            dfs2 (v);
            forn(j,0,component.size() - 1) {
                int a = component[j];
                int b = component[j+1];
                union_sets(a, b);
            }
            component.clear();
        }
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    forn(i,0,5001) cnk[i][0] = 1;
    forn(i,1,5001) {
        forn(j,1,min(i+1,5001)) {
            cnk[i][j] = (cnk[i-1][j] + cnk[i-1][j-1])%mod;
        }
    }
    
    scanf("%d %d %d\n", &n, &a, &b);
//    g.resize(n);
//    gr.resize(n);
    forn(i,0,n) make_set(i);
    forn(i,0,n) {
//        string s;
        char c[5001];
        scanf("%s", c);
        string s(c);
//        getline(cin, s);
        forn(j,0,n) {
            if(s[j] == '1') {
                g[i][j] = 1;
//                g[i].pb(j);
//                gr[j].pb(i);
//                e.pb(mp(i,j));
            }
        }
    }
    cond();
    vi grp;
    ss.resize(n);
    s.resize(n);
    char c[2000001];
    forn(i,0,n) {
//        scanf("%d ", &ss[i]);
//        getline(cin, s[i]);
        scanf("%d %s", &ss[i], c);
        s[i] = string(c);
//        char c;
        
        for(auto & c : s[i]) if(c=='0') c= '1'; else c='0';
//        cout<<s[i]<<'|'<<endl;
    }
//    if(n==5000) {
//        cout<<"GG";
//        return 0;
//    }
    vvi ns(n);
    forn(i,0,n) {
        if(lst[i].size() > 0) {
            grp.pb(i);
            int d = 0;
            for(auto v : lst[i]) {
                d = gcd(d, ss[v]);
            }
            ns[i] = vi(d,0);
            for(auto v : lst[i]) {
                forn(j, 0, ss[v]) {
                    if (s[v][j] == '0') ns[i][j%d] = 1;
                }
            }
        }
    }
//    set<pi> ced;
//    vvi has(n, vi(n,0));
    vvi dout(n);
    vi din(n,0);
//    for(auto x : e) {
    forn(i,0,n) forn(j,0,n) {
        if(g[i][j] != 1) continue;
        int a = find_set(i);
        int b = find_set(j);
        if (a != b && reach[a][b] == 0) {
            din[b]++;
            dout[a].pb(b);
//            has[a][b] = 1;
            forn(k,0,n) {
                reach[a][k] |= reach[b][k];
            }
            reach[a][b] = 1;
        }
    }
    vi done(n,0);
    int did = 0;
    while(did < n) {
        forn(i,0,n) {
            if (done[i]) continue;
            if (din[i] == 0) {
                for(auto u : dout[i]) {
                    int a = ns[i].size();
                    int b = ns[u].size();
                    int d = gcd(a,b);
                    forn(res,0,d) {
                        int can = 0;
                        for(int ta = res; ta < a; ta += d) if(ns[i][ta]) can = 1;
                        if (can) for(int tb = res; tb < b; tb += d) ns[u][tb] = 1;
                    }
                    din[u]--;
                }
                done[i] = 1;
                did++;
            }
        }
    }
    forn(i,0,n) {
        int host = find_set(i);
        int d = ns[host].size();
        forn(j,0,ss[i]) {
            if(s[i][j] == '1' && ns[host][j%d] == 1) s[i][j] = '2';
        }
    }
    vi amx, amn;
    forn(i,0,n) {
        int mn = 0;
        int mx = 0;
        for(auto c : s[i]) {
            if(c == '0') mn++;
            else if(c=='2') mx++;
        }
        mx += mn;
        amx.pb(mx);
        amn.pb(mn);
//        cout<<s[i]<<' '<<mn<<' '<<mx<<endl;
    }
    sort(all(amx));
    sort(all(amn));
    reverse(all(amx));
    reverse(all(amn));
    ll ans = 0;
    int pt = 0;
    forn(i,0,n) {
        int cur = amx[i];
        while(amn[pt] > cur) pt++;
//        cout << pt <<' '<<i-pt << endl;
        forn(x, max(pt+b-a, 0), min(b,pt+1)) {
            ans = (ans + cnk[pt][x] * cnk[i-pt][b-1-x]) % mod;
        }
    }
    cout<<ans;
    

}