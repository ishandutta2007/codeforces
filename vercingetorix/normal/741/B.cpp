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

const int MAXN = 1000;
vector<int> lst[MAXN];
vi wt(1000,0);
vi bt(1000,0);
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
        wt[a] += wt[b];
        bt[a] += bt[b];
        wt[b] = 0;
        bt[b] = 0;
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,w;
    scanf("%d %d %d", &n, &m, &w);
    
    forn(i,0,n) scanf("%d", &wt[i]);
    forn(i,0,n) scanf("%d", &bt[i]);
    vi wwas = wt;
    vi bwas = bt;
    forn(i,0,n) make_set(i);
    forn(i,0,m) {
        int x,y;
        scanf("%d %d", &x, &y);
        x--;
        y--;
        union_sets(x, y);
    }
    vi d(1001, 0);
    forn(i,0,n) {
        if(wt[i] > 0) {
            vi d2 = d;
            for(int j = 1000; j >= wt[i]; j--) {
                d2[j] = max(d2[j], d[j-wt[i]] + bt[i]);
            }
            for(auto ind : lst[i]) {
                for(int j = 1000; j >= wwas[ind]; j--) {
                    d2[j] = max(d2[j], d[j-wwas[ind]] + bwas[ind]);
                }
            }
            d = d2;
        }
    }
    int ans = 0;
    forn(i,0,w+1) {
        ans = max(ans, d[i]);
    }
    cout<<ans;
    
}