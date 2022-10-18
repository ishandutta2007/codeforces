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
#define left Left
#define right Right

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
    bool operator < (pt p) {return make_tuple(x, y) < make_tuple(p.x, p.y);}
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (ll k) {return {x * k, y * k};}
    pt operator / (ll k) {return {x / k, y / k};}
    ll operator * (pt p) {return x*p.y - y*p.x;}
    ll operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, pt &p) {
        os << p.x << " " << p.y;
        return os;
    }
};

ll orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

vector<pt> readMinRotation() {
    int n;
    cin >> n;

    vector<pt> po(n);
    fto(i, 0, n-1) cin >> po[i];

    int p = min_element(po.begin(), po.end()) - po.begin();

    vector<pt> res(n);
    fto(i, 0, n-1) res[i] = po[(p+i)%n];
    return res;
}

void add(vector<pt> &po, pt p) {
    int n = sz(po);
    if (n > 1 && orient(po[n-2], po[n-1], p) == 0)
        po.pop_back();
    po.pb(p);
}

vector<pt> combine(vector<pt> a, vector<pt> b) {
    int i = 0, j = 0, n = sz(a), m = sz(b);
    vector<pt> res;

    while (i < n && j < m) {
        add(res, a[i] + b[j]);
        pt v = a[(i+1)%n] - a[i], w = b[(j+1)%m] - b[j];
        if (v*w > 0) ++i;
        else ++j;
    }
    while (i < n) add(res, a[i++] + b[0]);
    while (j < m) add(res, a[0] + b[j++]);

    int k = sz(res);
    if (orient(res[k-2], res[k-1], res[0]) == 0)
        res.pop_back();
    return res;
}

int q;
vector<pt> po[3];

bool onLeft(pt a, pt p) {
    return (a*p >= 0);
}

bool crossesRay(pt a, pt p, pt q) {
    return (onLeft(a, q) - onLeft(a, p))*orient(a, p, q) > 0;
}

bool onSegment(pt a, pt b, pt p) {
    return (orient(a, b, p) == 0 && (a-p)%(b-p) <= 0);
}

bool isIn(vector<pt> &po, pt a) {
    if (onSegment(po[0], po[1], a))
        return true;

    int lo = 1, hi = sz(po)-2, res = -1;
    while (lo <= hi) {
        int mid = (lo + hi)/2;
        if (orient(po[0], po[mid], a) > 0) {
            res = mid;
            lo = mid+1;
        } else hi = mid-1;
    }

    if (res == -1)
        return false;
    return (onSegment(po[res], po[res+1], a) || crossesRay(a-po[0], po[res]-po[0], po[res+1]-po[0]));
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    ios::sync_with_stdio(false);

    fto(i, 0, 2) po[i] = readMinRotation();
    fto(i, 1, 2) po[i] = combine(po[i-1], po[i]);

    cin >> q;
    fto(i, 1, q) {
        pt p; cin >> p;
        p = p*3;
        cout << (isIn(po[2], p) ? "YES" : "NO") << endl;
    }

    return 0;
}