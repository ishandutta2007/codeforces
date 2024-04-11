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

int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    int n,m;
    scanf("%d %d\n", &n,&m);
    vector<string> board(n);
    vvi p(n, vi(m,0));
    forn(i,0,n) {
        getline(cin, board[i]);
        forn(j,0,m) {
            if(board[i][j]=='*') p[i][j] = 0;
            if(board[i][j]=='>') p[i][j] = 1;
            if(board[i][j]=='^') p[i][j] = 2;
            //if(board[i][j]=='*') p[i][j] = 3;
            if(board[i][j]=='<') p[i][j] = 4;
            if(board[i][j]=='-') p[i][j] = 5;
            //if(board[i][j]=='*') p[i][j] = 6;
            if(board[i][j]=='D') p[i][j] = 7;
            if(board[i][j]=='v') p[i][j] = 8;
            //if(board[i][j]=='*') p[i][j] = 9;
            if(board[i][j]=='|') p[i][j] = 10;
            if(board[i][j]=='L') p[i][j] = 11;
            //if(board[i][j]=='*') p[i][j] = 12;
            if(board[i][j]=='U') p[i][j] = 13;
            if(board[i][j]=='R') p[i][j] = 14;
            if(board[i][j]=='+') p[i][j] = 15;
        }
    }
    const int INF = 1000000000;
    int xt,yt,xm,ym;
    scanf("%d %d",&xt,&yt);
    scanf("%d %d",&xm,&ym);
//    vector < vector < int> > g (n*m*4);
    xt--; yt--;
    xm--;
    ym--;
    int s = xt*m + yt; //  
    int e = xm*m+ym;
//    forn(i,0,n*m) {
//        g[i].pb(i+n*m);
//        g[i+n*m].pb(i+2*n*m);
//        g[i+2*n*m].pb(i+3*n*m);
//        g[i+3*n*m].pb(i);
//    }
    int mn = m*n;
//    forn(i,0,n) {
//        forn(j,0,m-1) {
//            int posl = i*m+j;
//            int posr = posl+1;
//            int l = p[i][j];
//            int r = p[i][j+1];
//            if((l&1) && (r&4)) {
//                g[posl].pb(posr);
//                g[posr].pb(posl);
//            }
//            if((l&2) && (r&8)) {
//                g[posl+mn].pb(posr+mn);
//                g[posr+mn].pb(posl+mn);
//            }
//            if((l&4) && (r&1)) {
//                g[posl+2*mn].pb(posr+2*mn);
//                g[posr+2*mn].pb(posl+2*mn);
//            }
//            if((l&8) && (r&2)) {
//                g[posl+3*mn].pb(posr+3*mn);
//                g[posr+3*mn].pb(posl+3*mn);
//            }
//        }
//    }
//    
//    forn(i,0,n-1) {
//        forn(j,0,m) {
//            int posu = i*m+j;
//            int posd = posu+m;
//            int l = p[i][j];
//            int r = p[i+1][j];
//            if((l&8) && (r&2)) {
//                g[posu].pb(posd);
//                g[posd].pb(posu);
//            }
//            if((l&1) && (r&4)) {
//                g[posu+mn].pb(posd+mn);
//                g[posd+mn].pb(posu+mn);
//            }
//            if((l&2) && (r&8)) {
//                g[posu+2*mn].pb(posd+2*mn);
//                g[posd+2*mn].pb(posu+2*mn);
//            }
//            if((l&4) && (r&1)) {
//                g[posu+3*mn].pb(posd+3*mn);
//                g[posd+3*mn].pb(posu+3*mn);
//            }
//        }
//    }
    
    vi d (4*m*n, INF),  pp (4*m*n);
    d[s] = 0;
    priority_queue < pair<int,int> > q;
    q.push (make_pair (0, s));
    while (!q.empty()) {
        int v = q.top().second,  cur_d = -q.top().first;
        q.pop();
        if (cur_d > d[v])  continue;
        vi nv;
        int rot = v/(m*n);
        int i = (v%(m*n)) / m;
        int j = v % m;
        int w = p[i][j];
        if(rot<3) nv.pb(v+(m*n));
        else nv.pb(v%(m*n));
        if(j>0) {
            int l = p[i][j-1];
            if (rot == 0) if ((l&1) && (w&4)) nv.pb(v - 1);
            if (rot == 1) if ((l&2) && (w&8)) nv.pb(v - 1);
            if (rot == 2) if ((l&4) && (w&1)) nv.pb(v - 1);
            if (rot == 3) if ((l&8) && (w&2)) nv.pb(v - 1);
        }
        if(j<m-1) {
            int r = p[i][j+1];
            if (rot == 0) if ((w&1) && (r&4)) nv.pb(v + 1);
            if (rot == 1) if ((w&2) && (r&8)) nv.pb(v + 1);
            if (rot == 2) if ((w&4) && (r&1)) nv.pb(v + 1);
            if (rot == 3) if ((w&8) && (r&2)) nv.pb(v + 1);
        }
        if(i>0) {
            int u = p[i-1][j];
            if (rot == 0) if ((u&8) && (w&2)) nv.pb(v - m);
            if (rot == 1) if ((u&1) && (w&4)) nv.pb(v - m);
            if (rot == 2) if ((u&2) && (w&8)) nv.pb(v - m);
            if (rot == 3) if ((u&4) && (w&1)) nv.pb(v - m);
        }
        if(i<n-1) {
            int d = p[i+1][j];
            if (rot == 0) if ((w&8) && (d&2)) nv.pb(v + m);
            if (rot == 1) if ((w&1) && (d&4)) nv.pb(v + m);
            if (rot == 2) if ((w&2) && (d&8)) nv.pb(v + m);
            if (rot == 3) if ((w&4) && (d&1)) nv.pb(v + m);
        }
        
        for (size_t j=0; j<nv.size(); ++j) {
            int to = nv[j],
            len = 1;
            if (d[v] + len < d[to]) {
                d[to] = d[v] + len;
                pp[to] = v;
                q.push (make_pair (-d[to], to));
            }
        }
    }
    int ans = INF;
    ans = min(ans, d[e]);
    ans = min(ans, d[e+mn]);
    ans = min(ans, d[e+2*mn]);
    ans = min(ans, d[e+3*mn]);
    if(ans==INF) cout<<-1;
    else cout<<ans;
    
}