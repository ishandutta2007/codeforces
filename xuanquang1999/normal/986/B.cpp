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
#define maxN 1000005
#define maxK 105
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

struct BIT {
private:
    vector<int> t;
public:
    BIT(int n) {t.assign(n+1, 0);}
    void update(int p, int x) {
        for(int i = p; i < t.size(); i += i&(-i)) t[i] += x;
    }
    int query(int p) {
        int res = 0;
        for(int i = p; i > 0; i -= i&(-i)) res += t[i];
        return res;
    }
};

int n, p[maxN];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    scanf("%d", &n);
    fto(i, 1, n) scanf("%d", &p[i]);

    ll cntInv = 0;
    BIT t(n);
    fdto(i, n, 1) {
        cntInv += t.query(p[i]);
        t.update(p[i], 1);
    }

    puts(((3*n)%2 == cntInv%2) ? "Petr" : "Um_nik");

    return 0;
}