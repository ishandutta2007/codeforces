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

struct pt {
    ll x, y;
    void read() {cin >> x >> y;}
    friend ostream& operator << (ostream& os, const pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
    }
    pt operator - (pt p) {return {x - p.x, y - p.y};}
};

struct circle {
    pt p; ll r;
    void read() {
        cin >> r;
        p.read();
    }
};

ll sq(pt p) {return p.x*p.x + p.y*p.y;}

ll sq(ll x) {return x*x;}

const int MAXN = 1e3 + 5;
int n, m, k;
pt control[MAXN];
circle fence[MAXN];
bool in[MAXN][MAXN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d%d", &n, &m, &k);
    fto(i, 1, n) control[i].read();
    fto(i, 1, m) fence[i].read();

    fto(i, 1, n)
        fto(j, 1, m)
            in[i][j] = (sq(control[i] - fence[j].p) <= sq(fence[j].r));

    fto(i, 1, k) {
        int a, b;
        scanf("%d%d", &a, &b);

        int ans = 0;
        fto(j, 1, m)
            ans += in[a][j]^in[b][j];

        printf("%d\n", ans);
    }

    return 0;
}