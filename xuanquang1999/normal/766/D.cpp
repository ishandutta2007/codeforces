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

struct UFDS {
private:
    vector<int> pset, opposite;
public:
    UFDS(int n) {
        opposite.assign(n, -1);
        pset.resize(n);
        iota(pset.begin(), pset.end(), 0);
    }
    int findSet(int i) {
        return (pset[i] == i) ? i : pset[i] = findSet(pset[i]);
    }
    int findOpposite(int i) {
        int x = findSet(i);
        if (opposite[x] == -1) return -1;
        return opposite[x] = findSet(opposite[x]);
    }
    bool makeUnion(int i, int j) {
        int x = findSet(i), y = findSet(j);
        int X = findOpposite(i), Y = findOpposite(j);
        if (x == Y) return false;

        pset[y] = x;
        if (X != -1 && Y != -1) pset[min(X, Y)] = max(X, Y);

        opposite[x] = max(X, Y);

        return true;
    }
    bool makeOpposite(int i, int j) {
        int x = findSet(i), y = findSet(j);
        int X = findOpposite(i), Y = findOpposite(j);
        if (x == y) return false;

        if (X != -1) pset[X] = y;
        if (Y != -1) pset[Y] = x;

        opposite[x] = y;
        opposite[y] = x;

        return true;
    }
    int query(int i, int j) {
        int x = findSet(i), y = findSet(j);
        int X = findOpposite(i), Y = findOpposite(j);
        if (x == y || (X == Y && X != -1)) return 1;
        if (x == Y || y == X) return 2;
        return 3;
    }
};

int n, m, q;
map<string, int> dict;

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);
    cin >> n >> m >> q;
    for(int i = 0; i < n; ++i) {
        string s;
        cin >> s;
        dict[s] = i;
    }

    UFDS dsu(n);
    for(int i = 0; i < m; ++i) {
        int type;
        string s, t;
        cin >> type >> s >> t;

        bool result;
        if (type == 1) result = dsu.makeUnion(dict[s], dict[t]);
        else result = dsu.makeOpposite(dict[s], dict[t]);

        puts((result) ? "YES" : "NO");
    }

    for(int i = 0; i < q; ++i) {
        string s, t;
        cin >> s >> t;
        printf("%d\n", dsu.query(dict[s], dict[t]));
    }

    return 0;
}