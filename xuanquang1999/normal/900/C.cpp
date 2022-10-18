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
#define maxN 100005
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

int n, p[maxN], b[maxN], cnt[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &p[i]);

    int f1 = 0, f2 = 0;
    fto(i, 1, n) {
        if (p[f2] > p[i]) b[i] = -1;
        else if (p[f1] > p[i]) b[i] = f1;
        else b[i] = 0;

        if (p[i] > p[f1]) {
            f2 = f1; f1 = i;
        } else if (p[i] > p[f2]) {
            f2 = i;
        }

        if (b[i] > 0) ++cnt[b[i]];
    }

    int ansR = -2, ansP = 0;
    fto(i, 1, n) {
        int x = cnt[i]-(b[i] == 0);
        if (x > ansR || (x == ansR && p[i] < ansP)) {
            ansR = x;
            ansP = p[i];
        }
    }

    printf("%d", ansP);



    return 0;
}