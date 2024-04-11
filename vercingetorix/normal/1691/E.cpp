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
const int A = 100500;
int parent[A];
int rk[A];
void make_set (int v) {
    parent[v] = v;
    rk[v] = 0;
}

int find_set (int v) {
    if (v == parent[v])
        return v;
    return parent[v] = find_set (parent[v]);
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        if (rk[a] < rk[b])
            swap (a, b);
        parent[b] = a;
        if (rk[a] == rk[b])
            ++rk[a];
    }
}
int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int ta;
    read(ta);
    forn(ifa,0,ta) {
        int n;
        scanf("%d", &n);
        vi c(n), l(n), r(n);
        forn(i,0,n) scanf("%d %d %d", &c[i], &l[i], &r[i]);
        vpi ev;
        forn(i,0,n) {
            --l[i];
            --r[i];
            ev.pb(mp(r[i]+1, -i-1));
            ev.pb(mp(l[i], i+1));
        }
        srt(ev);
        forn(i,0,n) make_set(i);
        set<int> op[2];
        for(auto x : ev) {
            int ind = abs(x.second)-1;
            if(x.second < 0) op[c[ind]].erase(ind);
            else {
                int col = c[ind];
                int rind = -1;
                int best = -2e9;
                for(auto dif : op[col^1]) {
                    if(r[dif] > best) {
                        best = r[dif];
                        rind = dif;
                    }
                }
                if(rind != -1) {
                    for(auto dif : op[col^1]) union_sets(dif, ind);
                    op[col^1].clear();
                    op[col^1].insert(rind);
                }
                op[col].insert(ind);
            }
            
        }
        int ans =  0;
        forn(i,0,n) if(find_set(i) == i) ans++;
        printf("%d\n", ans);
    }
    
    
}