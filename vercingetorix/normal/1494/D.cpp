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
const int A = 500;
int parent[A];
int rk[A];
//int sal[A];
vi sot[A];
void make_set (int v) {
    parent[v] = v;
//    rk[v] = 0;
    sot[v].pb(v);
}

int find_set (int v) {
//    if (v == parent[v])
//        return v;
    return parent[v];
}

void union_sets (int a, int b) {
    a = find_set (a);
    b = find_set (b);
    if (a != b) {
        for(auto x : sot[b]) {
            sot[a].pb(x);
            parent[x] = a;
        }
        sot[b].clear();
    }
}

int num = 0;
vi temp;

int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n;
    read(n);
    vector<pair<int, pi>> q;
    int sal[10000];
    forn(i,0,n) {
        forn(j,0,n) {
            int x;
            scanf("%d", &x);
            if(i == j) {
                make_set(i);
                sal[i] = x;
            }
            else {
                q.pb(mp(x, mp(i,j)));
            }
        }
    }
    num = n;
    srt(q);
    int r = 0;
//    vi ch[10000];
    
    vpi ans;
    while(r < q.size()) {
        int pr = r+1;
        while(pr<q.size() && q[pr].first == q[r].first) pr++;
        forn(i,r,pr) {
            int u = q[i].second.first;
            int v = q[i].second.second;
            union_sets(u, v);
            temp.pb(u);
        }
        for(auto v : temp) {
            if(sot[parent[v]].size() > 1) {
                for(auto x : sot[parent[v]]) {
                    ans.pb(mp(x, num));
                }
                sal[num] = q[r].first;
                sot[parent[v]] = vi(1, num++);
            }
        }
        r = pr;
    }
    printf("%d\n", num);
    forn(i,0,num) printf("%d ", sal[i]); printf("\n");
    printf("%d\n", num);
    for(auto x : ans) printf("%d %d\n", x.first+1, x.second+1);
    
}