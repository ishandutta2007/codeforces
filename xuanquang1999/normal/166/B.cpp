#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<double, int> pdi;

#define debug(a) cout << #a << ": " << a << endl
#define debuga1(a, l, r) fto(i, l, r) cout << a[i] << " "; cout << endl
#define fdto(i, r, l) for(int i = (r); i >= (l); --i)
#define fto(i, l, r) for(int i = (l); i <= (r); ++i)
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
    bool operator < (pt p) {return make_tuple(y, x) < make_tuple(p.y, p.x);}
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (ll k) {return {x*k, y*k};}
    pt operator / (ll k) {return {x/k, y/k};}
    ll operator * (pt p) {return x*p.y - y*p.x;}
    ll operator | (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream& is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream& os, pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

ll orient(pt a, pt b, pt c) {return (b-a)*(c-a);}

bool onLeft(pt a, pt p) {
    return p*a > 0;
}

bool crossesRay(pt a, pt p, pt q) {
    return (onLeft(a, p) - onLeft(a, q))*orient(a, p, q) > 0;
}

bool onSegment(pt a, pt b, pt p) {
    return (orient(a, b, p) == 0 && ((a-p)|(b-p)) <= 0);
}

bool isIn(vector<pt> &po, pt a) {
    if (onSegment(po[0], po[1], a) || onSegment(po[0], po.back(), a))
        return false;
    int lo = 1, hi = sz(po)-2, res = -1;
    while (lo <= hi) {
        int mid = (lo+hi)/2;
        if (orient(po[0], po[mid], a) > 0) {
            res = mid;
            lo = mid+1;
        } else hi = mid-1;
    }

    if (res == -1)
        return false;
    pt p = po[res], q = po[res+1];
    return !onSegment(p, q, a) && crossesRay(a-po[0], p-po[0], q-po[0]);
}

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    int n;
    cin >> n;

    vector<pt> a(n);
    fto(i, 0, n-1)
        cin >> a[i];

    reverse(a.begin(), a.end());
    int ind = min_element(a.begin(), a.end()) - a.begin();

    vector<pt> po(n);
    fto(i, 0, n-1)
        po[i] = a[(i+ind)%n];

    bool ans = true;
    int q;
    cin >> q;
    fto(i, 0, q-1) {
        pt p; cin >> p;
        if (!isIn(po, p))
            ans = false;
    }

    puts((ans) ? "YES" : "NO");

    return 0;
}