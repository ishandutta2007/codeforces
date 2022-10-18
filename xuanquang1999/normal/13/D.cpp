#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long long T;
typedef complex<T> pt;
#define X real()
#define Y imag()

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
#define maxN 505
#define MOD 1000
#define oo 1000000000000000007LL
#define sz(a) (int)a.size()
#define EPS 1e-12

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

int sign(ll x) {return (x > 0) - (x < 0);}

ll cross(pt &v, pt &w) {return v.X*w.Y - v.Y*w.X;}

void read(pt &p) {
    int x, y;
    scanf("%d%d", &x, &y);
    p = {x, y};
}

int n, m, cnt[maxN][maxN], cntExc[maxN][maxN], dir[maxN][maxN];
pt r[maxN], b[maxN], dR[maxN][maxN], dB[maxN][maxN];

int count(int &i, int &j, int &k) {
    return (dir[i][j] == dir[j][k]) ? cntExc[i][j] : cnt[i][j];
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &m);
    fto(i, 1, n) read(r[i]);
    fto(i, 1, m) read(b[i]);
    fto(i, 1, n) fto(j, 1, n) dR[i][j] = r[j]-r[i];
    fto(i, 1, n) fto(j, 1, m) dB[i][j] = b[j]-r[i];

    fto(i, 1, n) {
        fto(j, i+1, n) {
            dir[i][j] = sign(r[j].X - r[i].X);
            dir[j][i] = -dir[i][j];
            int l1 = min(r[i].X, r[j].X), r1 = max(r[i].X, r[j].X);
            int l2 = l1, r2 = r1;
            int l3 = l1, r3 = r1;
            if (dir[i][j] > 0) {
                --r2;
                ++l3;
            } else {
                ++l2;
                --r3;
            }

            fto(k, 1, m) {
                ll x = sign(cross(dR[i][j], dB[i][k]));
                if (b[k].X >= l1 && b[k].X <= r1) {
                    cnt[i][j] += x;
                    cnt[j][i] -= x;
                }
                if (b[k].X >= l2 && b[k].X <= r2) cntExc[i][j] += x;
                if (b[k].X >= l3 && b[k].X <= r3) cntExc[j][i] -= x;
            }
        }
    }

    int ans = 0;
    fto(i, 1, n) {
        fto(j, i+1, n) {
            fto(k, j+1, n) {
                int x = 0;
                x += count(i, j, k);
                x += count(j, k, i);
                x += count(k, i, j);
                if (abs(x) == 0) ++ans;
            }
        }
    }

    printf("%d", ans);


    return 0;
}