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

const int MAXN = 100000;
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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    scanf("%d %d %d\n", &n, &m, &k);
    vs a(n);
    forn(i,0,n) getline(cin, a[i]);
    int ocean = 3000;
    make_set(ocean);
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == '.') make_set(i*m+j);
    }
    forn(i,0,n) forn(j,0,m) {
        if(i<n-1 && a[i][j]=='.' && a[i+1][j] == '.') union_sets(i*m+j, i*m+m+j);
        if(j<m-1 && a[i][j]=='.' && a[i][j+1] == '.') union_sets(i*m+j, i*m+1+j);
        if(a[i][j] == '.' && (i==0 || j==0 || i==n-1 || j==m-1)) union_sets(i*m+j, ocean);
    }
    vi cnt(3001,0);
    forn(i,0,n) forn(j,0,m) {
        if(a[i][j] == '.') cnt[find_set(i*m+j)]++;
    }
    int skip = find_set(ocean);
    vpi lakes;
    forn(i,0,3001) {
        if(i==skip) continue;
        if(cnt[i] > 0) lakes.pb(mp(cnt[i], i));
    }
    sort(all(lakes));
    int ans = 0;
    forn(i,0,lakes.size()-k) {
        ans += lakes[i].first;
        for(auto v : lst[lakes[i].second]) {
            a[v/m][v%m] = '*';
        }
    }
    cout<<ans<<endl;
    forn(i,0,n) cout<<a[i]<<endl;
    
}