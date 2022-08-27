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
const int MAXN = 1000000;
int parent[MAXN];
int rk[MAXN];

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

int N;


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int M;
    scanf("%d %d", &N, &M);
    ll n = N;
    ll m = M;
    vll deg(n,0);
    forn(i,0,n) make_set(i);
    int s = 0;
    vpi e;
    ll c0 = 0;
    vi used(n,0);
    forn(i,0,m) {
        int u,v;
        scanf("%d %d", &u, &v);
        u--;
        v--;
        used[u]=1;
        used[v]=1;
        if(i==0) {
            s=u;
        }
        if(u==v) {
            c0++;
            continue;
        }
        deg[u]++;
        deg[v]++;
        union_sets(u, v);
    }
    forn(i,0,n) {
        if(used[i] && find_set(s) != find_set(i)) {
            cout<<0;
            return 0;
        }
    }
    ll ans = c0*(c0-1)/2 + c0*(m-c0);
    forn(i,0,n) {
        ans+=deg[i]*(deg[i]-1)/2;
    }
    cout<<ans;
}