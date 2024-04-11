#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <queue>
#include <bitset>
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

vector<vector<bitset<1000>>> sq(1001, vector<bitset<1000>>(1000));

struct query{
    int x1,x2,y1,y2;
};

vector<query> q;
vi ans;
int n,m;

void go(int l, int r, vi lst) {
    if(lst.empty()) return;
    if(r-l == 1) {
        for(auto x : lst) ans[x] = l;
        return;
    }
    int med = (r+l)/2;
    vvi ch(n+1, vi(m+1, 0));
    forn(i,0,n) {
        int sum = 0;
        forn(j,0,m) {
            sum += sq[med][i][j];
            ch[i+1][j+1] = sum + ch[i][j+1];
        }
    }
    vi lst1, lst2;
    for(auto x : lst) {
        int x1 = q[x].x1;
        int y1 = q[x].y1;
        int x2 = q[x].x2 - med + 1;
        int y2 = q[x].y2 - med + 1;
        if(x2 < x1 || y2 < y1) lst1.pb(x);
        else {
            int cnt = ch[x2+1][y2+1] + ch[x1][y1] - ch[x1][y2+1] - ch[x2+1][y1];
            if(cnt >0) lst2.pb(x);
            else lst1.pb(x);
        }
    }
    go(l, med, lst1);
    go(med, r, lst2);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d\n", &n, &m);
    vvi a(n, vi(m));
    forn(i,0,n) forn(j,0,m) scanf("%d", &a[i][j]);
    forn(i,0,n) forn(j,0,m) sq[1][i][j] = a[i][j];
    forn(l,2,1001) {
        forn(i,0,999) {
            sq[l][i] = sq[l-1][i] & sq[l-1][i+1];
            sq[l][i] = sq[l][i] & (sq[l][i] >> 1);
        }
    }
    
//    forn(i,0,n) forn(j,0,m) {
//        if(j==0) cout<<endl;
//        cout<<sq[2][i][j] << ' ';
//    }
    int qnum;
    scanf("%d", &qnum);
    q.resize(qnum);
    ans.resize(qnum);
    vi lst;
    forn(i,0,qnum) {
        scanf("%d %d %d %d", &q[i].x1, &q[i].y1, &q[i].x2, &q[i].y2);
        q[i].x1--;
        q[i].y1--;
        q[i].x2--;
        q[i].y2--;
        lst.pb(i);
    }
    go(0, 1001, lst);
    
    for(auto x : ans) printf("%d\n", x);
    
}