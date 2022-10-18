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
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (ll k) {return {x*k, y*k};}
    pt operator / (ll k) {return {x/k, y/k};}
    ll operator * (pt p) {return x*p.y - y*p.x;}
    ll operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, const pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

bool half(pt a, pt p) {return p.y >= a.y;}

ll orient(pt a, pt b, pt c) {return (b-a)*(c-a);}

bool crossesRay(pt a, pt p, pt q) {
    return (half(a, q) - half(a, p)) * orient(a, p, q) > 0;
}

bool in(vector<pt> po, pt a) {
    int numCrossing = 0, n = sz(po);
    fto(i, 0, n-1)
        numCrossing += crossesRay(a, po[i], po[(i+1)%n]);
    return numCrossing&1;
}

const int MAXN = 1e5 + 5;
int n, q;
vector<pt> po;
pt a;

ll C2(ll x) {return x*(x-1)/2;}
ll C3(ll x) {return x*(x-1)*(x-2)/6;}

ll Solve() {
    if (!in(po, a))
        return 0;
    ll ans = C3(n);
    int j = 1;
    fto(i, 0, n-1) {
        while (orient(a, po[i], po[j%n]) > 0)
            ++j;
//        printf("%d %d\n", i, j);
        ans -= C2(j-i-1);
    }
    return ans;
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    po.resize(n);
    fto(i, 0, n-1) cin >> po[i];
    reverse(po.begin(), po.end());

    cin >> q;
    fto(i, 1, q) {
        cin >> a;
        cout << Solve() << endl;
    }

    return 0;
}