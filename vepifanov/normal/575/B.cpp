#include <bits/stdc++.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define rep(i,n) for(int i = 0; i < (n); i++)
#define re return
#define fi first
#define se second
#define sz(x) ((int) (x).size())
#define all(x) (x).begin(), (x).end()
#define sqr(x) ((x) * (x))
#define sqrt(x) sqrt(abs(x))
#define y0 y3487465
#define y1 y8687969
#define fill(x,y) memset(x,y,sizeof(x))
#define prev PREV
#define next NEXT
#define j0 j1347829
#define j1 j234892
                         
typedef vector<int> vi;
typedef long long ll;
typedef long double ld;
typedef double D;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<vi> vvi;

template<class T> T abs(T x) { re x > 0 ? x : -x; }
template<class T> T gcd(T a, T b) { re a ? gcd (b % a, a) : b; }

const D pi = asin(1.0) * 2;

const int N = 100000;
const int mod = 1000*1000*1000+7;

int n;
int m;
vii v[N];
int up[N];
int down[N];
int tin[N];
int tout[N];
int ct;
int anc[N][20];

int go (int x, int p) {
    tin[x] = ct++;
    anc[x][0] = p;
    for (int i = 1; i < 20; i++)
        anc[x][i] = anc[anc[x][i - 1]][i - 1];
    for (int i = 0; i < sz (v[x]); i++) 
        if (v[x][i].fi != p)
            go (v[x][i].fi, x);
    tout[x] = ct++;
    re 0;
}

int isanc (int a, int b) { re int (tin[a] <= tin[b] && tout[a] >= tout[b]); }

int lca (int a, int b) {
    int j = 19;
    while (!isanc (a, b))
        if (j == 0 || !isanc (anc[a][j], b))
            a = anc[a][j];
        else
            j--;    
    re a;
}

int ans = 0;
int sp2[1000001];

ii calc (int x, int p) {
    int cup = 0, cdown = 0;
    for (int i = 0; i < sz (v[x]); i++) {
        int y = v[x][i].fi;
        int z = v[x][i].se;
        if (y == p) continue;
        ii tmp = calc (y, x);
        cup += tmp.fi;
        cdown += tmp.se;
//      printf ("%d -> %d = %d %d\n", x + 1, y + 1, tmp.fi, tmp.se);
        if (z == 1) ans = (ans + sp2[tmp.fi]) % mod;
        if (z == 2) ans = (ans + sp2[tmp.se]) % mod;
    }
    cup += up[x];
    cdown += down[x];
    re mp (cup, cdown);
}

int main () {
    scanf ("%d", &n);
    for (int i = 1; i < n; i++) {
        int a, b, c;
        scanf ("%d%d%d", &a, &b, &c); a--; b--;
        v[a].pb (mp (b, c));
        v[b].pb (mp (a, c ^ 3));
    }
    go (0, 0);
    scanf ("%d", &m);
    int last = 0;
    for (int i = 0; i < m; i++) {
        int cur;
        scanf ("%d", &cur); cur--;
        int mid = lca (last, cur);
        up[last]++;
        up[mid]--;
        down[cur]++;
        down[mid]--;
        last = cur;
    }
    int cur = 1;
    sp2[0] = 0;
    for (int i = 1; i <= m; i++) {
        sp2[i] = (sp2[i - 1] + cur) % mod;
        cur = (cur * 2) % mod;
    }
    calc (0, 0);
    cout << ans << endl;
    re 0;
}