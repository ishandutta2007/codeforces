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
    set<vi> pos;
    forn(i,0,625*625) {
        vi a;
        int m = i;
        forn(j,0,8) {
            a.pb(m%5);
            m/=5;
        }
        sort(all(a));
        pos.insert(a);
    }
    map<vi, int> pnum;
    int c = 0;
    vvi ppos;
    for(auto x : pos) pnum[x] = c++;
    for(auto x : pos) ppos.pb(x);
    vvi g(495*495);
    vvi grev(495*495);
    forn(i,0,495*495) {
        int i1 = i/495;
        int i2 = i%495;
        vi p1 = ppos[i1];
        vi p2 = ppos[i2];
        forn(a,0,8) {
            if(p1[a]==0) continue;
            if(a>0 && p1[a] == p1[a-1]) continue;
        forn(b,0,8) {
            if(p2[b] == 0) continue;
            if(b>0 && p2[b] == p2[b-1]) continue;
            vi np = p1;
            np[a] = (np[a] + p2[b])%5;
            sort(all(np));
            int i3 = pnum[np];
            int to = i2*495 + i3;
            g[i].pb(to);
            grev[to].pb(i);
        }
        }
    }
    vi gnum(495*495);
    forn(i,0,495*495) gnum[i] = g[i].size();
    vi win(495*495, -1);
    forn(i,0,495) win[i*495] = 0;
    vi q;
    forn(i,0,495) q.pb(i*495);
    while(!q.empty()) {
        int v = q.back();
        q.pop_back();
        if(win[v] == 0) {
            for(auto x : grev[v]) {
                if(win[x] == -1) {
                    win[x] = 1;
                    q.pb(x);
                }
            }
        }
        else {
            for(auto x : grev[v]) {
                if(win[x] != -1) continue;
                gnum[x] --;
                if(gnum[x] == 0) {
                    win[x] = 0;
                    q.pb(x);
                }
            }
        }
    }
    int qnum;
    scanf("%d", &qnum);
    forn(it,0,qnum) {
        int tr;
        scanf("%d", &tr);
        readv(a,8);
        readv(b,8);
        if(tr==1) swap(a,b);
        sort(all(a));
        sort(all(b));
        int i1 = pnum[a];
        int i2 = pnum[b];
        int x = win[495*i1+i2];
        if(x==-1) printf("Deal\n");
        else if(x==tr) printf("Bob\n");
        else printf("Alice\n");
//        else printf("Deal\n");
    }
    
}