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

const int MAXN = 200000;
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
    int n,q;
    scanf("%d %d", &n, &q);
    set<int> nd;
    forn(i,0,n-1) nd.insert(i);
    
    forn(i,0,n) {
    
        make_set(i);
    }
    int t,x,y;
    forn(i,0,q) {
        scanf("%d %d %d", &t,&x,&y);
        x--;
        y--;
        if(t == 1) {
            union_sets(x, y);
        }
        if(t==2) {
            auto f = nd.lower_bound(x);
            vi del;
            while(f != nd.end() && (*f) < y) {
                del.pb(*f);
                union_sets((*f), (*f)+1);
                f++;
            }
            for(auto u:del) nd.erase(u);
        }
        if(t==3) {
            if(find_set(x) == find_set(y)) printf("YES\n");
            else printf("NO\n");
        }
    }
}