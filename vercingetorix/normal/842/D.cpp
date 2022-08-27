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
vi a;

struct vertex {
    int nx[2];
    bool fr = false;
};

vector<vertex> st(1);
int pt = 1;
void go(int ind, int l, int r, int ptl, int ptr, int bit) {
    if(r-l == 1) {
        return;
    }
    int m = (l+r)/2;
    int ptm = lower_bound(a.begin()+ptl, a.begin()+ptr, m) - a.begin();
    if (ptm > ptl) {
        st[ind].nx[0] = pt++;
        st.emplace_back();
        go(st[ind].nx[0], l, m, ptl, ptm, bit-1);
        st[ind].fr |= st[st[ind].nx[0]].fr;
    }
    else {
        st[ind].fr = true;
        st[ind].nx[0] = -1;
    }
    if (ptr > ptm) {
        st[ind].nx[1] = pt++;
        st.emplace_back();
        go(st[ind].nx[1], m, r, ptm, ptr, bit-1);
        st[ind].fr |= st[st[ind].nx[1]].fr;
    }
    else {
        st[ind].fr = true;
        st[ind].nx[1] = -1;
    }
}


int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d", &n, &m);
    a.resize(n);
    forn(i,0,n) scanf("%d", &a[i]);
    sort(all(a));
    vi na;
    forn(i,0,n) if(i==0 || a[i]!=a[i-1]) na.pb(a[i]);
    a = na;
    na.clear();
    n = a.size();
    int x = 0;
    go(0, 0, 1<<20, 0, n, 20);
    forn(i,0,m) {
        int y;
        scanf("%d", &y);
        x ^= y;
        int ans = 0;
        int ind = 0;
        for(int bit = 19; bit >= 0; bit--) {
            int s = x&(1<<bit);
            if (s>0) s = 1;
            if (st[ind].nx[s] == -1) break;
            else if(st[st[ind].nx[s]].fr) ind = st[ind].nx[s];
            else {
                ans += 1<<bit;
                ind = st[ind].nx[1-s];
                if(ind == -1) break;
            }
        }
        printf("%d\n", ans);
    }

    
}