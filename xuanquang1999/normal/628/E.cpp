//84104971101048411497 - Can you guess what does this mean?
using namespace std;
#include <bits/stdc++.h>
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define fordit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define ll long long
#define maxN 3005

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

struct BIT {
    vector<int> t;
    int n;
    void init(int _n) {
        n = _n;
        t.resize(n+1);
    }
    void update(int p, int x) {
        for(int i = p; i <= n; i += i&(-i)) {
            t[i] += x;
        }
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i >= 1; i -= i&(-i)) {
            res += t[i];
        }
        return res;
    }
};

int m, n, zr[maxN][maxN], zl[maxN][maxN], zld[maxN][maxN];
char s[maxN][maxN];
vector<ii> event[maxN];
ll ans;
BIT t[2*maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &m, &n);
    fto(i, 0, m-1) scanf("%s", s[i]);

    fdto(i, m-1, 0) {
        fdto(j, n-1, 0) {
            if (s[i][j] == 'z') zr[i][j] = zr[i][j+1]+1;
        }
        fto(j, 0, n-1) {
            if (s[i][j] == 'z') {
                zl[i][j] = zld[i][j] = 1;
                if (j > 0) zl[i][j] += zl[i][j-1], zld[i][j] += zld[i+1][j-1];
            }
        }
    }
    fto(i, 0, m-1) {
        fto(j, 0, n-1) {
            if (zr[i][j] > 0) event[j+zr[i][j]-1].pb(mp(i, j));
        }
    }

    fto(i, 0, m+n-2) t[i].init(n);

    fdto(j, n-1, 0) {
        forit(it, event[j]) {
            int x = it->ff, y = it->ss;
            t[x+y].update(y+1, 1);
        }
        fto(i, 0, m-1) {
            int c = min(zl[i][j], zld[i][j]);
            if (c == 0) continue;
            ans += t[i+j].query(j+1)-t[i+j].query(j-c+1);
        }
    }

    cout << ans;

    return 0;
}