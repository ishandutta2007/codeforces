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
typedef std::vector<vvi> vvvi;
typedef vector<vll> vvll;
typedef std::vector<std::pair<int, int> > vpi;
typedef vector<vpi> vvpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 998244353;
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

vi v[501][501];
int cnt[501][501];
int n;
vvi a;
vpi q;
vi used;

bool nb(int i1, int i2) {
    forn(j,0,n) if(a[i1][j] == a[i2][j]) return true;
    return false;
}

void del(int k) {
    used[k] = -1;
    forn(j,0,n) {
        cnt[a[k][j]][j] --;
        if(cnt[a[k][j]][j] == 1) q.pb(mp(a[k][j], j));
    }
}

void take(int k) {
    used[k] = 1;
    forn(j,0,n) cnt[a[k][j]][j] = 0;
    forn(i,0,2*n) if(used[i] == 0) forn(j,0,n) if(a[k][j] == a[i][j]) {
        del(i);
        break;
    }
}

void go(pi x) {
    if(cnt[x.first][x.second] == 0) return;
    for(auto ind : v[x.first][x.second]) if(used[ind] == 0) take(ind);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int t;
    read(t);
    while(t--) {
        
        read(n);
        a = vvi (2*n, vi(n));
        forn(i,0,2*n) {
            forn(j,0,n) {
                scanf("%d", &a[i][j]);
                a[i][j]--;
                v[a[i][j]][j].pb(i);
                cnt[a[i][j]][j]++;
            }
        }
        used = vi (2*n, 0);
        vpi proc;
        forn(i,0,n) forn(j,0,n) if(v[i][j].size() == 1) q.pb(mp(i,j));
        int pt = 0;
        int ans = 1;
        while(pt < 2*n) {
            while(!q.empty()) {
                auto x = q.back();
                q.pop_back();
                go(x);
            }
            while(pt<2*n && used[pt]!=0) pt++;
            if(pt == 2*n) break;
            ans = 2*ans%mod;
            take(pt);
        }
        printf("%d\n", ans);
        forn(i,0,2*n) if(used[i] == 1) {
            printf("%d ", i+1);
        }
         printf("\n");
        forn(i,0,n) forn(j,0,n) v[i][j].clear();
        forn(i,0,n) forn(j,0,n) cnt[i][j] = 0;
    }
    
}