#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <ctype.h>
#include <deque>
#include <cstring>
#include <set>
#include <bitset>
#include <map>
#include <chrono>
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
const unsigned gen_seed = std::chrono::system_clock::now().time_since_epoch().count();
std::mt19937_64 gen(gen_seed);

#define all(c) (c).begin(),(c).end()
#define srt(c) sort(all(c))
#define srtrev(c) sort(all(c)); reverse(all(c))
#define forn(i, a, b) for(int i = a; i < b; i++)
#define read(x) scanf("%d", &x)
#define readv(x, n) vi x(n); forn(i,0,n) scanf("%d", &x[i])

#define pb push_back
#define mp make_pair
vector<pair<pi, pi>> op;

vvi a;
void mv(int x1, int y1, int x2, int y2) {
    a[x2][y2] = a[x1][y1];
    a[x1][y1] = 0;
    op.pb(mp(mp(x1,y1), mp(x2,y2)));
}

int n,m;
int occ = 0;

void comp(int v) {
    occ = 0;
    forn(r,0,n) {
        if(a[v][r] != 0) {
            int pos = r;
            while(pos > occ) {
                mv(v,pos,v,pos-1);
                pos--;
            }
            occ++;
        }
    }
}


int main()
{
#ifdef LOCAL
    freopen("input.txt", "rt", stdin);
    freopen("output.txt", "wt", stdout);
#endif
    
    scanf("%d %d", &n, &m);
    vi xs(m+1), ys(m+1);
    vi xt(m+1), yt(m+1);
    forn(i,1,m+1) scanf("%d %d", &xs[i], &ys[i]);
    forn(i,1,m+1) scanf("%d %d", &xt[i], &yt[i]);
    
    vi colcnt(n,0);
    a = vvi(n, vi(n, 0));
    vvi to(n, vi(n,0));
    forn(i,1,m+1) {
        xs[i]--;
        ys[i]--;
        xt[i]--;
        yt[i]--;
        colcnt[xt[i]]++;
        a[xs[i]][ys[i]] = i;
        to[xt[i]][yt[i]] = i;
    }
    int v = 0;
    while(colcnt[v] > 1) v++;
    comp(v);
    
    forn(c,v+1,n) {
        for(int r = n-1; r >= 0; r--) {
            if(a[c][r] != 0) {
                int x = c;
                int y = r;
                if(r >= occ) {
                    while(x != v) {
                        mv(x,y,x-1,y);
                        x--;
                    }
                    while(y!=occ) {
                        mv(x,y,x,y-1);
                        y--;
                    }
                }
                else {
                    while(y!=occ) {
                        mv(x,y,x,y+1);
                        y++;
                    }
                    while(x != v) {
                        mv(x,y,x-1,y);
                        x--;
                    }
                }
                occ++;
            }
        }
    }
    for(int c = v-1; c>=0; c--) {
        for(int r = n-1; r >= 0; r--) {
            if(a[c][r] != 0) {
                int x = c;
                int y = r;
                if(r >= occ) {
                    while(x != v) {
                        mv(x,y,x+1,y);
                        x++;
                    }
                    while(y!=occ) {
                        mv(x,y,x,y-1);
                        y--;
                    }
                }
                else {
                    while(y!=occ) {
                        mv(x,y,x,y+1);
                        y++;
                    }
                    while(x != v) {
                        mv(x,y,x+1,y);
                        x++;
                    }
                }
                occ++;
            }
        }
    }

    for(int c = n-1; c > v+1; c--) {
        forn(r,0,n) {
            if(to[c][r] != 0) {
                int x = v;
                int y = 0;
                while(a[x][y] != to[c][r]) y++;
                mv(x,y,x+1,y);
                x++;
                while(y<r) {
                    mv(x,y,x,y+1);
                    y++;
                }
                while(y>r) {
                    mv(x,y,x,y-1);
                    y--;
                }
                while(x<c) {
                    mv(x,y,x+1,y);
                    x++;
                }
            }
        }
    }
    for(int c = 0; c < v-1; c++) {
        forn(r,0,n) {
            if(to[c][r] != 0) {
                int x = v;
                int y = 0;
                while(a[x][y] != to[c][r]) y++;
                mv(x,y,x-1,y);
                x--;
                while(y<r) {
                    mv(x,y,x,y+1);
                    y++;
                }
                while(y>r) {
                    mv(x,y,x,y-1);
                    y--;
                }
                while(x>c) {
                    mv(x,y,x-1,y);
                    x--;
                }
            }
        }
    }
    if(v!=0 && v!=n-1) {
        forn(i,0,n) if(a[v][i] != 0 && xt[a[v][i]] != v+1) mv(v,i,v-1,i);
    }
    if(v!=n-1) {
        forn(r,0,n) {
            if(a[v][r] != 0 && xt[a[v][r]] == v) {
                mv(v,r,v+1,r);
                comp(v);
                int x = v+1;
                int y = r;
                while(a[v][y] != 0) {
                    mv(x,y,x,y+1);
                    y++;
                }
                mv(x,y,x-1,y);
                x--;
            }
        }
        for(int r = n-1; r>=0; r--) {
            if(to[v+1][r] != 0) {
                comp(v);
                int x = v;
                int y = 0;
                while(a[x][y] != to[v+1][r]) y++;
                mv(x,y,x+1,y);
                x++;
                while(y!=r) {
                    mv(x,y,x,y+1);
                    y++;
                }
            }
        }
    }
    if(v!=0 && v!=n-1) {
        forn(i,0,n) if(a[v-1][i] != 0) mv(v-1,i,v,i);
    }
    if(v!=0) {
        forn(r,0,n) {
            if(a[v][r] != 0 && xt[a[v][r]] == v) {
                mv(v,r,v-1,r);
                comp(v);
                int x = v-1;
                int y = r;
                while(a[v][y] != 0) {
                    mv(x,y,x,y+1);
                    y++;
                }
                mv(x,y,x+1,y);
                x++;
            }
        }
        for(int r = n-1; r>=0; r--) {
            if(to[v-1][r] != 0) {
                comp(v);
                int x = v;
                int y = 0;
                while(a[x][y] != to[v-1][r]) y++;
                mv(x,y,x-1,y);
                x--;
                while(y!=r) {
                    mv(x,y,x,y+1);
                    y++;
                }
            }
        }
    }
    forn(r,0,n) if(to[v][r] != 0) {
        int x = v;
        int y = 0;
        while(a[x][y] != to[v][r]) y++;
        while(y<r) {
            mv(x,y,x,y+1);
            y++;
        }
        while(y>r) {
            mv(x,y,x,y-1);
            y--;
        }
    }
//        for(int j = n-1; j>=0; j--) {
//            forn(i,0,n) printf("%d", a[i][j]);
//            printf("\n");
//        }
    printf("%d\n", op.size());
    for(auto x : op) printf("%d %d %d %d\n", x.first.first+1, x.first.second+1, x.second.first+1,x.second.second+1);
    
}