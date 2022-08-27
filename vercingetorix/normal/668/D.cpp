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
typedef std::vector<std::vector<bool> > vvb;
typedef std::vector<std::pair<int, int> > vpi;
typedef std::pair<int, int> pi;
typedef std::pair<ll, ll> pll;
typedef std::vector<pll> vpll;

const long long mod = 1000000007;

#define all(c) (c).begin(),(c).end()
#define sz(c) (int)(c).size()
#define forn(i, a, b) for(int i = a; i < b; i++)

#define pb push_back
#define mp make_pair

class stree {
public:
    vi t;
    int s;
    void build (vi & a, int v, int tl, int tr) {
        t.resize(a.size() * 4);
        s = a.size();
        if (tl == tr)
            t[v] = a[tl];
        else {
            int tm = (tl + tr) / 2;
            build (a, v*2, tl, tm);
            build (a, v*2+1, tm+1, tr);
        }
    }
    
    void update (int v, int tl, int tr, int l, int r, int add) {
        if (l > r)
            return;
        if (l == tl && tr == r)
            t[v] += add;
        else {
            int tm = (tl + tr) / 2;
            update (v*2, tl, tm, l, min(r,tm), add);
            update (v*2+1, tm+1, tr, max(l,tm+1), r, add);
        }
    }
    
    int get (int v, int tl, int tr, int pos) {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get (v*2, tl, tm, pos);
        else
            return t[v] + get (v*2+1, tm+1, tr, pos);
    }
};

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d", &n);
    vi t(n);
    vpi q(n);
    map<int, set<int>> moments;
    set<int> nums;
    forn(i,0,n) {
        scanf("%d %d %d", &t[i], &q[i].first, &q[i].second);
        moments[q[i].second].insert(q[i].first);
        nums.insert(q[i].second);
    }
    map<int, int> ind;
    int cnt=0;
    vi num;
    for(auto x: nums) {
        ind[x] = cnt;
        num.pb(x);
        cnt++;
    }
    vector<map<int,int>> tind(cnt);
    vector<stree> st(cnt);
    forn(i,0,cnt) {
        int tcnt = 0;
        for(auto y:moments[num[i]]) {
            tind[i][y] = tcnt;
            tcnt++;
        }
        vi stbase(tcnt, 0);
        st[i].build(stbase, 1, 0, tcnt-1);
    }
    forn(i,0,n) {
        int k = ind[q[i].second];
        int pos = tind[k][q[i].first];
        if(t[i] == 1) st[k].update(1, 0, st[k].s-1, pos, st[k].s-1, 1);
        if(t[i] == 2) st[k].update(1, 0, st[k].s-1, pos, st[k].s-1, -1);
        if(t[i] == 3) printf("%d\n", st[k].get(1, 0, st[k].s-1, pos));
    }
}