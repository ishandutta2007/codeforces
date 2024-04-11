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
#define maxN 10005
#define MOD 1000
#define oo 1000000000000000007LL
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

int n, q;
vector<int> t[4*maxN];
bitset<maxN> bs[4*maxN];

void addQuery(int id, int l, int r, int i, int j, int x) {
    if (r < i || l > j) return;
    if (i <= l && r <= j) {
        t[id].pb(x);
        return;
    }
    int m = (l+r)/2;
    addQuery(2*id, l, m, i, j, x); addQuery(2*id+1, m+1, r, i, j, x);
}

void execute(int id, int l, int r) {
    if (l < r) {
        int m = (l+r)/2;
        execute(2*id, l, m);
        execute(2*id+1, m+1, r);
        bs[id] = bs[2*id] | bs[2*id+1];
    } else bs[id].set(0);
    for(int x: t[id])
        bs[id] |= bs[id]<<x;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d%d", &n, &q);
    fto(i, 1, q) {
        int l, r, x;
        scanf("%d%d%d", &l, &r, &x);
        addQuery(1, 1, n, l, r, x);
    }

    execute(1, 1, n);

    vector<int> ans;
    fto(i, 1, n) {
        if (bs[1][i]) ans.pb(i);
    }
    printf("%d\n", sz(ans));
    for(int x: ans) printf("%d ", x);

    return 0;
}