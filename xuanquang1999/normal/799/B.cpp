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
#define maxN 200005
#define oo 2000000007
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

int n, q, p[maxN], a[maxN], b[maxN];
vector<int> price[4][4];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &p[i]);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n) scanf("%d", &b[i]);

    fto(i, 1, n) price[a[i]][b[i]].pb(p[i]);

    fto(i, 1, 3) fto(j, 1, 3) sort(price[i][j].rbegin(), price[i][j].rend());
    scanf("%d", &q);
    fto(i, 1, q) {
        int c; scanf("%d", &c);

        int ansI, ansJ, minP = oo;
        fto(i, 1, 3) fto(j, 1, 3) {
            if ((i == c || j == c) && sz(price[i][j]) > 0 && *price[i][j].rbegin() < minP) {
                minP = *price[i][j].rbegin();
                ansI = i; ansJ = j;
            }
        }

        if (minP == oo) minP = -1;
        else price[ansI][ansJ].pop_back();
        printf("%d ", minP);
    }

    return 0;
}