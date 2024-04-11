//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i,  r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
#define forit(it, var) for(__typeof(var.begin()) it = var.begin(); it != var.end(); it++)
#define forrit(rit, var) for(__typeof(var.rbegin()) rit = var.rbegin(); rit != var.rend(); rit++)
#define ii pair<int, int>
#define iii pair<int, ii>
#define ff first
#define ss second
#define mp make_pair
#define pb push_back
#define X real()
#define Y imag()
#define maxN 1005
#define maxQ 100005
#define oo 2000000007
#define EPS 1e-9

const double PI = acos(-1.0);

double fRand(double fMin, double fMax)
{
    double f = (double)rand() / RAND_MAX;
    return fMin + f * (fMax - fMin);
}

template <class T>
T min(T a, T b, T c) {
    return min(a, min(b, c));
}

template <class T>
T max(T a, T b, T c) {
    return max(a, max(b, c));
}

int n, m, q, dr[maxN][maxN], dc[maxN][maxN], k[maxQ];
char s[maxN][maxN], c[maxQ];
vector<ii> pos;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 0, n-1) scanf("%s", s[i]);

    fto(i, 1, n) {
        fto(j, 1, m) {
            dr[i][j] = dr[i][j-1] + (s[i-1][j-1] != '#');
            dc[i][j] = dc[i-1][j] + (s[i-1][j-1] != '#');
            if (s[i-1][j-1] != '.' && s[i-1][j-1] != '#') pos.pb(mp(i, j));
        }
    }

    scanf("%d\n", &q);
    fto(i, 1, q) scanf("%c%d\n", &c[i], &k[i]);
    //fto(i, 1, q) printf("%c %d\n", c[i], k[i]);
    string ans;
    forit(it, pos) {
        int x = it->ff, y = it->ss;
        bool ok = true;
        //printf("x, y: %d %d\n", x, y);
        fto(i, 1, q) {
            if (!ok) break;

            if (c[i] == 'N') {
                if (x-k[i] < 1 || dc[x-1][y]-dc[x-k[i]-1][y] != k[i]) ok = false;
                x -= k[i];
            } else if (c[i] == 'S') {
                if (x+k[i] > n || dc[x+k[i]][y]-dc[x][y] != k[i]) ok = false;
                x += k[i];
            } else if (c[i] == 'W') {
                if (y-k[i] < 1 || dr[x][y-1]-dr[x][y-k[i]-1] != k[i]) ok = false;
                y -= k[i];
            } else if (c[i] == 'E') {
                if (y+k[i] > m || dr[x][y+k[i]]-dr[x][y] != k[i]) ok = false;
                y += k[i];
            }
            //printf("%d %d\n", x, y);
        }

        if (ok) ans += s[it->ff-1][it->ss-1];
    }

    sort(ans.begin(), ans.end());
    if (ans == "") ans = "no solution";
    cout << ans;

    return 0;
}