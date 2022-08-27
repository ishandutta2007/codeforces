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

#define all(c) (c).begin(),(c).end()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair
class stree {
public:
    vi t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        if(v==1) {
            t.resize(a.size() * 4);
            s = a.size();
        }
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
            t[v] = -2;
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int to) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] = to;
        else {
            int tm = (tl + tr) / 2;
            if(t[v] != -2) {
                t[v*2] = t[v];
                t[v*2+1] = t[v];
                t[v] = -2;
            }
            update (v*2, tl, tm, l, min(r,tm), to);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, to);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (t[v] != -2)
            return t[v];
        else if (pos <= tm)
            return get (v*2, tl, tm, pos);
        else
            return get (v*2+1, tm+1, tr, pos);
    }
    
    void print() {
        forn(i,0,s) printf("%d ", get(1,0,s-1,i));
        printf("\n");
    }
};
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int num;
    scanf("%d\n", &num);
    vs s(num);
    vvi x(num);
    char c[1000100];
    int n = 0;
    forn(i,0,num) {
        int k;
        scanf("%s %d", c, &k);
        s[i] = c;
        x[i].resize(k);
        forn(j,0,k) scanf("%d", &x[i][j]);
        forn(j,0,k) x[i][j]--;
        n = max(n, (int)x[i].back() + (int)s[i].size());
    }
    stree res;
    vi a(n,-1);
    res.build(a, 1, 0, n-1);
//    res.print();
    forn(i,0,num) {
        int l = s[i].size();
        for(auto st : x[i]) {
            res.update(1, 0, n-1, st, st+l-1, i);
//            printf("Update from %d to %d with %d\n", st, st+l-1, i);
//            res.print();
        }
    }
    string ans;
    forn(i,0,n) {
        int w = res.get(1, 0, n-1, i);
//        cout<<w<<' ';
        if (w == -1) ans.pb('a');
        else {
            auto it = upper_bound(all(x[w]), i);
            it--;
            int st = *it;
            ans.pb(s[w][i-st]);
        }
    }
//    cout<<endl;
    printf("%s", ans.c_str());
}