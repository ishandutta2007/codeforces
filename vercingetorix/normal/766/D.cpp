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

const int MAXN = 200000;
vector<int> lst[MAXN];
int parent[MAXN];
int sgn[MAXN];

void make_set (int v) {
    lst[v] = vector<int> (1, v);
    parent[v] = v;
    sgn[v] = 1;
}

int find_set (int v) {
    return parent[v];
}

string union_sets (int a, int b, int sg) {
    int ap = find_set (a);
    int bp = find_set (b);
    if(sgn[ap] != sgn[a]) sg=-sg;
    if(sgn[bp] != sgn[b]) sg=-sg;
    if (ap == bp) {
        if(sg == -1) return "NO";
        return "YES";
    }
    a=ap;
    b=bp;
    if (a != b) {
        if (lst[a].size() < lst[b].size())
            swap (a, b);
        while (!lst[b].empty()) {
            int v = lst[b].back();
            lst[b].pop_back();
            if (sg == -1) sgn[v] = -sgn[v];
            parent[v] = a;
            lst[a].push_back (v);
        }
        
    }
    return "YES";
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,q;
    scanf("%d %d %d\n", &n, &m, &q);
    map<string, int> wto;
    forn(i,0,n) {
        char w[30];
        scanf("%s", w);
        string s(w);
        wto[s] = i;
        make_set(i);
    }
    forn(i,0,m) {
        char w1[30], w2[30];
        int t;
        scanf("%d %s %s\n", &t, w1, w2);
        string s1(w1), s2(w2);
        if(t==2) t=-1;
        printf("%s\n", union_sets(wto[s1], wto[s2], t).c_str());
    }
    forn(i,0,q) {
        char w1[30], w2[30];
        scanf("%s %s",w1,w2);
        string s1(w1), s2(w2);
        int i1 = wto[s1];
        int i2 = wto[s2];
        if(find_set(i1) != find_set(i2)) printf("3\n");
        else if(sgn[i1] == sgn[i2]) printf("1\n");
        else printf("2\n");
    }
    
    
}