//84104971101048411497 - Can you guess what does this mean?
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef complex<double> point;
#define mapii map<int, int>
#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
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
#define maxN 100005
#define oo 1000000007
#define sz(a) (int)a.size()

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

int n, c, d;
vector<int> fC[2], fD[2];
vector<ii> pC, pD;

void Calc(vector<ii> p, int c, vector<int> f[]) {
    fto(i, 0, 1) f[i].assign(c+1, -oo);
    forit(it, p) {
        if (it->ff > c) continue;
        if (it->ss > f[0][it->ff]) {
            f[1][it->ff] = f[0][it->ff];
            f[0][it->ff] = it->ss;
        } else if (it->ss > f[1][it->ff]) f[1][it->ff] = it->ss;
    }
    fto(i, 1, c) {
        if (f[0][i-1] > f[0][i]) {
            f[1][i] = f[0][i];
            f[0][i] = f[0][i-1];
        } else if (f[0][i-1] > f[1][i]) f[1][i] = f[0][i-1];
    }
}

int get(vector<int> f[], int x1, int x2) {
    if (f[0][x1] == f[0][x2]) return max(f[0][x1]+f[1][x2], f[0][x2]+f[1][x1]);
    else return f[0][x1]+f[0][x2];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &c, &d);
    fto(i, 1, n) {
        int p, v; char s[2];
        scanf("%d%d%s", &v, &p, s);
        if (s[0] == 'C') pC.pb(mp(p, v));
        else pD.pb(mp(p, v));
    }

    Calc(pC, c, fC);
    Calc(pD, d, fD);

//    fto(i, 1, c) printf("%d %d\n", fC[0][i], fC[1][i]);
//    fto(i, 1, d) printf("%d %d\n", fD[0][i], fD[1][i]);

    int ans = fC[0][c]+fD[0][d];
    fto(x, 0, c) ans = max(ans, get(fC, x, c-x));
    fto(x, 0, d) ans = max(ans, get(fD, x, d-x));

    ans = max(ans, 0);
    printf("%d", ans);

    return 0;
}