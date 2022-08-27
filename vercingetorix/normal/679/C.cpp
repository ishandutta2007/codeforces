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

const int MAXN = 250000;
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
vvi b,a;
int n,k;
vi cc(250000,0);
int total;
vvi diff = {{0,1}, {0,-1}, {1,0}, {-1,0}};
vi s;

bool valid(int i, int j) {
    return (i>=0 && j>=0 && i<n && j<n);
}

void add2(int i, int j) {
    cc[b[i][j]]++;
    if(cc[b[i][j]] == 1) total += s[b[i][j]];
}

void del2(int i, int j) {
    cc[b[i][j]]--;
    if(cc[b[i][j]] == 0) total -= s[b[i][j]];
}

void add(int i, int j) {
    cc[b[i][j]]++;
    if(cc[b[i][j]] == 1) total += s[b[i][j]];
//    for(auto p : diff) {
//        int x = i+p[0];
//        int y = j+p[1];
//        if(valid(i+p[0], j+p[1])) {
//            if(a[x][y] == 1) continue;
//            cc[b[x][y]]++;
//            if(cc[b[x][y]] == 1) total += s[b[x][y]];
//        }
//    }
    if(i>0 && a[i-1][j]==0) add2(i-1, j);
    if(i<n-1 && a[i+1][j]==0) add2(i+1, j);
    if(j>0 && a[i][j-1]==0) add2(i, j-1);
    if(j<n-1 && a[i][j+1]==0) add2(i, j+1);
}

void del(int i, int j) {
    cc[b[i][j]]--;
    if(cc[b[i][j]] == 0) total -= s[b[i][j]];
//    for(auto p : diff) {
//        int x = i+p[0];
//        int y = j+p[1];
//        if(valid(i+p[0], j+p[1])) {
//            if(a[x][y] == 1) continue;
//            cc[b[x][y]]--;
//            if(cc[b[x][y]] == 0) total -= s[b[x][y]];
//        }
//    }
    if(i>0 && a[i-1][j]==0) del2(i-1, j);
    if(i<n-1 && a[i+1][j]==0) del2(i+1, j);
    if(j>0 && a[i][j-1]==0) del2(i, j-1);
    if(j<n-1 && a[i][j+1]==0) del2(i, j+1);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &k);
    a= vvi(n, vi(n));
    string ss;
    forn(i,0,n) {
        getline(cin, ss);
        forn(j,0,n) {
            if(ss[j] == '.') a[i][j] = 0;
            else a[i][j] = 1;
        }
    }
    forn(i,0,n*n) make_set(i);
    forn(i,0,n) forn(j,0,n-1) {
        if(a[i][j] + a[i][j+1] == 0) union_sets(i*n+j, i*n+j+1);
    }
    forn(i,0,n-1) forn(j,0,n) {
        if(a[i][j] + a[i+1][j] == 0) union_sets(i*n+j, i*n+j+n);
    }
    vi comp;
    forn(i,0,n) forn(j,0,n) {
        comp.pb(find_set(i*n+j));
    }
    sort(all(comp));
    int cnt = 0;
    b = vvi(n, vi(n,-1));
    forn(i,0,n*n) {
        if(i>0 && comp[i]==comp[i-1]) continue;
        for(auto v : lst[comp[i]]) {
            b[v/n][v%n] = cnt;
        }
        s.pb(lst[comp[i]].size());
        cnt++;
    }
    int ans = 0;
    total  = 0;
    forn(i,0,k) forn(j,0,k) add(i, j);
    ans = max(ans,total);
    int t = 0;
    int l = 0;
    int r = k-1;
    int d = k-1;
    forn(down, 0, n-k+1) {
        forn(lr, 0, n-k) {
            if(down%2==0) {
                forn(i,t,d+1) del(i,l);
                forn(i,t,d+1) add(i,r+1);
                l++; r++;
            }
            else {
                forn(i,t,d+1) add(i,l-1);
                forn(i,t,d+1) del(i,r);
                l--; r--;
            }
            ans = max(ans,total);
        }
        
        if(down == n-k) break;
        forn(i,l,r+1) del(t,i);
        forn(i,l,r+1) add(d+1,i);
        ans = max(ans,total);
        t++; d++;
    }
    cout<<ans;
    
    
}