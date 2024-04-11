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

vi p;
#ifdef LOCAL
const int B = 4;
const int A = 20;
#else
const int B = 320;
const int A = 100500;
#endif
int bad[A];
vi seg[A];
int segnum[A];
int segpos[A];
int vis[A];
int pseg[A];
int clen[A];
vi tp;
vi x, y;
int n;

void go() {
    int m = tp.size();
    forn(i,0,m) {
        if(tp[i] == 1) {
            bad[p[x[i]]] = 1;
            bad[p[y[i]]] = 1;
        }
    }
    forn(i,0,n) vis[i] = 0;
    forn(i,0,n) {
        if(bad[i]) {
            int cur =  i;
            segnum[cur] = i;
            segpos[cur] = seg[i].size();
            seg[i].pb(cur);
            vis[i] = 1;
            while(!bad[p[cur]]) {
                cur = p[cur];
                segnum[cur] = i;
                segpos[cur] = seg[i].size();
                seg[i].pb(cur);
                vis[cur] = 1;
            }
            pseg[i] = p[cur];
        }
    }
    forn(i,0,n) if(!vis[i]) {
        int cur = i;
        vis[i] = 1;
        segnum[cur] = i;
        segpos[cur] = seg[i].size();
        seg[i].pb(cur);
        pseg[i] = i;
        while(p[cur]!=i) {
            cur = p[cur];
            vis[cur] = 1;
            segnum[cur] = i;
            segpos[cur] = seg[i].size();
            seg[i].pb(cur);
        }
    }
    forn(i,0,m) {
        if(tp[i] == 1) {
            swap(pseg[segnum[x[i]]], pseg[segnum[y[i]]]);
        }
        else {
            int f = segnum[x[i]];
            int curs = f;
            int flen = 0;
            do {
                flen += seg[curs].size();
                curs = pseg[curs];
            } while(curs != f);
            int k = y[i];
            k %= flen;
            int curpos = segpos[x[i]];
            while(k > 0) {
                if(curpos + k >= seg[curs].size()) {
                    k -= seg[curs].size() - curpos;
                    curs = pseg[curs];
                    curpos = 0;
                }
                else {
                    curpos += k;
                    break;
                }
            }
            printf("%d\n", seg[curs][curpos]+1);
        }
    }
    forn(i,0,m) {
        if(tp[i] == 1) {
            bad[p[x[i]]] = 0;
            bad[p[y[i]]] = 0;
        }
    }
    forn(i,0,n) seg[i].clear();
}

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int qn;
    scanf("%d %d", &n, &qn);
    p.resize(n);
    forn(i,0,n) {
        scanf("%d", &p[i]);
        p[i]--;
    }
    
    while(qn > 0) {
        int tk = min(B, qn);
        qn-=tk;
        tp.resize(tk);
        x.resize(tk);
        y.resize(tk);
        forn(i,0,tk) {
            scanf("%d %d %d", &tp[i], &x[i], &y[i]);
            x[i]--;
            if(tp[i]==1) y[i]--;
        }
        go();
        forn(i,0,tk) if(tp[i] == 1) swap(p[x[i]], p[y[i]]);
    }
    
}