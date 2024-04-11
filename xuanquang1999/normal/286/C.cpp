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
#define maxN 1000005
#define oo 2000000007

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

int n, t, p[maxN], y[maxN];
bool open[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &p[n-i+1]);
    scanf("%d", &t);
    fto(i, 1, t) {
        int x; scanf("%d", &x);
        open[n-x+1] = true;
    }

    stack<int> s;
    fto(i, 1, n) {
        if (s.empty() || s.top() != p[i]) {
            s.push(p[i]);
            y[i] = p[i];
        } else {
            if (open[i]) {
                s.push(p[i]);
                y[i] = p[i];
            } else {
                s.pop();
                y[i] = -p[i];
            }
        }
    }

    if (s.empty()) {
        puts("YES");
        fdto(i, n, 1) printf("%d ", -y[i]);
    } else puts("NO");

    return 0;
}