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
#define maxN 25
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

int dom[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n, a[maxN];

int daysofMonth(int year, int month) {
    int x = dom[month];
    if (month == 1 && (year%400 == 0 || (year%4 == 0 && year%100 != 0))) ++x;
    return x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 0, n-1) scanf("%d", &a[i]);

    fto(y, 0, 399) {
        fto(m, 0, 11) {
            bool ok = true;
            fto(i, 0, n-1) {
                if (a[i] != daysofMonth(y+(m+i)/12, (m+i)%12)) {
                    ok = false;
                    break;
                }
            }
            if (ok) {
                puts("YES");
                return 0;
            }
        }
    }

    puts("NO");

    return 0;
}