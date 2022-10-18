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

int n, a[maxN], b[maxN], ans[maxN];

bool Check() {
    set<int> s;
    fto(i, 1, n) s.insert(ans[i]);
    if (s.size() < n) return false;

    int cnt = 0;
    fto(i, 1, n) {
        if (a[i] != ans[i]) ++cnt;
    }
    if (cnt != 1) return false;

    cnt = 0;
    fto(i, 1, n) {
        if (b[i] != ans[i]) ++cnt;
    }
    if (cnt != 1) return false;

    return true;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &a[i]);
    fto(i, 1, n) scanf("%d", &b[i]);

    vector<int> p;
    fto(i, 1, n) {
        if (a[i] == b[i]) ans[i] = a[i];
        else p.pb(i);
    }

    if (p.size() == 1) {
        set<int> s;
        fto(i, 1, n) s.insert(i);
        fto(i, 1, n) s.erase(a[i]);
        ans[p[0]] = *s.begin();
    } else {
        ans[p[0]] = a[p[0]];
        ans[p[1]] = b[p[1]];
        if (!Check()) {
            ans[p[0]] = b[p[0]];
            ans[p[1]] = a[p[1]];
        }
    }


    fto(i, 1, n) printf("%d ", ans[i]);


    return 0;
}