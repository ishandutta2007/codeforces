#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <set>
#include <list>
#include <map>
#include <unordered_map>
#include <unordered_set>

#include <stdio.h>

using namespace std;

typedef long long ll;
typedef std::vector<int> vi;
typedef std::vector<bool> vb;
typedef std::vector<string> vs;
typedef std::vector<double> vd;
typedef std::vector<long long> vll;
typedef std::vector<std::vector<int> > vvi;
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

long long mod=1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

vi parent;
vi rankk;

void make_set (int v) {
    parent[v] = v;
    rankk[v] = 0;
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
        if (rankk[a] < rankk[b])
            swap (a, b);
        parent[b] = a;
        if (rankk[a] == rankk[b])
            ++rankk[a];
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m,k;
    string s;
    //ll ans = 0;
//    cin >> n >> m;
    scanf("%d %d" , &n,&m);
    vector<int> v;
    vector<int> vv;
    //unordered_map<int, vpi> p;
    vvi ans(n, vi(m, 0));
    vi maxrow(n,0);
    vi maxcol(m,0);
    int cur=0;
    vvi ad(n, vi(m,0));
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            int x;
            scanf("%d", &x);
            ad[i][j] = x;
            vv.pb(x);
           
        }
    }
    sort(all(vv));
    for(int i =0; i<vv.size(); i++) {
        if ((i==0) || (vv[i] != vv[i-1])) v.pb(vv[i]);
    }
    map<int, int> sj;
    int currrr =0;
    for (auto a : v) {
        sj[a] = currrr;
        currrr++;
    }
    vector<vpi> p(currrr);
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            p[sj[ad[i][j]]].pb(mp(i,j));
            
        }
    }
    for(auto a : v) {
        parent = vi(p[sj[a]].size() +1 , 0);
        rankk = vi(p[sj[a]].size() +1 , 0);
        map<int, int> wasrow;
        map<int, int> wascol;
        for(int i =0; i<p[sj[a]].size(); i++) {
            make_set(i+1);
            int x = p[sj[a]][i].first;
            int y = p[sj[a]][i].second;
            if (wasrow[x] > 0) union_sets(wasrow[x], i+1);
            if (wascol[y] > 0) union_sets(wascol[y], i+1);
            wasrow[x] = i+1;
            wascol[y] = i+1;
        }
        //unordered_set<int> allcomp;
        vi allcomp2;
        vi allcomp;
        unordered_map<int, vi> sost;
        for (int i =0; i<p[sj[a]].size(); i++) {
            int ind = find_set(i+1);
            allcomp2.pb(ind);
            sost[ind].pb(i);
        }
        sort(all(allcomp2));
        for(int i =0; i<allcomp2.size(); i++) {
            if ((i==0) || (allcomp2[i] != allcomp2[i-1])) allcomp.pb(allcomp2[i]);
        }
        for(auto comp:allcomp)
        {
            int maxv = 0;
            for(auto r : sost[comp]) {
                maxv = max(maxv, maxrow[p[sj[a]][r].first]);
                maxv = max(maxv, maxcol[p[sj[a]][r].second]);
            }
            maxv++;
            cur = max(maxv, cur);
            for(auto r : sost[comp]) {
                maxrow[p[sj[a]][r].first] = maxv;
                maxcol[p[sj[a]][r].second] = maxv;
            }
            for(auto r : sost[comp]) {
                ans[p[sj[a]][r].first][p[sj[a]][r].second] = maxv;
            }
        }
    }
    
    
//    cout<<cur;
    forn(i,0,n){
        forn(j,0,m) {
            printf("%d ", ans[i][j]);
        }
        printf("\n");
    }
}