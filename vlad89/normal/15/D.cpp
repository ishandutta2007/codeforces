#include <iostream>
#include <cstdio>
#include <bitset>
#include <cstring>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <cstdlib>
#include <cmath>
#include <list>

using namespace std;

#define FOR(i,a,b) for(int i=(a),_b(b);i<_b;++i)
#define FORD(i,a,b) for(int i=(a),_b(b);i>=_b;--i)
#define REP(i,n) FOR(i,0,n)
#define ALL(a) (a).begin(),a.end()
#define SORT(a) sort(ALL(a))
#define UNIQUE(a) SORT(a),(a).resize(unique(ALL(a))-a.begin())
#define SZ(a) ((int) a.size())
#define pb push_back

#define VAR(a,b) __typeof(b) a=(b)
#define FORE(it,a) for(VAR(it,(a).begin());it!=(a).end();it++)
#define X first
#define Y second

#define INF 1000000000

typedef vector<int> vi;
typedef pair<int, int> pii;
typedef long long ll;

long long S[1024][1024];
pair <long long, pii> c[1024*1024];
int k;

#define PREV(x) (x & (x - 1))
#define NEXT(x) ((x << 1) - (PREV(x)))

int mas[1024][1024];
int n, m;

int sum_1based(int y1, int x1, int y2, int x2) {
    if (y2 < 0 || x2 < 0) 
        return 0;        
    if (y1 == 1 && x1 == 1) {
        static int r;
        r = 0;
        for(y1 = y2; y1; y1 = PREV(y1))
            for(x1 = x2; x1; x1 = PREV(x1))
                r += mas[y1][x1];                 
        return r;
    } else
    return sum_1based(1, 1, y2, x2) - sum_1based(1, 1, y1 - 1, x2) - sum_1based(1, 1, y2, x1 - 1) + sum_1based(1, 1, y1 - 1, x1 - 1);
}

int sum(int y1, int x1, int y2, int x2) {
    return sum_1based(y1 + 1, x1 + 1, y2 + 1, x2 + 1);
}    

void modify(int y, int x) {
    y++;    x++;
    static int yy, xx;
    for(yy = y; yy <= n; yy = NEXT(yy))
        for(xx = x; xx <= m; xx = NEXT(xx))
            mas[yy][xx] ++;                        
}

priority_queue <pair <int, pii>, vector <pair <int, pii> >, greater <pair <int, pii> > > ph[1024];

int main() {
#ifdef LOCAL
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int a, b;
    scanf ("%d%d%d%d", &n, &m, &a, &b);
    int yo = 0;
    REP (i, n) 
    {
        priority_queue <pair <int, pii>, vector <pair <int, pii> >, greater <pair <int, pii> > > p;
        REP (j, m) {
            scanf ("%I64d", &S[i+1][j+1]);
            ph[j].push (make_pair (S[i+1][j+1], pii (j, i)));
            S[i+1][j+1] = S[i+1][j+1] + S[i][j+1] + S[i+1][j] - S[i][j];
            if (i >= a-1) {
                while (ph[j].top().Y.Y <= i-a) ph[j].pop();
                
                p.push (ph[j].top());
                
                if (j >= b-1) {
                    while (p.top().Y.X <= j-b) p.pop();
                    
                    c[yo++].X -= (long long) p.top().X * a * b;
                }
            }
        }
    }
    REP (i, n-a+1) REP (j, m-b+1) {
        c[k].X += S[i+a][j+b] + S[i][j] - S[i+a][j] - S[i][j+b];
        
        c[k].Y.X = i;
        c[k].Y.Y = j;
        ++k;
    }
    sort (c, c + k);
    
    int lenans = 0;
    REP (i, k) {
        if (sum (c[i].Y.X, c[i].Y.Y, c[i].Y.X + a-1, c[i].Y.Y + b-1)) continue;
        REP (q, a) REP (w, b)
            modify (c[i].Y.X + q, c[i].Y.Y + w);
        c[lenans++] = c[i];
    } 
    printf ("%d\n", lenans);
    REP (i, lenans) 
        printf ("%d %d %I64d\n", c[i].Y.X+1, c[i].Y.Y+1, c[i].X);
    return 0;
}