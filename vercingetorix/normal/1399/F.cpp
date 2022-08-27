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
int d[6000][6000];
//int has[6000][6000];
vi rtol[6000];
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    scanf("%d", &t);
    while(t--) {
        int n;
        scanf("%d",&n);
        vi l(n),r(n);
        set<int> en;
        forn(i,0,n){
            scanf("%d %d", &l[i], &r[i]);
            en.insert(l[i]);
            en.insert(r[i]);
        }
        int pt = 0;
        map<int, int> to;
        for(auto x : en) to[x] = pt++;
        forn(i,0,n) l[i] = to[l[i]];
        forn(i,0,n) r[i] = to[r[i]];
        forn(i,0,pt) forn(j,0,pt) d[i][j] = 0;
//        forn(i,0,pt) forn(j,0,pt) has[i][j] = 0;
        forn(i,0,n) rtol[r[i]].pb(l[i]);
//        forn(i,0,n) has[l[i]][r[i]] = 1;
        forn(len,0,pt) {
            forn(st,0,pt-len) {
                int en = st+len;
                if(len > 0) d[st][en] = max(d[st+1][en], d[st][en-1]);
                int hit= 0;
                for(auto x : rtol[en]){
                    if(x>st) {
                        d[st][en] = max(d[st][en], d[st][x-1] + d[x][en]);
                    }
                    else if(x==st) hit = 1;
                }
                d[st][en] +=hit;
            }
        }
        printf("%d\n", d[0][pt-1]);
        forn(i,0,pt) rtol[i].clear();
    }
    
}