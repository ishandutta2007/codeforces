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

struct pos{
    int a, b, i;
    bool inline operator < (const pos &o) const {
        return (a > o.a || (a == o.a && b > o.b));
    }
};

int n;
pos p[maxN];
vector<int> ans;

void add(set<ii> &s, int i) {
    if (i >= 1 && i <= n) {
        s.insert(mp(p[i].b, p[i].i));
    }
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &p[i].a);
    fto(i, 1, n) scanf("%d", &p[i].b);
    fto(i, 1, n) p[i].i = i;

    sort(p+1, p+n+1);

//    fto(i, 1, n) printf("%d %d %d\n", p[i].a, p[i].b, p[i].i);

    set<ii> s;
    fto(i, 1, n/2+1) {
        add(s, 2*i-2);
        add(s, 2*i-1);
        ans.pb(s.rbegin()->ss);
        s.erase(s.find(*s.rbegin()));
    }

    printf("%d\n", sz(ans));
    forit(it, ans) printf("%d ", *it);

    return 0;
}