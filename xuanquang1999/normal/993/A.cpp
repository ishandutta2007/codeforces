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
#define MOD 1000
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


void read(int &x1, int &y1, int &x2, int &y2) {
    x1 = oo; y1 = oo;
    x2 = -oo; y2 = -oo;
    fto(i, 0, 3) {
        int x, y;
        scanf("%d%d", &x, &y);
        x1 = min(x1, x); y1 = min(y1, y);
        x2 = max(x2, x); y2 = max(y2, y);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int x1, y1, x2, y2, x3, y3, x4, y4;
    read(x1, y1, x2, y2);
    read(x3, y3, x4, y4);

    fto(x, x1, x2) {
        fto(y, y1, y2) {
            int d = abs(x-(x3+x4)/2)+abs(y-(y3+y4)/2);
            if (d <= (x4-x3)/2) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");

    return 0;
}