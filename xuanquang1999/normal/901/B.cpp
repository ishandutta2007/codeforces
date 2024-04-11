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

int n;

void print(vector<int> a) {
    printf("%d\n", sz(a)-1);
    for(int x: a) printf("%d ", x);
    puts("");
}

void Try(int i, vector<int> a, vector<int> b) {
    fto(i, 0, sz(b)-1) {
        if (abs(b[i]) > 1) return;
    }
    if (i == n) {
        if (b.back()*a.back() == -1) return;
        if (b.back() == -1) {
            fto(i, 0, sz(a)-1) a[i] *= -1;
            fto(i, 0, sz(b)-1) b[i] *= -1;
        }
        print(b);
        print(a);
        exit(0);
    }
    for(int j = -1; j <= 1; j += 2) {
        vector<int> c(sz(b)+1, 0);
        fto(i, 0, sz(b)) {
            if (i < sz(a)) c[i] += a[i];
            if (i > 0) c[i] += b[i-1]*j;
        }
        Try(i+1, b, c);
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);

    Try(0, {0}, {1});

    return 0;
}