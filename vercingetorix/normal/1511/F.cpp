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

const long long mod = 998244353 ;
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
vs a;
int valid[9][9][5][5];
int k;
ll mh[3][1000][1000];

void fmul(int a, int b, int c) {
    forn(i,0,k) forn(j,0,k) mh[c][i][j] = 0;
    forn(i,0,k) forn(j,0,k) {
        forn(p,0,k) mh[c][i][j] += mh[a][i][p] * mh[b][p][j] % mod;
        mh[c][i][j] %= mod;
    }
}

vvll fmpow(vvll & x, int kk) {
    forn(i,0,k) forn(j,0,k) mh[0][i][j] = x[i][j];
    int curd=0;
    int d2 = 1;
    while((kk & d2) == 0) {
        fmul(curd,curd,1-curd);
        d2 *= 2;
        curd = 1-curd;
    }
    kk -= d2;
    int curr = 2;
    forn(i,0,k) forn(j,0,k) mh[2][i][j] = mh[curd][i][j];
    while(kk > 0) {
        int fr = 3-curd-curr;
        fmul(curd, curd, fr);
        curd = fr;
        fr = 3-curd-curr;
        d2*=2;
        if(kk&d2) {
            fmul(curd, curr, fr);
            curr = fr;
            kk-=d2;
        }
    }
    vvll res(k, vll(k, 0));
    forn(i,0,k) forn(j,0,k) res[i][j] = mh[curr][i][j];
    return res;
}

vvll mul(const vvll & x, const vvll & y) {
    vvll res(k, vll(k, 0));
    forn(i,0,k) forn(j,0,k) {
        forn(p,0,k) res[i][j] += x[i][p] * y[p][j] % mod;
        res[i][j] %= mod;
    }
    return res;
}

vll mulv(const vvll & x, const vll & y) {
    vll res(k,0);
    forn(i,0,k) {
        forn(p,0,k) res[i] += x[i][p] * y[p] % mod;
        res[i] %= mod;
    }
    return res;
}

vvll mpow(vvll & x, int kk) {
    if(kk == 1) return x;
    vvll u = mpow(x, kk/2);
    vvll res = mul(u, u);
    if(kk%2) res = mul(res, x);
    return res;
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n, &m);
    a.pb(string(1,'#'));
    char c[100];
    forn(i,0,n) {
        scanf("%s", c);
        a.pb(string(c));
    }
    forn(i,1,n+1) {
        forn(j,1,n+1) {
            forn(p1,0,a[i].size()) {
                forn(p2,0,a[j].size()) {
//                    if(p1+1 == a[i].size() && p2+1==a[j].size()) continue;
                    int can = 1;
                    for(int k = -4; k<=4; k++) {
                        if(p1+k>=0 && p1+k<a[i].size() && p2+k>=0 && p2+k<a[j].size() && a[i][p1+k] != a[j][p2+k]) can = 0;
                    }
                    if(can) {
                        valid[i][j][p1][p2] = 1;
//                        if(p1 + 1 != a[i].size() && p2 + 1 != a[j].size()) valid[i][j][p1][p2] = 1;
//                        else if(p1+1==a[i].size()) {
//                            valid[0][j][0][p2] = 1;
//                        }
//                        else if(p2+1==a[j].size()) {
//                            valid[i][0][p1][0] = 1;
//                        }
                    }
                }
            }
        }
    }
    vvi state;
    state.pb(vi(4,0));
    forn(i,0,n+1)
        forn(j,0,n+1)
            forn(p1,0,a[i].size())
                forn(p2,0,a[j].size())
                    if(valid[i][j][p1][p2]) state.pb(vi({i,j,p1,p2}));
    map<vi, int> code;
    forn(i,0,state.size()) code[state[i]] = i;
    k = state.size();
//    vector<set<int>> g(k);
    vvll mat(k, vll(k, 0));
    forn(f,0,k) {
        int i = state[f][0];
        int j = state[f][1];
        int p1 = state[f][2];
        int p2 = state[f][3];
        p1++;
        p2++;
        if(p1 == a[i].size()) {
            p1 = 0;
            i = 0;
        }
        if(p2 == a[j].size()) {
            p2 = 0;
            j = 0;
        }
        if (i!=0 && j!=0) {
//            g[f].insert(code[vi({i,j,p1,p2})]);
            mat[code[vi({i,j,p1,p2})]][f]++;
        }
        else if(i==0 && j==0) {
            forn(i2,1,n+1) forn(j2,1,n+1) {
                int can = 1;
                int pt = 0;
                while(pt<a[i2].size() && pt<a[j2].size()) {
                    if(a[i2][pt] != a[j2][pt]) can = 0;
                    pt++;
                }
                if(can) {
                    int p12 = 0;
                    int p22 = 0;
                    int i3 = i2;
                    int j3 = j2;
                    if(p12 + 1 == a[i3].size() && p22 + 1 == a[j3].size()) {
                        i3 = 0;
                        j3 = 0;
                    }
//                    g[f].insert(code[vi({i3,j3,p12,p22})]);
                    mat[code[vi({i3,j3,p12,p22})]][f]++;
                }
            }
        }
        else if(i == 0) {
            forn(i2,1,n+1) {
                int can = 1;
                int pt = 0;
                while(pt<a[i2].size() && p2+pt < a[j].size()) {
                    if(a[i2][pt] != a[j][p2+pt]) can = 0;
                    pt++;
                }
                if(can) {
                    int i3 = i2;
                    int j3 = j;
                    int p12 = 0;
                    int p22 = p2;
                    if(p12 + 1 == a[i3].size() && p22 + 1 == a[j3].size()) {
                        i3 = 0;
                        j3 = 0;
                        p22 =0;
                    }
//                    g[f].insert(code[vi({i3,j3,p12,p22})]);
                    mat[code[vi({i3,j3,p12,p22})]][f]++;
                }
            }
        }
        else if(j == 0) {
            forn(j2,1,n+1) {
                int can = 1;
                int pt = 0;
                while(pt<a[j2].size() && p1+pt < a[i].size()) {
                    if(a[j2][pt] != a[i][p1+pt]) can = 0;
                    pt++;
                }
                if(can) {
                    int i3 = i;
                    int j3 = j2;
                    int p12 = p1;
                    int p22 = 0;
                    if(p12 + 1 == a[i3].size() && p22 + 1 == a[j3].size()) {
                        i3 = 0;
                        j3 = 0;
                        p12 = 0;
                    }
//                    g[f].insert(code[vi({i3,j3,p12,p22})]);
                    mat[code[vi({i3,j3,p12,p22})]][f]++;
                }
            }
        }
    }
    
    vvi g(k);
    forn(i,0,k) forn(j,0,k) if(mat[i][j] > 0) g[j].pb(i);
    vi vis(k, 0);
    vi q;
    q.pb(0);
    vis[0] = 1;
    while(!q.empty()) {
        int v = q.back();
        q.pop_back();
        for(auto u : g[v]) if(vis[u] == 0) {
            vis[u] = 1;
            q.pb(u);
        }
    }
    vi comp;
    forn(i,0,k) if(vis[i]) comp.pb(i);
    int kwas = k;
    k = comp.size();
    vvll compmat(k, vll(k, 0));
    forn(i,0,k) forn(j,0,k) compmat[i][j] = mat[comp[i]][comp[j]];

    int kkk = k*2;
    vpi qp;
    vi red;
    forn(i,0,k) red.pb(i);
    for(auto x : comp) {
        if(state[x][0] != state[x][1] || state[x][2] != state[x][3]) {
            kkk--;
            int xto = code[vi({state[x][1], state[x][0], state[x][3], state[x][2]})];
            if(xto > x) qp.pb(mp(xto, x));
            int pt2 = 0;
            int pt = 0;
            while(comp[pt2] != xto) pt2++;
            while(comp[pt] != x) pt++;
            if(pt2>pt) red[pt2] = pt;
        }
    }
    kkk/=2;
    vi comp2;
    forn(i,0,k) {
        if(red[i] != i) {
            int j = red[i];
            forn(p,0,k) compmat[j][p] += compmat[i][p];
//            forn(p,0,k) compmat[p][j] += compmat[p][i];
//            compmat[j][j]/=2;
        }
        else comp2.pb(i);
    }
    
    k = comp2.size();
    vvll compmat2(k, vll(k, 0));
    forn(i,0,k) forn(j,0,k) compmat2[i][j] = compmat[comp2[i]][comp2[j]];
    
//    k = kwas;
    vvll res = fmpow(compmat2, m);
    vll d(k,0);
    d[0] = 1;
    vll ans = mulv(res, d);
    ll fin = 0;
    forn(ff,0,k) {
        int f = comp[comp2[ff]];
//        int f = ff;
        int i = state[f][0];
        int j = state[f][1];
        int p1 = state[f][2];
        int p2 = state[f][3];
        if(p1+1 == a[i].size()) {
            p1 = 0;
            i = 0;
        }
        if(p2+1 == a[j].size()) {
            p2 = 0;
            j = 0;
        }
        if(i == 0 && j == 0) fin += ans[ff];
    }
    cout<<fin%mod;
    
    
    
    
}