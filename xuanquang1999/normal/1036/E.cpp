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
    bool inline operator == (const pt &p) const {
        return (x == p.x && y == p.y);
    }
    bool inline operator < (const pt &p) const {
        return (x == p.x) ? (y < p.y) : (x < p.x);
    }
    pt operator + (pt p) {return {x + p.x, y + p.y};}
    pt operator - (pt p) {return {x - p.x, y - p.y};}
    pt operator * (ll k) {return {x * k, y * k};}
    pt operator / (ll k) {return {x / k, y / k};}
    ll operator * (pt p) {return x*p.y - y*p.x;}
    ll operator % (pt p) {return x*p.x + y*p.y;}
    friend istream& operator >> (istream &is, pt &p) {
        is >> p.x >> p.y;
        return is;
    }
    friend ostream& operator << (ostream &os, const pt &p) {
        os << "(" << p.x << ", " << p.y << ")";
        return os;
    }
};

ll orient(pt a, pt b, pt c) {
    return (b-a)*(c-a);
}

bool onSegment(pt a, pt b, pt p) {
    return (orient(a, b, p) == 0 && (a-p)%(b-p) <= 0);
}

int sign(ll x) {
    return (x > 0) - (x < 0);
}

bool properInter(pt a, pt b, pt c, pt d, pt &out) {
    ll oa = orient(c, d, a), ob = orient(c, d, b);
    ll oc = orient(a, b, c), od = orient(a, b, d);
    if (sign(oa)*sign(ob) < 0 && sign(oc)*sign(od) < 0) {
        pt p = a*ob - b*oa;
        ll q = ob - oa;
        if (abs(p.x)%abs(q) != 0 || abs(p.y)%abs(q) != 0)
            return false;
        out = p/q;
        return true;
    }
    return false;
}

vector<pt> inter(pt a, pt b, pt c, pt d) {
    pt out;
    if (properInter(a, b, c, d, out))
        return {out};
    vector<pt> res;
    if (onSegment(c, d, a)) res.pb(a);
    if (onSegment(c, d, b)) res.pb(b);
    if (onSegment(a, b, c)) res.pb(c);
    if (onSegment(a, b, d)) res.pb(d);
    return res;
}

int GCD(int a, int b) {
    return (b == 0) ? a : GCD(b, a%b);
}

const int MAXN = 1e3 + 5;

int n;
pt l[MAXN][2];

int main () {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
//        fr*eopen("output.txt", "w", stdout);
    #endif // ONLINE_JUDGE

    cin >> n;
    fto(i, 0, n-1)
        fto(j, 0, 1) cin >> l[i][j];

    ll ans = 0;
    fto(i, 0, n-1) {
        pt p = l[i][1] - l[i][0];
        int x = abs(p.x), y = abs(p.y);
//        debug(i);
        int d = GCD(x, y);
//        printf("%d %d %d %d\n", i, x, y, d);
        if (d == 0) ans += max(x, y) + 1;
        else ans += d+1;
    }

//    debug(ans);

    vector<pt> p;
    fto(i, 0, n-1) {
        fto(j, i+1, n-1) {
            vector<pt> out = inter(l[i][0], l[i][1], l[j][0], l[j][1]);
            if (!out.empty()) {
                p.pb(out[0]);
            }
        }
    }

    sort(p.begin(), p.end());
//    for(pt q: p) cout << q << endl;
    int i = 0;
    fto(j, 1, sz(p)) {
        if (j == sz(p) || !(p[i] == p[j])) {
            int k = j-i;
//            debug(k);
            int x = 0;
            while (true) {
                int cnt = x*(x-1)/2;
                if (cnt == k) {
                    ans -= x-1;
                    break;
                }
                assert(cnt <= k);
                ++x;
            }
            i = j;
        }
    }

    cout << ans;


    return 0;
}